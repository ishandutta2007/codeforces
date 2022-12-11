#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
const ll mod = 1000000007;
ll n,k,l;
ll a[maxn];
ll m,p,q;
ll b[maxn],d;
ll c[maxn];
ll f[maxn],g[maxn],ans;
struct BIT
{
	ll a[maxn];
	void clear()
	{
		memset(a,0,sizeof(a));
	}
	void add(int x,ll v)
	{
		for(;x<=maxn-5;x+=x&(-x))a[x]=(a[x]+v+mod)%mod; 
	}
	ll get(int x)
	{
		ll ans=0;
		for(;x;x-=x&(-x))ans=(ans+a[x])%mod;
		return ans;
	}
}tr;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&l,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	d=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+d+1,a[i])-b;
	m=l/n;p=l%n;
	if(!p)m--,p+=n;
	q=max(0ll,m-k+1);
	q%=mod;
	int cnt=0;
	for(int i=1;i<=k-1;++i)
		for(int j=1;j<=n;++j)c[++cnt]=a[j];
	for(int i=1;i<=p;++i)c[++cnt]=a[i];
	for(int i=cnt-p+1;i<=cnt;++i)f[i]=1,tr.add(c[i],f[i]);
	for(int i=k-1;i;--i)
	{
		for(int j=1;j<=n;++j)
		{
			int pos=(i-1)*n+j;
			f[pos]=(tr.get(maxn-5)-tr.get(c[pos]-1)+mod)%mod;
		}
		for(int j=1;j<=n;++j)
		{
			int pos=(i-1)*n+j;
			if(pos+n<=cnt)tr.add(c[pos+n],-f[pos+n]);
			tr.add(c[pos],f[pos]);
		}
	}
	for(int i=max(cnt-p-m*n+1,1ll);i<=cnt;++i)ans=(ans+f[i])%mod;
	memset(c,0,sizeof(c));
	tr.clear();
	cnt=0;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)c[++cnt]=a[j];
	for(int i=cnt-n+1;i<=cnt;++i)g[i]=1,tr.add(c[i],g[i]);
	for(int i=k-1;i;--i)
	{
		for(int j=1;j<=n;++j)
		{
			int pos=(i-1)*n+j;
			g[pos]=(tr.get(maxn-5)-tr.get(c[pos]-1)+mod)%mod;
		}
		for(int j=1;j<=n;++j)
		{
			int pos=(i-1)*n+j;
			tr.add(c[pos+n],-g[pos+n]);
			tr.add(c[pos],g[pos]);
		}
	}
	ll tmp=0;
	for(int i=1;i<=min(m,k-1);++i)
	{
		for(int j=1;j<=n;++j)
		{
			int pos=(k-i)*n+j;
			tmp=(tmp+g[pos])%mod;
		}
		ans=(ans+tmp)%mod;
	}
	tmp=0;
	for(int i=1;i<=k;++i)
		for(int j=1;j<=n;++j)
		{
			int pos=(i-1)*n+j;
			tmp=(tmp+g[pos])%mod;
		}
	tmp=tmp*q%mod;
	ans=(ans+tmp)%mod;
	printf("%I64d\n",ans);
	return 0;
}