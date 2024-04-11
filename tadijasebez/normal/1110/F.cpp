#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=500050;
const int M=N*5;
const ll inf=7e18;
int ls[M],rs[M],tsz,root,lid[N],rid[N];
ll mn[M],lzy[M],dep[N];
void Build(int &c, int ss, int se)
{
	c=++tsz;lzy[c]=0;
	if(ss==se){ mn[c]=lid[ss]==rid[ss]?dep[ss]:inf;return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	mn[c]=min(mn[ls[c]],mn[rs[c]]);
	//printf("%i (%i %i) %lld\n",c,ss,se,mn[c]);
}
void Add(int &c, int ss, int se, int qs, int qe, ll f)
{
	if(qs>qe || qs>se || ss>qe) return;
	//c=++tsz;lzy[c]=lzy[p];ls[c]=ls[p];rs[c]=rs[p];mn[c]=mn[p];
	if(qs<=ss && qe>=se){ mn[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]])+lzy[c];
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return inf;
	if(qs<=ss && qe>=se) return mn[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}
vector<pair<int,int>> E[N];
int par[N],w[N];
void DFS(int u, int p)
{
	lid[u]=rid[u]=u;
	par[u]=p;
	//printf("%i dep:%lld par:%i\n",u,dep[u],par[u]);
	for(auto e:E[u]) if(e.first!=p)
	{
		dep[e.first]=dep[u]+e.second;
		DFS(e.first,u);
		rid[u]=max(rid[u],rid[e.first]);
	}
}
int n;
ll ans[N];
vector<pair<int,pair<int,int>>> Qs[N];
void Build(int u, int p)
{
	Add(root,1,n,lid[u],rid[u],-2*w[u]);
	//printf("Dec: %i %i za %i\n",lid[u],rid[u],2*w[u]);
	for(auto Qu:Qs[u])
	{
		int id=Qu.first;
		int l=Qu.second.first;
		int r=Qu.second.second;
		ans[id]=Get(root,1,n,l,r)+dep[u];
	}
	for(auto e:E[u]) if(e.first!=p) Build(e.first,u);
	Add(root,1,n,lid[u],rid[u],2*w[u]);
}
int main()
{
	int q,i;
	scanf("%i %i",&n,&q);
	for(i=2;i<=n;i++) scanf("%i %i",&par[i],&w[i]),E[par[i]].pb(mp(i,w[i]));
	DFS(1,0);
	Build(root,1,n);
	//Build(1,0);
	for(int i=1;i<=q;i++)
	{
		int u,l,r;
		scanf("%i %i %i",&u,&l,&r);
		Qs[u].pb(mp(i,mp(l,r)));
		//ll ans=Get(root[u],1,n,l,r)+dep[u];
		//printf("%lld\n",ans);
	}
	Build(1,0);
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}