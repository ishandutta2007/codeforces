#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n;
ll a[200005],b[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]*=1ll*i*(n-i+1);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)scanf("%I64d",&b[i]);
	sort(b+1,b+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]%=MOD;
		ans=(ans+a[i]*b[n-i+1])%MOD;
	}
	printf("%I64d\n",ans);
	return 0;
}