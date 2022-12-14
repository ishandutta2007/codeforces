#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n,m,Q;

struct node{int to,next;}e[N<<1];
int head[N],cnt;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}

vector<int >v[N];
// 
int dfn[N],low[N],tims,sta[N],top,bel[N],scc;
void tarjan(int x,int from)
{
	sta[++top] = x; dfn[x] = low[x] = ++tims;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(!dfn[to1])tarjan(to1,i),low[x] = min(low[x],low[to1]);
		else if((i^from)!=1)low[x] = min(low[x] , dfn[to1]);
	}
	if(dfn[x] == low[x])
	{
		int t;scc++;
		do{t=sta[top--],bel[t] = scc;}while(t!=x);
	}
}

// LCA
int fa[N],anc[N],dep[N],siz[N],son[N],idx[N],p[N];
void dfs1(int x,int from)
{
	fa[x]=from,dep[x]=dep[from]+1,siz[x]=1;
	for(int i = 0;i<v[x].size();i++)
	{
		int to1=v[x][i];
		if(to1!=from)dfs1(to1,x),siz[x]+=siz[to1],siz[son[x]]<siz[to1]?son[x]=to1:0;
	}
}
void dfs2(int x,int top)
{
	anc[x] = top; idx[x] = ++tims , p[tims] = x;if(son[x]) dfs2(son[x],top);
	for(int i = 0;i<v[x].size();i++)if(v[x][i]!=fa[x]&&v[x][i]!=son[x])
		dfs2(v[x][i],v[x][i]);
}
int get_lca(int x,int y)
{
	while(anc[x]!=anc[y])
	{
		if(dep[anc[x]]<dep[anc[y]])swap(x,y);
		x=fa[anc[x]];
	}return dep[x]<dep[y]?x:y;
}

int f[N],tag[N];
int find(int x){tims++;return x==f[x]?x:f[x]=find(f[x]);}
int cover(int x,int y,int flag)
{
	if(x==y)return 0;
	// for(int i=1;i<=n;i++)printf("%d ",find(i));puts("");
	while(dep[fa[find(x)]] > dep[y])
	{
		if(tag[find(x)] == -flag)return 1;
		x = find(x) , f[x] = fa[x] , x = fa[x];
	}
	if(tag[find(x)] == -flag)return 1;tag[find(x)] = flag;return 0;
}

int main()
{
	scanf("%d%d%d",&n,&m,&Q);memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,-1);tims = 0;
	for(int x=1;x<=n;x++)
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(bel[to1]!=bel[x])
				v[bel[x]].push_back(bel[to1]);
		}
	for(int i=1;i<=scc;i++)if(!dep[i])dfs1(i,0),dfs2(i,i);
	for(int i=1;i<=scc;i++)f[i] = i , tag[i] = 0;
	tims=0;
	for(int x,y;Q--;)
	{
		scanf("%d%d",&x,&y); x = bel[x] , y = bel[y];
		if(x==y)continue;int lca = get_lca(x,y);if(!lca)return puts("No"),0;
		if(cover(x,lca,1)||cover(y,lca,-1))return puts("No"),0;
		// cover(x,lca,1),cover(y,lca,2);
	}
	puts("Yes");
}