#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
const int M=200050;
int f[N];
struct Node
{
	int l,r,sz,sum;
	Node(){ l=r=sz=sum=0;}
	bool full(){ return sz==l && l && r;}
	void Empty(int a){ sz=0;l=r=sum=0;}
	void One(){ l=r=sz=1;sum=f[1];}
	Node operator + (Node b) const
	{
		Node c;
		c.sz=sz+b.sz;
		c.sum=sum+b.sum-f[r]-f[b.l]+f[r+b.l];
		if(sz==l && l && r) c.l=l+b.l;
		else c.l=l;
		if(b.full()) c.r=r+b.r;
		else c.r=b.r;
		return c;
	}
	void Reverse(){ l^=r;r^=l;l^=r;}
} node[M],ret;
int ls[M],rs[M],tsz,root[N];
void Make(int &c, int ss, int se){ if(!c) c=++tsz,node[c].Empty(se-ss+1);}
void Set(int &c, int ss, int se, int qi)
{
	if(!c) c=++tsz,node[c].Empty(se-ss+1);
	if(ss==se){ if(node[c].sum) printf("???\n");node[c].One();return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
	Make(ls[c],ss,mid);Make(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
Node Get(int &c, int ss, int se, int qs, int qe)
{
	if(!c) c=++tsz,node[c].Empty(se-ss+1);
	if(qs>qe || qs>se || ss>qe) return ret;
	if(qs<=ss && qe>=se) return node[c];
	int mid=ss+se>>1;
	Node x=Get(ls[c],ss,mid,qs,qe);
	Node y=Get(rs[c],mid+1,se,qs,qe);
	if(qs>mid) return y;
	if(qe<mid+1) return x;
	return x+y;
}
struct Edge{ int u,v,w,i;Edge(int a, int b, int c, int d){ u=a,v=b,w=c,i=d;}};
vector<Edge> edges;
vector<pair<int,int> > E[N];
vector<int> Head;
void Init(){ Head.pb(0);}
int sz[N],edg[N],par[N][17],dep[N],chn[N],csz[N],idx[N],nod[N];
void DFS(int u, int p, int e)
{
	sz[u]=1;
	par[u][0]=p;
	dep[u]=dep[p]+1;
	edg[u]=e;
	if(e) nod[e]=u;
	int i;
	for(i=1;i<17;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(i=0;i<E[u].size();i++)
	{
		int e1=E[u][i].second;
		int v=E[u][i].first;
		if(v!=p) DFS(v,u,e1),sz[u]+=sz[v];
	}
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=16;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=16;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return v==u?v:par[v][0];
}
void HLD(int u, int p)
{
	if(!chn[u])
	{
		chn[u]=Head.size();
		Head.pb(u);
	}
	idx[u]=++csz[chn[u]];
	int HC=0,i;
	for(i=0;i<E[u].size();i++)
	{
		int e1=E[u][i].second;
		int v=E[u][i].first;
		if(v!=p && sz[v]>sz[HC]) HC=v;
	}
	if(HC)
	{
		chn[HC]=chn[u];HLD(HC,u);
		for(i=0;i<E[u].size();i++)
		{
			int e1=E[u][i].second;
			int v=E[u][i].first;
			if(v!=p && v!=HC) HLD(v,u);
		}
	}
}
Node Get(int u, int lca)
{
	if(chn[u]==chn[lca]) return Get(root[chn[u]],1,csz[chn[u]],idx[lca]+1,idx[u]);
	else
	{
		Node x=Get(root[chn[u]],1,csz[chn[u]],1,idx[u]);
		Node y=Get(par[Head[chn[u]]][0],lca);
		if(par[Head[chn[u]]][0]==lca) return x;
		return y+x;
	}
}
int sol[N];
struct Event
{
	int t,u,v,w,i;
	Event(int a, int b, int c, int d, int e){ t=a,u=b,v=c,w=d,i=e;}
	bool operator < (Event b) const { return (w==b.w && t<b.t) || w>b.w;}
};
vector<Event> events;
int main()
{
	Init();
	int n,q,i,u,v,w,t,id;
	scanf("%i %i",&n,&q);
	for(i=1;i<n;i++) scanf("%i",&f[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		edges.pb(Edge(u,v,w,i));
		E[u].pb(mp(v,i));E[v].pb(mp(u,i));
		events.pb(Event(0,u,v,w,i));
	}
	DFS(1,0,0);HLD(1,0);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		events.pb(Event(1,u,v,w,i));
	}
	sort(events.begin(),events.end());
	for(i=0;i<events.size();i++)
	{
		t=events[i].t;
		u=events[i].u;
		v=events[i].v;
		id=events[i].i;
		if(t==0)
		{
			u=nod[id];
			Set(root[chn[u]],1,csz[chn[u]],idx[u]);
		}
		else
		{
			int lca=LCA(u,v);
			Node x=Get(u,lca);x.Reverse();
			Node y=Get(v,lca);
			if(u==lca) sol[id]=y.sum;
			else if(v==lca) sol[id]=x.sum;
			else x=x+y,sol[id]=x.sum;
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}