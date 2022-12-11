#include<bits/stdc++.h>
#define maxn 400005
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mpr(a,b) make_pair(a,b)
using namespace std;
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll fastpow(ll a,ll p,ll mod)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
ll inv(ll x,ll mod){return fastpow(x,mod-2,mod);}
int T,n; 
int a[maxn];
int g,s,b;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		g=s=b=0;
		g=1;
		int i,t=0;
		for(i=2;i<=n/2+1;++i)
		{
			if(a[i]==a[i-1])g++;
			else break;
		}
		for(;i<=n/2+1;++i)
		{
			if(a[i]==a[i-1])t++;
			else
			{
				s+=t;t=0;
				if(s<=g)t++;
				else break;
			}
		}
		for(;i<=n/2+1;++i)
		{
			if(a[i]==a[i-1])t++;
			else
			{
				b+=t;t=0;
				if(b<=g)t++;
				else break;
			}
		}
		while(1)
		{
			i++;
			t=1;
			for(;i<=n;++i)
			{
				if(a[i]==a[i-1])t++;
				else break;
			}
			if(i-1>n/2)break;
			else b+=t;
		}
		bool yes=1;
		if(g>=s||g>=b)puts("0 0 0");
		else printf("%d %d %d\n",g,s,b);
	}
}