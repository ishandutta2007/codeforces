#include<bits/stdc++.h>
#define ll long long
#define maxn 600005
using namespace std;
int n,q;
vector<int> T[maxn];
int root;
namespace Tree
{
	struct edge
	{
		int to,next;
	}e[maxn<<1];
	int head[maxn],p;
	int cnt;
	void addedge(int u,int v)
	{
		e[++p].to=v;e[p].next=head[u];head[u]=p;
		e[++p].to=u;e[p].next=head[v];head[v]=p;
	}
	int rt,nowsize;
	bool del[maxn];
	int sum[maxn],f[maxn];
	void getroot(int u,int fa)
	{
	    sum[u]=1;f[u]=0;
	    for(int i=head[u];i;i=e[i].next)
	    {
	        int v=e[i].to;
			if(v==fa||del[v])continue;
	        getroot(v,u);
			sum[u]+=sum[v];
	        if(sum[v]>f[u])f[u]=sum[v];
	    }
	    f[u]=max(f[u],nowsize-sum[u]);
	    if(f[u]<f[rt])rt=u;
	}
	void solve(int u)
	{
	    del[u]=1;
	    for(int i=head[u];i;i=e[i].next)
	    {
	        int v=e[i].to;
			if(del[v])continue;
	        rt=0;
			f[rt]=nowsize=sum[v];
	        getroot(v,0);
			T[u].push_back(rt);
			T[u+1].push_back(rt+1); 
			solve(rt);
	    }
	}
	void work()
	{
		rt=0;
		f[rt]=nowsize=n;
    	getroot(1,0);
    	root=rt;
		solve(rt);
	}
};
namespace Graph
{
	const ll inf = (ll)2e18;
	struct Query
	{
		int u,v,id;
		Query(){}
		Query(int U,int V,int ID){u=U;v=V;id=ID;}
	};
	ll Ans[maxn];
	vector<Query> vq[maxn];
	struct edge
	{
		int to,next;
		ll w;
	}e[maxn<<2];
	bool used[maxn];
	bool del[maxn];
	int head[maxn],p;
	void addedge(int u,int v,ll w)
	{
		e[++p].to=v;e[p].w=w;e[p].next=head[u];head[u]=p;
		e[++p].to=u;e[p].w=w;e[p].next=head[v];head[v]=p;
	}
	struct node
	{
		int x;ll dis;
		node(){}
		node(int id,ll d){x=id;dis=d;}
	};
	bool operator < (node a,node b)
	{
		return a.dis>b.dis;
	}
	ll dis[maxn];
	void dijkstra(int s)
	{
		priority_queue<node> q;
		q.push(node(s,0));dis[s]=0;
		while(!q.empty())
		{
			int u=q.top().x;q.pop();
			if(used[u])continue;
			used[u]=1;
			for(int i=head[u];i;i=e[i].next)if(!del[e[i].to])
			{
				int v=e[i].to;
				ll w=e[i].w;
				if(dis[v]>dis[u]+w)
				{
					dis[v]=dis[u]+w;
					q.push(node(v,dis[v]));
				}
			}
		}
	}
	int belong[maxn];
	void clear(int u)
	{
		dis[u]=inf;used[u]=0;
		for(int i=0;i<T[u].size();++i)clear(T[u][i]);
	}
	void get_belong(int u,int rt,int tp)
	{
		belong[u]=rt+tp;
		for(int i=0;i<T[u].size();++i)
		{
			int v=T[u][i];
			get_belong(v,rt,tp);
		}
	}
	void dfs(int rt)
	{
		if(!vq[rt].size())return;
		clear(rt);
		clear(rt+1);
		dijkstra(rt);
		for(int i=0;i<vq[rt].size();++i)
		{
			int u=vq[rt][i].u,v=vq[rt][i].v;
			Ans[vq[rt][i].id]=min(Ans[vq[rt][i].id],dis[u]+dis[v]);
		}
		clear(rt);
		clear(rt+1);
		dijkstra(rt+1);
		for(int i=0;i<vq[rt].size();++i)
		{
			int u=vq[rt][i].u,v=vq[rt][i].v;
			Ans[vq[rt][i].id]=min(Ans[vq[rt][i].id],dis[u]+dis[v]);
		}
		del[rt]=1;del[rt+1]=1;
		for(int i=0;i<T[rt].size();++i)get_belong(T[rt][i],T[rt][i],0);
		for(int i=0;i<T[rt+1].size();++i)get_belong(T[rt+1][i],T[rt+1][i],-1);
		for(int i=0;i<vq[rt].size();++i)
		{
			int u=vq[rt][i].u,v=vq[rt][i].v;
			if(u==rt||v==rt||u==rt+1||v==rt+1)continue;
			if(belong[u]==belong[v])vq[belong[u]].push_back(vq[rt][i]);
		}
		for(int i=0;i<T[rt].size();++i)dfs(T[rt][i]);
	}
	void work()
	{
		Tree::work();
		for(int i=1;i<=q;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			vq[root].push_back(Query(u,v,i));
			Ans[i]=inf;
		}
		dfs(root);
		for(int i=1;i<=q;++i)printf("%I64d\n",Ans[i]);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		ll w;
		scanf("%I64d",&w);
		Graph::addedge(i*2-1,i*2,w);
	}
	for(int i=1;i<n;++i)
	{
		int x,y;ll w1,w2;
		scanf("%d%d%I64d%I64d",&x,&y,&w1,&w2);
		Graph::addedge(x*2-1,y*2-1,w1);
		Graph::addedge(x*2,y*2,w2);
		Tree::addedge(x*2-1,y*2-1);
	}
	scanf("%d",&q); 
	Graph::work();
	return 0;
}