#include <stdio.h>
int k[100000];
int dp[100000];
int main()
{
int n,i;
scanf("%i",&n);
for(i=0;i<n;i++) scanf("%i",&k[i]);
dp[0]=1;
int sol=1;
for(i=1;i<n;i++)
{
if(k[i]>=k[i-1]) dp[i]=dp[i-1]+1;
else dp[i]=1;
if(sol<dp[i]) sol=dp[i];
}
printf("%i\n",sol);
return 0;
}