#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
const int inf=1e9+7;
void ckmn(int &a, int b){ a=min(a,b);}
void ckmx(int &a, int b){ a=max(a,b);}
struct Heap
{
	priority_queue<int> p,q;
	void push(int x){ p.push(-x);}
	void pop(int x){ for(q.push(-x);q.size()&&p.size()&&p.top()==q.top();q.pop(),p.pop());}
	int top(){ return -p.top();}
} hp[N];
vector<int> G[N];
int tid,disc[N],low[N],stk[N],top,n,par[N],cst[N],mn[N],go[N][2],tag[N],fa[N];
void Tarjan(int u)
{
	disc[u]=low[u]=++tid;
	stk[top++]=u;
	for(int v:G[u])
	{
		if(!disc[v])
		{
			Tarjan(v);
			ckmn(low[u],low[v]);
			if(low[v]>=disc[u])
			{
				for(n++,par[n]=fa[n]=u;stk[top]^v;)
				{
					int h=stk[--top];
					par[h]=fa[h]=n;
					hp[n].push(cst[h]);
				}
				cst[n]=hp[n].top();
			}
		}
		else ckmn(low[u],disc[v]);
	}
}
void push(int u)
{
	if(!tag[u]) return;
	swap(go[u][0],go[u][1]);
	tag[go[u][0]]^=1;
	tag[go[u][1]]^=1;
	tag[u]=0;
}
void pull(int u){ mn[u]=min(mn[go[u][0]],mn[go[u][1]]);ckmn(mn[u],cst[u]);}
int pd(int u){ if(go[fa[u]][0]==u) return 0;if(go[fa[u]][1]==u) return 1;return -1;}
void rot(int u)
{
	int x=fa[u],y=fa[x],tx=pd(u),ty=pd(x),v=go[u][tx^1];
	if(ty!=-1) go[y][ty]=u;go[u][tx^1]=x;go[x][tx]=v;
	if(v) fa[v]=x;fa[x]=u;fa[u]=y;
	pull(x);pull(u);
}
void cl(int u){ do{ stk[++top]=u;}while(pd(u)!=-1 && !((u=fa[u])*0));for(;top;push(stk[top--]));}
void splay(int u){ for(cl(u);pd(u)!=-1;rot(u)) if(pd(fa[u])!=-1) rot(pd(u)==pd(fa[u])?fa[u]:u);}
void access(int u){ for(splay(u),go[u][1]=0,pull(u);fa[u];rot(u)) splay(fa[u]),go[fa[u]][1]=u,pull(fa[u]);}
void rt(int u){ access(u);tag[u]^=1;push(u);}
int main()
{
	mn[0]=inf;
	int m,q,u,v,p;
	scanf("%i %i %i",&n,&m,&q);p=n;
	for(int i=1;i<=n;i++) scanf("%i",&cst[i]);
	for(int i=1;i<=m;i++) scanf("%i %i",&u,&v),G[u].pb(v),G[v].pb(u);
	Tarjan(1);top=0;
	for(int i=1;i<=n;i++) mn[i]=cst[i];
	for(char t;q--;)
	{
		scanf("\n%c %i %i",&t,&u,&v);
		if(t=='C')
		{
			if(u!=1)
			{
				int x=par[u];
				hp[x].pop(cst[u]);
				hp[x].push(v);
				splay(x);cst[x]=hp[x].top();pull(x);
			}
			splay(u);cst[u]=v;pull(u);
		}
		else
		{
			rt(1);access(u);access(v);splay(u);
			int lca=fa[u];
			rt(u);access(v);
			int ans=mn[v];
			if(lca>p) ckmn(ans,cst[par[lca]]);
			printf("%i\n",ans);
		}
	}
	return 0;
}