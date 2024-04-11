#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=200050;
const int M=2*N;
const int L=20;
vector<pair<int,int>> G[N],E[M];
void AddEdge(int u, int v, int w){ E[u].pb({v,w}),E[v].pb({u,w});}
int tot,n,q,sz[M],was[M],idx[M][L],lvl[M];ll dep[M][L];
void Bin(int u, int p)
{
	int last=u;
	vector<pair<int,int>> work;
	for(auto e:G[u]) if(e.first!=p) work.pb(e);
	for(int i=0;i<work.size();i++)
	{
		auto e=work[i];
		AddEdge(last,e.first,e.second);
		if(work.size()-i>2)
		{
			AddEdge(last,++tot,0);
			last=tot;
		}
	}
	for(auto e:work) Bin(e.first,u);
}
void SZ(int u, int p){ sz[u]=1;for(auto e:E[u]) if(e.first!=p && !was[e.first]) SZ(e.first,u),sz[u]+=sz[e.first];}
int Find(int u, int p, int n){ for(auto e:E[u]) if(e.first!=p && !was[e.first] && sz[e.first]*2>n) return Find(e.first,u,n);return u;}
int Find(int u){ SZ(u,0);return Find(u,0,sz[u]);}
void Build(int u, int p, int id, ll d, int l){ idx[u][l]=id;dep[u][l]=d;for(auto e:E[u]) if(e.first!=p && !was[e.first]) Build(e.first,u,id,d+e.second,l);}
void Decompose(int u, int d)
{
	was[u=Find(u)]=1;lvl[u]=d;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int w=E[u][i].second;
		if(!was[v]) Build(v,u,i,w,d);
	}
	for(auto e:E[u]) if(!was[e.first]) Decompose(e.first,d+1);
}
const int H=N*3*L;
int go[H][3],cnt[H],tsz,root[N];ll sum[H];
void Set(int p, int &c, int u, int l, int f)
{
	c=++tsz;cnt[c]=cnt[p]+f;sum[c]=sum[p]+(dep[u][l]-dep[u][l-1])*f;
	for(int i=0;i<3;i++) go[c][i]=go[p][i];
	if(lvl[u]==l) return;
	Set(go[p][idx[u][l]],go[c][idx[u][l]],u,l+1,f);
}
ll Get(int c, int u, int l)
{
	ll ans=sum[c]+(dep[u][l]-dep[u][l-1])*cnt[c];
	if(lvl[u]==l) return ans;
	return ans+Get(go[c][idx[u][l]],u,l+1);
}
int a[N];
int main()
{
	scanf("%i %i",&n,&q);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	for(int i=2,u,v,w;i<=n;i++) scanf("%i %i %i",&u,&v,&w),G[u].pb({v,w}),G[v].pb({u,w});
	tot=n;Bin(1,0);Decompose(1,1);
	for(int i=1;i<=n;i++) Set(root[i-1],root[i],a[i],1,1);
	for(ll last=0;q--;)
	{
		int t,l,r,v,x;
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %i",&l,&r,&v);
			l^=last;r^=last;v^=last;
			last=Get(root[r],v,1)-Get(root[l-1],v,1);
			printf("%lld\n",last);
		}
		else
		{
			scanf("%i",&x);
			x^=last;
			Set(root[x],root[x],a[x],1,-1);
			swap(a[x],a[x+1]);
			Set(root[x],root[x],a[x],1,1);
		}
		last%=1<<30;
	}
	return 0;
}