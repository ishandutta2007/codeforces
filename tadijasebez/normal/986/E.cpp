#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
const int mod=1e9+7;
const int N=100050;
const int H=2*N;
const int M=2*H;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int lid[N],rid[N],tid,dep[N],nod[N],par[N][17];
vector<int> E[N];
void DFS(int u, int p)
{
	par[u][0]=p;
	dep[u]=dep[p]+1;
	lid[u]=++tid;
	int i;
	for(i=1;i<17;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++) if(E[u][i]!=p) DFS(E[u][i],u);
	rid[u]=++tid;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=16;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=16;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int ls[M],rs[M],tsz,root,sum[M];
void Set(int &c, int ss, int se, int qi, int f)
{
	if(!c) c=++tsz;
	sum[c]+=f;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || qs>se || ss>qe) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
int Get(int u){ return Get(root,1,H,1,lid[u]);}
int Get(int u, int v)
{
	int lca=LCA(u,v);
	return Get(root,1,H,1,lid[u])+Get(root,1,H,1,lid[v])-Get(root,1,H,1,lid[lca])-Get(root,1,H,1,lid[par[lca][0]]);
}
struct Query
{
	int id,sz;
	Query(){}
	Query(int a, int b){ id=a,sz=b;}
	bool operator < (Query b) const { return sz<b.sz;}
};
vector<Query> Qs[H];
vector<Query> Us[H];
vector<int> Ps;
int a[N],cen[N],den[N],sol[N];
int Find(int x){ return lower_bound(Ps.begin(),Ps.end(),x)-Ps.begin()+1;}
int main()
{
	int n,i,u,v,j,x,k;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		x=a[i];
		for(j=2;j*j<=x;j++)
		{
			if(x%j) continue;
			Ps.pb(j);
			while(!(x%j)) x/=j;
		}
		if(x>1) Ps.pb(x);
	}
	sort(Ps.begin(),Ps.end());
	Ps.erase(unique(Ps.begin(),Ps.end()),Ps.end());
	for(i=1;i<=n;i++)
	{
		x=a[i];
		for(j=2;j*j<=x;j++)
		{
			if(x%j) continue;
			int cnt=0;
			while(!(x%j)) x/=j,cnt++,Us[Find(j)].pb(Query(i,cnt));
		}
		if(x>1) Us[Find(x)].pb(Query(i,1));
	}
	int q;
	scanf("%i",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i",&cen[i],&den[i],&x);
		for(j=2;j*j<=x;j++)
		{
			if(x%j) continue;
			int cnt=0;
			while(!(x%j)) x/=j,cnt++;
			if(Find(j)>Ps.size() || Ps[Find(j)-1]!=j) continue;
			Qs[Find(j)].pb(Query(i,cnt));
		}
		if(x>1 && Find(x)<=Ps.size() && Ps[Find(x)-1]==x) Qs[Find(x)].pb(Query(i,1));
		sol[i]=1;
	}
	for(k=1;k<=Ps.size();k++)
	{
		int p=Ps[k-1];
		//printf("->%i<-\n",p);
		j=0;
		for(i=1;i<=tsz;i++) ls[i]=rs[i]=sum[i]=0;
		root=tsz=0;
		sort(Qs[k].begin(),Qs[k].end());
		sort(Us[k].begin(),Us[k].end());
		//for(i=0;i<Qs[k].size();i++) printf("(%i %i) ",Qs[k][i].id,Qs[k][i].sz);printf("\n");
		//for(i=0;i<Us[k].size();i++) printf("(%i %i) ",Us[k][i].id,Us[k][i].sz);printf("\n");
		for(i=0;i<Qs[k].size();i++)
		{
			while(j<Us[k].size() && Us[k][j].sz<=Qs[k][i].sz)
			{
				Set(root,1,H,lid[Us[k][j].id],1);
				Set(root,1,H,rid[Us[k][j].id],-1);
				j++;
			}
			int g=Get(cen[Qs[k][i].id],den[Qs[k][i].id]);
			//printf("prime:%i query:%i get:%i\n",p,Qs[k][i].id,g);
			sol[Qs[k][i].id]=(ll)sol[Qs[k][i].id]*pow(p,g)%mod;
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}