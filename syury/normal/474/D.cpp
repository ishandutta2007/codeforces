#include <stdio.h>

const int M = 1000000007;

int t,k,a,b;
int ans[100007];
long long int anssum[100007];

int main(){
  scanf("%d%d",&t,&k);
  for(int i=0;i<k;i++){ans[i]=1;if (i==0){anssum[i]=1;}else{anssum[i]=anssum[i-1]+ans[i];}}
  for (int i=k;i<100007;i++){ans[i] = ans[i-1]+ans[i-k];ans[i]=ans[i]%M;anssum[i]=anssum[i-1]+ans[i];}
  for (int i=0;i<t;i++){
    scanf("%d%d",&a,&b);
    printf("%I64d\n",(anssum[b]-anssum[a-1])%M);
  }
  return 0;
}