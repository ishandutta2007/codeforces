#include<bits/stdc++.h>
#define maxn 200005 
#define ll long long
using namespace std;
const int mod = 998244353;
int n,m;
int fac[maxn],inv[maxn];
int fastpow(int a,int p)
{
	int ans=1;
	for(;p;p>>=1,a=1ll*a*a%mod)if(p&1)ans=1ll*ans*a%mod;
	return ans;
}
int C(int x,int y)
{
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
	fac[0]=1;inv[0]=1;
	for(int i=1;i<=200000;++i)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=200000;++i)inv[i]=fastpow(fac[i],mod-2);
	scanf("%d%d",&n,&m);
	if(n==2)
	{
		puts("0");
	}
	else
	{
		int ans=0;
		for(int i=n-1;i<=m;++i)ans=(ans+C(i-1,n-2))%mod;
		ans=1ll*ans*(n-2)%mod*fastpow(2,n-3)%mod;
		printf("%d\n",ans);
	}
}