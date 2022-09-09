#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define mp make_pair
#define pb push_back
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int pos(int x){ return x<<1;}
int neg(int x){ return x<<1|1;}
const int N=100050;
const int H=(N*2+20050*14*14)*2;
struct TwoSat
{
	vector<int> E[H];
	TwoSat(){}
	int sz;
	void imply(int u, int v){ E[u].pb(v);sz=max(sz,u|1);sz=max(sz,v|1);}
	int disc[H],low[H],tid,comp[H],csz;
	bool in[H],sol[H];stack<int> st;
	void Trajan(int u)
	{
		disc[u]=low[u]=++tid;st.push(u);in[u]=1;
		for(int i=0;i<E[u].size();i++)
		{
			int v=E[u][i];
			if(!disc[v])
			{
				Trajan(v);
				low[u]=min(low[u],low[v]);
			}
			else if(in[v]) low[u]=min(low[u],disc[v]);
		}
		if(disc[u]==low[u])
		{
			int v;csz++;
			do
			{
				v=st.top();
				comp[v]=csz;
				st.pop();
				in[v]=0;
			}while(v!=u);
		}
	}
	bool Check()
	{
		int i;
		for(i=0;i<=sz;i++) if(!disc[i]) Trajan(i);
		for(i=0;i<=sz;i++) if(comp[i]==comp[i^1]) return 0;
		return 1;
	}
	vector<vector<int> > G;
	vector<int> lsz,exp;
	void Solve()
	{
		int i,j;
		G.resize(csz+1);
		lsz.resize(csz+1);
		exp.resize(csz+1);
		for(i=0;i<=sz;i++)
		{
			for(j=0;j<E[i].size();j++)
			{
				int v=E[i][j];
				if(comp[i]!=comp[v]) G[comp[i]].pb(comp[v]),lsz[comp[v]]++;
			}
		}
		queue<int> q;
		for(i=1;i<=csz;i++) if(!lsz[i]) q.push(i);
		int tm=0;
		while(q.size())
		{
			int x=q.front();q.pop();
			exp[x]=++tm;
			for(i=0;i<G[x].size();i++)
			{
				int y=G[x][i];
				lsz[y]--;
				if(!lsz[y]) q.push(y);
			}
		}
		for(i=0;i<=sz;i+=2) if(exp[comp[i^1]]<exp[comp[i]]) sol[i>>1]=1;
	}
} TwoSat;
int bsz,root[N<<1];
void Merge(int &c, int a, int b)
{
	if(a==-1){ c=b;return;}
	if(b==-1){ c=a;return;}
	c=++bsz;
	TwoSat.imply(pos(a),pos(c));
	TwoSat.imply(neg(c),neg(a));
	TwoSat.imply(pos(b),pos(c));
	TwoSat.imply(neg(c),neg(b));
	TwoSat.imply(pos(a),neg(b));
	TwoSat.imply(pos(b),neg(a));
}
int head[N],par[N],sz[N],lid[N],csz[N],tid,dep[N];
vector<int> E[N];
void DFS(int u, int p)
{
	sz[u]=1;
	par[u]=p;
	dep[u]=dep[p]+1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u),sz[u]+=sz[v];
	}
}
void HLD(int u, int p)
{
	int i,HC=0;
	lid[u]=++tid;
	for(i=0;i<E[u].size();i++){ int v=E[u][i];if(v!=p && sz[v]>sz[HC]) HC=v;}
	if(HC) head[HC]=head[u],HLD(HC,u);
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && v!=HC)
		{
			head[v]=v;
			HLD(v,u);
		}
	}
}
int LCA(int u, int v)
{
	while(head[u]!=head[v])
	{
		if(dep[par[head[u]]]>dep[par[head[v]]]) u=par[head[u]];
		else v=par[head[v]];
	}
	return dep[v]<dep[u]?v:u;
}
int ls[N<<1],rs[N<<1],rt,tsz;
void Add(int &c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || ss>qe || qs>se) return;
	if(!c) c=++tsz,root[c]=-1;
	if(qs<=ss && qe>=se){ Merge(root[c],root[c],x);return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,x);
	Add(rs[c],mid+1,se,qs,qe,x);
}
void Solve(int p, int c, int ss, int se)
{
	if(!c) return;
	if(p) Merge(root[c],root[c],root[p]);
	if(ss==se) return;
	int mid=ss+se>>1;
	Solve(c,ls[c],ss,mid);
	Solve(c,rs[c],mid+1,se);
}
int main()
{
	int n,u,v,i,m,a,b,c,d;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	head[1]=1;
	HLD(1,0);
	scanf("%i",&m);bsz=m*2;
	for(i=0;i<m;i++)
	{
		scanf("%i %i %i %i",&a,&b,&c,&d);
		TwoSat.imply(neg(i<<1),pos(i<<1|1));
		TwoSat.imply(neg(i<<1|1),pos(i<<1));
		int lca=LCA(a,b);
		while(head[a]!=head[lca])
		{
			Add(rt,1,n,lid[head[a]],lid[a],i<<1);
			a=par[head[a]];
		}
		Add(rt,1,n,lid[lca]+1,lid[a],i<<1);
		while(head[b]!=head[lca])
		{
			Add(rt,1,n,lid[head[b]],lid[b],i<<1);
			b=par[head[b]];
		}
		Add(rt,1,n,lid[lca]+1,lid[b],i<<1);
		lca=LCA(c,d);
		while(head[c]!=head[lca])
		{
			Add(rt,1,n,lid[head[c]],lid[c],i<<1|1);
			c=par[head[c]];
		}
		Add(rt,1,n,lid[lca]+1,lid[c],i<<1|1);
		while(head[d]!=head[lca])
		{
			Add(rt,1,n,lid[head[d]],lid[d],i<<1|1);
			d=par[head[d]];
		}
		Add(rt,1,n,lid[lca]+1,lid[d],i<<1|1);
	}
	Solve(0,rt,1,n);
	if(TwoSat.Check())
	{
		printf("YES\n");
		TwoSat.Solve();
		for(i=0;i<m;i++)
		{
			if(TwoSat.sol[i<<1]) printf("1\n");
			else printf("2\n");
		}
	}
	else printf("NO\n");
	return 0;
}