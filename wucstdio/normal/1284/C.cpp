#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll MOD,fact[250005];
int main()
{
	scanf("%d%lld",&n,&MOD);
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%MOD;
	ll ans=0;
	for(int i=1;i<=n;i++)
	  ans=(ans+fact[i]*fact[n-i]%MOD*(n-i+1)%MOD*(n-i+1))%MOD;
	printf("%lld\n",ans);
	return 0;
}