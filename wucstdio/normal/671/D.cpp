#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[600005];
struct Tree
{
	#define lson tree[x].child[0]
	#define rson tree[x].child[1]
	struct Node
	{
		int child[2];
		ll val;
		ll add;
		int dis;
		int en;
	}tree[300005];
	int tot;
	void pushdown(int x)
	{
		if(tree[x].add)
		{
			tree[lson].add+=tree[x].add;
			tree[rson].add+=tree[x].add;
			tree[lson].val+=tree[x].add;
			tree[rson].val+=tree[x].add;
			tree[x].add=0;
		}
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;
		pushdown(x);
		pushdown(y);
		if(tree[x].val>tree[y].val||(tree[x].val==tree[y].val&&x>y))swap(x,y);
		rson=merge(rson,y);
		if(tree[lson].dis<tree[rson].dis)swap(lson,rson);
		tree[x].dis=tree[rson].dis+1;
		return x;
	}
	int del(int x)
	{
		pushdown(x);
		return merge(lson,rson);
	}
	void add(int x,ll v)
	{
		if(x)
		{
			tree[x].val+=v;
			tree[x].add+=v;
		}
	}
	int insert(int x,ll v,int en)
	{
		tree[++tot].val=v;
		tree[tot].en=en;
		tree[tot].dis=1;
		return merge(x,tot);
	}
	#undef lson
	#undef rson
}q;
int n,m,edgenum,root[300005],head[300005],pa[300005],dep[300005];
ll f[300005];
vector<int>v[300005],c[300005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	ll sum=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		sum+=f[to];
	}
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		q.add(root[to],sum-f[to]);
		root[node]=q.merge(root[node],root[to]);
	}
	int m=(int)v[node].size();
	for(int i=0;i<m;i++)root[node]=q.insert(root[node],c[node][i]+sum,v[node][i]);
	while(dep[q.tree[root[node]].en]>=dep[node])root[node]=q.del(root[node]);
	if(!root[node])
	{
		printf("-1\n");
		exit(0);
	}
	f[node]=q.tree[root[node]].val;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	while(m--)
	{
		int uu,vv,cc;
		scanf("%d%d%d",&uu,&vv,&cc);
		if(vv==1)vv=0;
		v[uu].push_back(vv);
		c[uu].push_back(cc);
	}
	dfs(1);
	printf("%lld\n",f[1]);
	return 0;
}