#include<bits/stdc++.h>
#define maxn 2005
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
int n,a,b;
int sum[maxn][maxn];
vector<int> ga[maxn],gb[maxn];
int ax[maxn],by[maxn],xa[maxn],yb[maxn];
int amx[maxn],amn[maxn],bmx[maxn],bmn[maxn];
int sza[maxn],szb[maxn];
vector<pii> av[maxn],bv[maxn];
void dfs1(int u)
{
	sza[u]=1;
	if(xa[u])amn[u]=amx[u]=xa[u];
	else amn[u]=2001,amx[u]=0;
	for(int v:ga[u])
	{
		dfs1(v);
		amn[u]=min(amn[u],amn[v]);
		amx[u]=max(amx[u],amx[v]);
		sza[u]+=sza[v];
	}
	av[amx[u]].push_back(mpr(amn[u],(u==1)?sza[u]-1:sza[u]));
}
void dfs2(int u)
{
	szb[u]=1;
	if(yb[u])bmn[u]=bmx[u]=yb[u];
	else bmn[u]=2001,bmx[u]=0;
	for(int v:gb[u])
	{
		dfs2(v);
		bmn[u]=min(bmn[u],bmn[v]);
		bmx[u]=max(bmx[u],bmx[v]);
		szb[u]+=szb[v];
	}
	bv[bmx[u]].push_back(mpr(bmn[u],(u==1)?szb[u]-1:szb[u]));
}
int dp[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%d",&a);
	for(int x,i=2;i<=a;++i)
	{
		scanf("%d",&x);
		ga[x].push_back(i); 
	}
	for(int i=1;i<=n;++i)scanf("%d",&ax[i]),xa[ax[i]]=i;
	scanf("%d",&b);
	for(int x,i=2;i<=b;++i)
	{
		scanf("%d",&x);
		gb[x].push_back(i);
	}
	for(int i=1;i<=n;++i)scanf("%d",&by[i]),yb[by[i]]=i;
	dfs1(1);dfs2(1);
	for(int i=1;i<=n;++i)
	{
		for(pii u:av[i])
		{
			int j=u.first,w=u.second;
			dp[i]=max(dp[i],dp[j-1]+w);
		}
		for(pii u:bv[i])
		{
			int j=u.first,w=u.second;
			dp[i]=max(dp[i],dp[j-1]+w);
		}
	}
	printf("%d\n",dp[n]);
}