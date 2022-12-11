#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mpr(a,b) make_pair(a,b)
#define maxn 300005
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
const ll mod = 998244353;
int n,q;
vector<int> g[maxn];
int f[maxn],top[maxn];
int lpos[maxn],rpos[maxn],cnt,sz[maxn];
ll addt[maxn];
const int B = 100;
void dfs(int u,int fa)
{
	if(g[fa].size()>B)top[u]=u;
	else top[u]=top[fa];
	f[u]=fa;
	lpos[u]=++cnt; 
	sz[u]=1;
	for(int v:g[u])if(v!=fa)
	{
		dfs(v,u);
		sz[u]+=sz[v];
	}
	rpos[u]=cnt;
}
ll val[maxn<<2];
void add(int rt,int l,int r,int ql,int qr,ll v)
{
	if(ql>qr)return;
	if(ql<=l&&r<=qr)
	{
		val[rt]=(val[rt]+v)%mod;
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)add(rt<<1,l,mid,ql,qr,v);
	if(qr>mid)add(rt<<1|1,mid+1,r,ql,qr,v);
}
ll query(int rt,int l,int r,int pos)
{
	ll ans=val[rt];
	int mid=(l+r)>>1;
	if(l==r)return ans;
	if(pos<=mid)ans=(ans+query(rt<<1,l,mid,pos))%mod;
	else ans=(ans+query(rt<<1|1,mid+1,r,pos))%mod;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int x,y,i=1;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	dfs(1,0);
	while(q--)
	{
		int opt,u,d;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&u,&d);
			add(1,1,n,1,lpos[u]-1,1ll*sz[u]*inv(n,mod)%mod*d%mod);
			add(1,1,n,rpos[u]+1,n,1ll*sz[u]*inv(n,mod)%mod*d%mod);
			if(g[u].size()>B)addt[u]=(addt[u]+d)%mod;
			else
			{
				for(int v:g[u])if(v!=f[u])
				{
					add(1,1,n,lpos[v],rpos[v],1ll*(n-sz[v])*inv(n,mod)%mod*d%mod);
				}
				add(1,1,n,lpos[u],lpos[u],d);
			}
		}
		else
		{
			scanf("%d",&u);
			ll ans=(addt[u]+query(1,1,n,lpos[u]))%mod; 
			while(top[u])
			{
				u=top[u];
				ans=(ans+1ll*(n-sz[u])*inv(n,mod)%mod*addt[f[u]]%mod)%mod;
				u=f[u];
			}
			printf("%I64d\n",ans);
		}
	}
}