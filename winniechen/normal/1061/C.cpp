#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define mod 1000000007
ll fac[N],inv[N],n,f[N];int a[N];vector<int >v[N*10];
// ll q_pow(ll x,int n){ll ret=1;for(;n;n>>=1,x=x*x%mod)if(n&1)ret=ret*x%mod;return ret;}
// ll C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=1000000;i++)for(int j=i;j<=1000000;j+=i)v[j].push_back(i);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	// for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;inv[n]=q_pow(fac[n],mod-2);
	// for(int i=n;i;i--)inv[i-1]=inv[i]*i%mod;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		int lim=v[a[i]].size();
		for(int j=lim-1;~j;j--)
		{
			int x=v[a[i]][j];if(x>i)continue;
			(f[x]+=f[x-1])%=mod;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)(ans+=f[i])%=mod;
	printf("%lld\n",ans);
}