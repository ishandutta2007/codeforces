#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
bool ckmax(int &a, int b){ int c=a;a=max(a,b);return c!=a;}
bool ckmin(int &a, int b){ int c=a;a=min(a,b);return c!=a;}
bool ckmax(ll &a, ll b){ ll c=a;a=max(a,b);return c!=a;}
bool ckmin(ll &a, ll b){ ll c=a;a=min(a,b);return c!=a;}
const int N=200050;
const int inf=1e9+7;
const int L=18;
vector<int> E[N];
int par[N][L],dep[N],lid[N],rid[N],tid;
void DFS(int u)
{
	lid[u]=++tid;
	for(int i=0;i<E[u].size();i++) DFS(E[u][i]);
	rid[u]=tid;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
const int M=2*N;
int ls[M],rs[M],rmq[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz;
	ckmin(rmq[c],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>se || ss>qe) return inf;
	if(qs<=ss && qe>=se) return rmq[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int up[N][L];
int ok[N];
void Process(int u)
{
	int i,v=u,sol=Get(root,1,N,lid[u],rid[u]);
	for(i=L-1;~i;i--) if(dep[par[v][i]]>=sol) v=par[v][i];
	if(sol>=dep[u]) ok[u]=0;
	else ok[u]=1;
	ok[u]+=ok[par[u][0]];
	up[u][0]=v;
	for(i=1;i<L;i++) up[u][i]=up[up[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++) Process(E[u][i]);
}
vector<int> vals[N];
void Insert(int x, int y)
{
	for(int i=x;i<N;i+=i&-i) vals[i].pb(y);
}
void Build()
{
	for(int i=0;i<N;i++) sort(vals[i].begin(),vals[i].end());
}
int Get(int x, int y1, int y2)
{
	int ret=0;
	//printf("%i\n",x);
	for(int i=x;i;i-=i&-i)
	{
		int a=lower_bound(vals[i].begin(),vals[i].end(),y1)-vals[i].begin();
		int b=upper_bound(vals[i].begin(),vals[i].end(),y2)-vals[i].begin();
		//printf("%i %i\n",a,b);
		ret+=b-a;
	}
	return ret;
}
bool Check(int x1, int x2, int y1, int y2){ return Get(x2,y1,y2)>Get(x1-1,y1,y2);}
int main()
{
	int n,m,q,i,j,u,v;
	for(i=0;i<M;i++) rmq[i]=inf;
	scanf("%i",&n);dep[1]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%i",&par[i][0]);E[par[i][0]].pb(i);
		for(j=1;j<L;j++) par[i][j]=par[par[i][j-1]][j-1];
		dep[i]=dep[par[i][0]]+1;
	}
	DFS(1);
	scanf("%i",&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		int lca=LCA(u,v);
		Set(root,1,N,lid[u],dep[lca]);
		Set(root,1,N,lid[v],dep[lca]);
		Insert(min(lid[v],lid[u]),max(lid[v],lid[u]));
	}
	Build();
	Process(1);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&u,&v);
		int lca=LCA(u,v);
		if(ok[u]+ok[v]-2*ok[lca]!=dep[u]+dep[v]-2*dep[lca])
		{
			printf("-1\n");
			continue;
		}
		int h=u,sol=0;
		for(i=L-1;~i;i--)
		{
			if(dep[up[h][i]]>dep[lca]) h=up[h][i],sol+=1<<i;
		}
		int k=h;
		h=v;
		//printf("%i %i %i\n",h,k,sol);
		for(i=L-1;~i;i--)
		{
			if(dep[up[h][i]]>dep[lca]) h=up[h][i],sol+=1<<i;
		}
		if(u==lca)
		{
			sol++;
			printf("%i\n",sol);
		}
		else if(v==lca)
		{
			sol++;
			printf("%i\n",sol);
		}
		else
		{
			int x1=min(lid[h],lid[k]),x2=min(rid[h],rid[k]);
			int y1=max(lid[h],lid[k]),y2=max(rid[h],rid[k]);
			if(Check(x1,x2,y1,y2)) sol++;
			else sol+=2;
			printf("%i\n",sol);
		}
	}
	return 0;
}