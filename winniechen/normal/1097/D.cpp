#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 60
#define K 10005
#define mod 1000000007 
#define ll long long
ll P=1,Q;
ll a[N],b[N];
int cnt;
ll qpow(ll x,ll n){ll ret=1;for(;n;n>>=1,x=x*x%mod)if(n&1)ret=ret*x%mod;return ret;}
struct WC
{
	ll x,y;
	WC operator + (const WC &a) const
	{
		WC re;
		re.x=a.x*y%mod+a.y*x%mod;
		re.y=a.y*y%mod;
		return re;
	}
	WC operator * (const WC &a) const 
	{
		WC re;
		re.x=a.x*x%mod;
		re.y=a.y*y%mod;
		return re;
	}
	WC operator * (ll b) const
	{
		WC re;
		(re.x=x*b)%=mod; re.y=y;
		return re;
	}
}f[K][N];
int main()
{
	ll n,k; cin >> n >> k ;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a[++cnt]=i; while(n%i==0) b[cnt]++,n/=i;
		}
	}
	if(n!=1) a[++cnt]=n,b[cnt]=1;
	WC Ans=(WC){1,1},Now=(WC){0,1};
	for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int l=0;l<=b[i];l++)
			{
				f[j][l]=(WC){0,1};
			}
		}
		f[0][b[i]]=(WC){1,1};
		for(int j=1;j<=k;j++)
		{
			for(int l=0;l<=b[i];l++)
			{
				for(int r=l;r<=b[i];r++)
				{
					f[j][l]=f[j][l]+(f[j-1][r]*(WC){1ll,r+1});
				}
			}
		}
		Now=(WC){0,1};
		for(int j=0;j<=b[i];j++) Now=Now+(f[k][j]*qpow(a[i],j));
		Ans=Ans*Now;
	}
	cout << Ans.x*qpow(Ans.y,mod-2)%mod << endl ;
	return 0;
}