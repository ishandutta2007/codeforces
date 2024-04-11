#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=250050;
const int LSZ=N*2;
int val[LSZ],go[LSZ][2],fa[LSZ],l_v[LSZ],r_v[LSZ],tag[LSZ];
void upd(int x){ if(x) swap(go[x][0],go[x][1]),swap(l_v[x],r_v[x]),tag[x]^=1;}
void push(int x){ if(tag[x]) upd(go[x][0]),upd(go[x][1]),tag[x]=0;}
void pull(int x)
{
	l_v[x]=l_v[go[x][0]]?l_v[go[x][0]]:val[x]?val[x]:l_v[go[x][1]];
	r_v[x]=r_v[go[x][1]]?r_v[go[x][1]]:val[x]?val[x]:r_v[go[x][0]];
}
int pd(int x){ return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x)
{
	int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
	if(~q) go[z][q]=x;go[y][p]=w;go[x][p^1]=y;
	if(w) fa[w]=y;fa[y]=x;fa[x]=z;
	pull(y);pull(x);
}
void cl(int x){ if(~pd(x)) cl(fa[x]);push(x);}
void splay(int x){ for(cl(x);~pd(x);rot(x)) if(~pd(fa[x])) rot(pd(x)==pd(fa[x])?fa[x]:x);}
void access(int x){ for(splay(x),go[x][1]=0,pull(x);fa[x];rot(x)) splay(fa[x]),go[fa[x]][1]=x,pull(fa[x]);}
void make_rt(int x){ access(x);upd(x);}
void link(int x, int y){ make_rt(y);fa[y]=x;}
void cut(int x, int y){ make_rt(x);access(y);assert(go[y][0]==x);go[y][0]=0;fa[x]=0;pull(y);}
void path(int x, int y){ make_rt(x);access(y);}
vector<int> E[N];
int e_u[N],e_v[N],n;
void DFS(int u, int p)
{
	for(int v:E[u]) if(v!=p) DFS(v,u);
	if(p)
	{
		path(u,p);
        int e=l_v[p];
        printf("%i %i %i %i\n",u,p,e_u[e],e_v[e]);
		cut(e_u[e],e+n);
		cut(e_v[e],e+n);
		val[e+n]=l_v[e+n]=r_v[e+n]=0;
		link(u,e+n);
		link(p,e+n);
	}
}
int main()
{
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(int i=1;i<n;i++) scanf("%i %i",&e_u[i],&e_v[i]),val[i+n]=l_v[i+n]=r_v[i+n]=i,link(i+n,e_u[i]),link(i+n,e_v[i]);
	printf("%i\n",n-1);
	DFS(1,0);
	return 0;
}