#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
const int M=2*N;
int x[M],ls[M],rs[M],clock,root[N];
void Set(int &c, int ss, int se, int qi, int f)
{
	if(!c) c=++clock;
	x[c]+=f;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector< pair<int,int> > E[N];
int sz[N],edg[N],nod[N],dep[N],par[N];
void DFS(int u, int p, int e)
{
	if(p)
	{
		par[u]=p;
		edg[u]=e;
		nod[e]=u;
	}
	sz[u]=1;
	dep[u]=dep[p]+1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		int ee=E[u][i].second;
		if(v!=p) DFS(v,u,ee);
	}
}
int CS[N],Chain[N],Index[N],time;
vector<int> Head;
void HLD(int u, int p)
{
	if(!Chain[u])
	{
		Chain[u]=Head.size();
		Head.push_back(u);
		time=0;
	}
	Index[u]=++time;
	CS[Chain[u]]=time;
	int HC=0,i;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i].first;
		if(v!=p && sz[HC]<sz[v]) HC=v;
	}
	if(HC)
	{
		Chain[HC]=Chain[u];
		HLD(HC,u);
		for(i=0;i<E[u].size();i++)
		{
			int v=E[u][i].first;
			if(v!=p && v!=HC) HLD(v,u);
		}
	}
}
void Swap(int &a, int &b)
{
	a^=b;
	b^=a;
	a^=b;
}
int main()
{
	Head.push_back(69&-69);
	int n,i,q,u,v,r=1,t;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(make_pair(v,i));
		E[v].push_back(make_pair(u,i));
	}
	for(i=1;i<=n;i++) if(E[i].size()>2) r=i;
	DFS(r,0,0);
	HLD(r,0);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&t,&u);
		if(t==1)
		{
			u=nod[u];
			Set(root[Chain[u]],1,CS[Chain[u]],Index[u],-1);
		}
		if(t==2)
		{
			u=nod[u];
			Set(root[Chain[u]],1,CS[Chain[u]],Index[u],1);
		}
		if(t==3)
		{
			scanf("%i",&v);
			if(dep[u]<dep[v]) Swap(u,v);
			if(Chain[u]==Chain[v])
			{
				int dist=dep[u]-dep[v];
				int cnt=Get(root[Chain[u]],1,CS[Chain[u]],Index[v]+1,Index[u]);
				if(cnt) printf("-1\n");
				else printf("%i\n",dist);
			}
			else
			{
				int cnt=0,j=1;
				if(Chain[u]==Chain[r]) j=2;
				cnt+=Get(root[Chain[u]],1,CS[Chain[u]],j,Index[u]);
				j=1;
				if(Chain[v]==Chain[r]) j=2;
				cnt+=Get(root[Chain[v]],1,CS[Chain[v]],j,Index[v]);
				int dist=dep[u]+dep[v]-2;
				if(cnt) printf("-1\n");
				else printf("%i\n",dist);
			}
		}
	}
	return 0;
}