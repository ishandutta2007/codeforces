#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int N,M;

int head[220],nxt[2020],to[2020],cap[2020],e=0;
int f[2020];


int level[220];
int ite[220];

void bfs(int s)
{
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty())
	{
		int v=que.front();
		que.pop();
		for(int e=head[v];e!=-1;e=nxt[e])
		{
			if(cap[e]>f[e]&&level[to[e]]<0)
			{
				level[to[e]]=level[v]+1;
				que.push(to[e]);
			}
		}
	}
}

int dfs(int v,int t,int fl)
{
	if(v==t) return fl;
	for(int &e=ite[v];e!=-1;e=nxt[e])
	{
		if(cap[e]>f[e]&&level[v]<level[to[e]])
		{
			int d=dfs(to[e],t,min(fl,cap[e]-f[e]));
			if(d>0)
			{
				f[e]+=d;
				f[e^1]-=d;
				return d;
			}
		}
	}
	return 0;
}

int maxFlow(int s,int t)
{
	int res=0;
	for(int i=0;i<2020;i++) f[i]=0;
	for(;;)
	{
		bfs(s);
		if(level[t]<0) return res;
		for(int i=0;i<N;i++) ite[i]=head[i];
		int fl;
		while((fl=dfs(s,t,1<<29))>0)
		{
			res+=fl;
		}
	}
}

/*
bool used[220];

int dfs(int v,int t,int fl)
{
	if(v==t) return fl;
	used[v]=true;
	for(int e=head[v];e!=-1;e=nxt[e])
	{
		if((used[to[e]]==false)&&cap[e]>f[e])
		{
			int d=dfs(to[e],t,min(fl,cap[e]-f[e]));
			if(d>0)
			{
				f[e]+=d;
				f[e^1]-=d;
				return d;
			}
		}
	}
	return 0;
}

int maxFlow(int s,int t)
{
	int res=0;
	for(int i=0;i<2020;i++) f[i]=0;
	for(;;)
	{
		for(int i=0;i<220;i++) used[i]=false;
		int f=dfs(s,t,1<<29);
		if(f==0) return res;
		res+=f;
	}
}*/

struct UnionFind{
	int par[220];
	void init(int N)
	{
		for(int i=0;i<N;i++) par[i]=i;
	}
	int find(int v)
	{
		if(v==par[v]) return v;
		return par[v]=find(par[v]);
	}
	void unite(int u,int v)
	{
		u=find(u),v=find(v);
		if(u==v) return;
		par[u]=v;
	}
	bool same(int u,int v)
	{
		return find(u)==find(v);
	}
};

UnionFind uf;

struct edge{
	int u,v;
	int cost;
	edge(){}
	edge(int a,int b,int c):u(a),v(b),cost(c){}
};

edge edges[220*220];

bool cmp(const edge &e1,const edge &e2)
{
	return e1.cost<e2.cost;
}

int c=0;
int ansp[220];
int ans=0;

int G[220][220];
int par[220];

int Ms[220][220];

void getTree()
{
	int id=0;
//	for(int i=0;i<N;i++) for(int j=i+1;j<N;j++)
//	{
//		int flow=maxFlow(i,j);
//		edges[id++]=edge(i,j,flow);
//	}
	for(int i=1;i<N;i++) Ms[0][i]=maxFlow(0,i);
	for(int i=1;i<N;i++) for(int j=0;j<N;j++)
	{
		if(i==j) continue;
		if(i>j)
		{
			Ms[i][j]=Ms[j][i];
			continue;
		}
		bool flg=false;
		for(int k=0;k<i;k++)
		{
			if(Ms[k][i]!=Ms[k][j])
			{
				Ms[i][j]=min(Ms[k][i],Ms[k][j]);
				flg=true;
				break;
			}
		}
		if(flg==false) Ms[i][j]=maxFlow(i,j);
	}
	for(int i=0;i<N;i++) for(int j=i+1;j<N;j++)
	{
		edges[id++]=edge(i,j,Ms[i][j]);
	}
	sort(edges,edges+id,cmp);
	uf.init(N);
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) G[i][j]=-1;
	for(int i=id-1;i>=0;i--)
	{
		int u=edges[i].u,v=edges[i].v,c=edges[i].cost;
		if(uf.same(u,v)) continue;
		uf.unite(u,v);
		G[u][v]=c,G[v][u]=c;
	}
}

int u,cu;
int sz[220];
int search(int v,int p)
{
	if(p==-1) u=-1;
	par[v]=p;
	int c=1;
	for(int i=0;i<N;i++)
	{
		if(i==v||i==p) continue;
		if(G[i][v]==-1) continue;
		if(u==-1||G[i][v]<cu)
		{
			u=i;
			cu=G[i][v];
		}
		c+=search(i,v);
	}
	sz[v]=c;
	return c;
}

void solve(int r)
{
	search(r,-1);
	if(sz[r]==1)
	{
		ansp[c++]=r;
		return;
	}
	else if(sz[r]==2)
	{
		for(int i=0;i<N;i++) if(G[i][r]>0) ansp[c++]=i;
		ansp[c++]=r;
		return;
	}
	int u=::u,v=par[::u];
	int tmp=G[u][v];
	G[u][v]=-1;
	G[v][u]=-1;
	solve(u);
	solve(v);
	G[u][v]=tmp;
	G[v][u]=tmp;
}

void init()
{
	memset(head,-1,sizeof(head));
	memset(nxt,-1,sizeof(nxt));
}

void add_edge(int u,int v,int cost)
{
	nxt[e]=head[u];to[e]=v;head[u]=e;cap[e]=cost;e++;
	nxt[e]=head[v];to[e]=u;head[v]=e;cap[e]=cost;e++;
}

int main()
{
	init();
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		add_edge(a,b,c);
	}
	getTree();
	solve(0);
	int ans=0;
	for(int i=0;i<N-1;i++)
	{
		int f=maxFlow(ansp[i],ansp[i+1]);
		ans+=f;
	}
	printf("%d\n",ans);
	for(int i=0;i<N;i++) printf("%d%c",ansp[i]+1,i==N-1?'\n':' ');
	return 0;
}