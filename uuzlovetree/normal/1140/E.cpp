#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
#define maxn 200005
const ll mod = 998244353;
ll f[maxn][2],g[maxn][2];
ll fastpow(ll a,ll p)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1; 
	}
	return ans;
}
ll work(ll *a,int n,ll k)
{
	for(int i=2;i<=n;++i)if(a[i]==a[i-1]&&a[i]!=-1)return 0;
	int p=0;
	for(int i=1;i<=n;++i)if(a[i]!=-1)p++;
	if(!p)
	{
		return fastpow(k-1,n-1)*k%mod;
	}
	else if(p==1)
	{
		return fastpow(k-1,n-1);
	}
	else
	{
		if(p==n)return 1;
		if(k==1)return 0;
		ll res=1;
		int l,r;
		for(int i=1;i<=n;++i)
		{
			if(a[i]!=-1)
			{
				l=i+1;
				break;
			}
			res=res*(k-1)%mod;
		}
		for(int i=n;i;--i)
		{
			if(a[i]!=-1)
			{
				r=i-1;
				break;
			}
			res=res*(k-1)%mod;
		}
		ll t=0;
		ll last=a[l-1];
		for(int i=l;i<=r+1;++i)
		{
			if(a[i]!=-1)
			{
				if(!t)
				{
					last=a[i];
					continue;
				}
				if(a[i]!=last)res=(res*f[t][0])%mod;
				else res=(res*g[t][0])%mod;
				t=0;last=a[i];
			}
			else t++;
		}
		return res;
	}
}
int n,cnt1,cnt2;
ll k;
ll a[maxn],b[maxn],c[maxn];
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d",&a[i]);
	}
	f[1][0]=k-2;f[1][1]=1;
	g[1][0]=k-1;g[1][1]=0;
	for(int i=2;i<=n;++i)
	{
		f[i][0]=(f[i-1][0]*(k-2)%mod+f[i-1][1]*(k-1)%mod)%mod;
		f[i][1]=f[i-1][0];
		g[i][0]=(g[i-1][0]*(k-2)%mod+g[i-1][1]*(k-1)%mod)%mod;
		g[i][1]=g[i-1][0];
	}
	for(int i=1;i<=n;i+=2)b[++cnt1]=a[i];
	for(int i=2;i<=n;i+=2)c[++cnt2]=a[i];
	ll ans=work(b,cnt1,k);
	ans=ans*work(c,cnt2,k)%mod;
	printf("%I64d\n",ans);
	return 0;
}