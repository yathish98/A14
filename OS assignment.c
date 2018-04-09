#include<stdio.h> 
 
int main() 
{ 
  int student[1000],faculty[1000]; 
  int count,j,n,time,remain,flag=0,tq,wait=0,turnaround=0,arr[10],burst[10],rem[10];
  float avgwait,avgturn; 
  printf("Enter number of processes: "); 
  scanf("%d",&n); 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
  	printf("\nFor process P%d",count+1);
    printf("\nEnter Arrival Time:"); 
    scanf("%d",&arr[count]); 
    printf("\nEnter burst time:");
    scanf("%d",&burst[count]); 
    rem[count]=burst[count]; 
  } 
  printf("Enter Time Quantum:"); 
  scanf("%d",&tq); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rem[count]<=tq && rem[count]>0) 
    { 
      time+=rem[count]; 
      rem[count]=0; 
      flag=1; 
    } 
    else if(rem[count]>0) 
    { 
      rem[count]-=tq; 
      time+=tq; 
    } 
    if(rem[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P%d\t|\t%d\t|\t%d\n",count+1,time-arr[count],time-arr[count]-burst[count]); 
      wait+=time-arr[count]-burst[count]; 
      turnaround+=time-arr[count]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(arr[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  avgwait=wait*1.0/n;
  avgturn=turnaround*1.0/n;
  printf("\nAverage Waiting Time= %f\n",avgwait); 
  printf("Avg Turnaround Time = %f",avgturn); 
  return 0; 
}
