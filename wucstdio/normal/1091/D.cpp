#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
const ll MOD=998244353;
ll n,down[1000005],ans;
int main()
{
	scanf("%I64d",&n);
	down[0]=1,ans=1;
	for(int i=1;i<=n;i++)
	  down[i]=down[i-1]*(n-i+1)%MOD,ans=ans*i%MOD;
	ans=ans*n%MOD;
	for(int i=1;i<=n-1;i++)
	  ans=ans-down[i]+MOD;
	printf("%I64d\n",ans%MOD);
	return 0;
}