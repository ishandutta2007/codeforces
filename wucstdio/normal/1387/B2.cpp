#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[200005];
int n,edgenum,head[100005],pa[100005],sze[100005],maxs[100005],match[100005],root;
ll ans;
priority_queue<pair<int,int> >q;
vector<int>s[100005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	sze[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		sze[node]+=sze[to];
		maxs[node]=max(maxs[node],sze[to]);
	}
	maxs[node]=max(maxs[node],n-sze[node]);
	if(maxs[node]<maxs[root])root=node;
	ans+=min(sze[node],n-sze[node])*2;
}
void dfs2(int node,int r)
{
	s[r].push_back(node);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs2(to,r);
	}
}
int main()
{
	maxs[0]=2147483647;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	printf("%lld\n",ans);
	pa[root]=0;
	dfs(root);
	for(int hd=head[root];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		dfs2(to,to);
		q.push(make_pair(sze[to],to));
	}
	sze[root]=1;
	q.push(make_pair(1,root));
	s[root].push_back(root);
	int now=n;
	while(now&&now!=3)
	{
		int x=q.top().second;
		q.pop();
		int y=q.top().second;
		q.pop();
		sze[x]--;
		sze[y]--;
		if(sze[x])q.push(make_pair(sze[x],x));
		if(sze[y])q.push(make_pair(sze[y],y));
		x=s[x][sze[x]],y=s[y][sze[y]];
		match[x]=y,match[y]=x;
		now-=2;
	}
	if(now==3)
	{
		int x=q.top().second;
		q.pop();
		int y=q.top().second;
		q.pop();
		int z=q.top().second;
		q.pop();
		x=s[x][0],y=s[y][0],z=s[z][0];
		match[x]=y,match[y]=z,match[z]=x;
	}
	for(int i=1;i<=n;i++)printf("%d ",match[i]);
	printf("\n");
	return 0;
	return 0;
}