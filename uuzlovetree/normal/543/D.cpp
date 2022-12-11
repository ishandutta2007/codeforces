#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
const ll mod = 1000000007;
int n;
vector<int> g[maxn];
ll f[maxn],ans[maxn];
ll fastpow(ll a,ll p)
{
	ll res=1;
	while(p)
	{
		if(p&1)res=res*a%mod;
		a=a*a%mod;p>>=1;
	}
	return res;
}
ll inv(ll x)
{
	return fastpow(x,mod-2);
}
void dfs(int u)
{
	f[u]=1;
	for(int i=0;i<g[u].size();++i)
	{
		int v=g[u][i];
		dfs(v);
		f[u]=f[u]*(1+f[v])%mod;
	}
}
void dfs2(int u,ll val)
{
	if(u==1)ans[u]=f[u];
	else ans[u]=f[u]*(val+1)%mod;
	int sz=g[u].size();
	vector<ll> pre(sz+1,0),suf(sz+1,0);
	pre[0]=1,suf[sz]=1;
	for(int i=1;i<=sz;++i)
	{
		int v=g[u][i-1];
		pre[i]=pre[i-1]*(1+f[v])%mod;
	}
	for(int i=sz-1;i>=0;--i)
	{
		int v=g[u][i];
		suf[i]=suf[i+1]*(1+f[v])%mod;
	}
	for(int i=0;i<sz;++i)
	{
		int v=g[u][i];
		dfs2(v,(val+1)*pre[i]%mod*suf[i+1]%mod);
	}
}
int main()
{
	scanf("%d",&n);
	for(int x,i=2;i<=n;++i)
	{
		scanf("%d",&x);
		g[x].push_back(i);
	}
	dfs(1);
	dfs2(1,0);
	for(int i=1;i<=n;++i)printf("%I64d ",ans[i]);
	return 0; 
}