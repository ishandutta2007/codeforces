#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=100050;
const int M=2*N;
ll x[M],y[M];
int ls[M],rs[M],a[N],nod[N],clock,root;
void Build(int &c, int ss, int se)
{
	c=++clock;
	if(ss==se){ x[c]=a[nod[ss]];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	x[c]=x[ls[c]]+x[rs[c]];
}
void Propagate(int c, int ss, int se)
{
	if(y[c])
	{
		x[c]+=y[c]*(se-ss+1);
		if(ss!=se)
		{
			y[ls[c]]+=y[c];
			y[rs[c]]+=y[c];
		}
		y[c]=0;
	}
}
void Set(int c, int ss, int se, int qs, int qe, int val)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		y[c]+=val;
		Propagate(c,ss,se);
		return;
	}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	x[c]=x[ls[c]]+x[rs[c]];
}
ll Get(int c, int ss, int se, int qs, int qe)
{
	Propagate(c,ss,se);
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector<int> E[N];
int par[N][17],b[N],e[N],dep[N],time;
void DFS(int u, int p)
{
	b[u]=++time;
	nod[time]=u;
	dep[u]=dep[p]+1;
	par[u][0]=p;
	int i;
	for(i=1;i<17;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
	e[u]=time;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=16;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=16;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
bool InTree(int u, int v)
{
	return b[u]>=b[v] && b[u]<=e[v];
}
int Center(int u, int v, int h)
{
	int lca1=LCA(u,v);
	int lca2=LCA(u,h);
	int lca3=LCA(v,h);
	if(dep[lca1]>=dep[lca2] && dep[lca1]>=dep[lca3]) return lca1;
	if(dep[lca2]>=dep[lca1] && dep[lca2]>=dep[lca3]) return lca2;
	if(dep[lca3]>=dep[lca2] && dep[lca3]>=dep[lca1]) return lca3;
}
int main()
{
	int r,n,u,v,i,q,t,val;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	r=1;
	DFS(1,0);
	Build(root,1,n);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1) scanf("%i",&r);
		if(t==2)
		{
			scanf("%i %i %i",&u,&v,&val);
			int cen=Center(u,v,r);
			//printf("Center is %i\n",cen);
			if(cen==r) Set(root,1,n,1,n,val);
			else if(!InTree(r,cen)) Set(root,1,n,b[cen],e[cen],val);
			else
			{
				int h=r;
				for(i=16;~i;i--) if(dep[par[h][i]]>dep[cen]) h=par[h][i];
				Set(root,1,n,1,n,val);
				Set(root,1,n,b[h],e[h],-val);
			}
		}
		if(t==3)
		{
			scanf("%i",&u);
			if(r==u) printf("%lld\n",Get(root,1,n,1,n));
			else if(!InTree(r,u)) printf("%lld\n",Get(root,1,n,b[u],e[u]));
			else
			{
				int h=r;
				for(i=16;~i;i--) if(dep[par[h][i]]>dep[u]) h=par[h][i];
				printf("%lld\n",Get(root,1,n,1,n)-Get(root,1,n,b[h],e[h]));
			}
		}
	}
	return 0;
}