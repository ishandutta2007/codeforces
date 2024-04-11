#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll a[300005],k,MOD;
int main()
{
	scanf("%d%I64d%I64d",&n,&MOD,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]=(a[i]*a[i]%MOD*a[i]%MOD*a[i]%MOD-k*a[i]%MOD+MOD)%MOD;
	}
	sort(a+1,a+n+1);
	ll len=0;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			ans+=len*(len-1)/2;
			len=1;
		}
		else len++;
	}
	ans+=len*(len-1)/2;
	printf("%I64d\n",ans);
	return 0;
}