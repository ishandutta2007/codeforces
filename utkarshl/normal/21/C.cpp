#include"stdio.h"
#include"iostream"
int main()
{
  int A[100000],N;
  int B[100000+1];
  scanf("%d",&N);
  while(N)
  {
    int sum=0;
    for(int x=0;x<N;x++)
    {
      scanf("%d",&A[x]);
      sum+=A[x];
    }
    if(sum%3!=0 || N<3)
    {
      printf("0\n");break;
    }
    int s1=sum/3;
    B[0]=0;
    sum=0;
    for(int x=0;x<N;x++)
    {
      sum+=A[x];
      if(sum==s1)B[x+1]=B[x]+1;
      else B[x+1]=B[x];
    }
    sum=A[N-1];
    long long int soln=0;
//     if(s1==0)soln=B[N];
    for(int x=N-2;x>0;x--)
    {
      if(sum==s1)soln+=B[x];
      sum+=A[x];
    }
//     soln=10000000000000L;
    std::cout<<soln<<"\n";
    break;
    N=0;
  }
}