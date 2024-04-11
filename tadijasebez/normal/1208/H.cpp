//O(nlong) using Link-Cut Trees
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
pair<int,int> operator + (pair<int,int> a, pair<int,int> b)
{
	if(a.first>b.second || a.second<b.first) return a;
	return {max(a.first,b.first),min(a.second,b.second)};
}
const int N=100050;
const int inf=1e9+7;
struct Color
{
	int deg,cnt,cur,bal;
	vector<int> sz;
	Color(){}
	void init(int d){ deg=d;cnt=cur=bal=0;sz.clear();sz.resize(deg*2+1);}
	void upd()
	{
		while(cur>bal) cur--,bal+=2*sz[cur+deg];
		while(cur+1<=bal-2*sz[cur+deg]) bal-=2*sz[cur+deg],cur++;
	}
	void Add(int x)
	{
		cnt++;
		x=min(deg,max(-deg,x));
		sz[x+deg]++;
		if(x>=cur) bal++;
		else bal--;
		upd();
	}
	void Rem(int x)
	{
		cnt--;
		x=min(deg,max(-deg,x));
		sz[x+deg]--;
		if(x>=cur) bal--;
		else bal++;
		upd();
	}
	pair<int,int> Get()
	{
		if(cnt==deg) return {cur,cur};
		if(cnt==deg-1)
		{
			int l=cur,r=cur;
			if(cur==bal) l--;
			if(cur==bal-2*sz[cur+deg]) r++;
			return {l,r};
		}
		else return {0,0};
	}
} C[N];
int fa[N],go[N][2];
pair<int,int> path[N];
int pd(int x){ return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void pull(int x){ path[x]=(path[go[x][0]]+C[x].Get())+path[go[x][1]];}
void rot(int x)
{
    int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
    if(q!=-1) go[z][q]=x;go[y][p]=w;go[x][p^1]=y;
    if(w) fa[w]=y;fa[x]=z;fa[y]=x;
    pull(y);pull(x);
}
void Add(int x, int y){ if(y) C[x].Add(path[y].first);}
void Rem(int x, int y){ if(y) C[x].Rem(path[y].first);}
void splay(int x){ while(pd(x)!=-1){ if(pd(fa[x])!=-1) rot(pd(fa[x])==pd(x)?fa[x]:x);rot(x);}}
void access(int x)
{
	int tmp=x;
	for(int y=0;x;)
	{
		splay(x);
		Rem(x,y);
		Add(x,go[x][1]);
		go[x][1]=y;
		pull(x);
		y=x;
		x=fa[x];
	}
	splay(tmp);
}
void link(int x, int y){ splay(y);access(x);go[y][0]=x;fa[x]=y;pull(y);}
int n,k,q;
vector<int> E[N];
int par[N],st[N],lf[N];
vector<int> ord;
void DFS(int u, int p)
{
	int deg=0;
	ord.pb(u);
	for(int v:E[u]) if(v!=p)
	{
		deg++;
		par[v]=u;
		DFS(v,u);
	}
	C[u].init(deg);
	if(deg==0) lf[u]=1;
}
void P(int v)
{
	if(lf[v]) printf("%i\n",st[v]);
	else access(v),printf("%i\n",k<=C[v].cur?1:0);
}
void U(int v, int c)
{
	if(st[v]==c) return;
	access(par[v]);
	C[par[v]].Rem(st[v]==1?inf:-inf);
	st[v]=c;
	C[par[v]].Add(st[v]==1?inf:-inf);
	pull(par[v]);
}
int main()
{
	path[0]={-inf,inf};
	scanf("%i %i",&n,&k);
	for(int i=1,u,v;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(int i=1;i<=n;i++) scanf("%i",&st[i]);
	DFS(1,0);
	for(int i=2;i<=n;i++) if(lf[i]) C[par[i]].Add(st[i]==1?inf:-inf);
	reverse(ord.begin(),ord.end());
	for(int u:ord) if(!lf[u])
	{
		pull(u);
		if(par[u]) link(par[u],u);
	}
	scanf("%i",&q);
	while(q--)
	{
		int t,v,c;
		scanf("%i",&t);
		if(t==1) scanf("%i",&v),P(v);
		if(t==2) scanf("%i %i",&v,&c),U(v,c);
		if(t==3) scanf("%i",&k);
	}
	return 0;
}