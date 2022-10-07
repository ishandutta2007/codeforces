#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
int maxv[2000005];
void update(int o,int l,int r,int from,int to,int v)
{
	if(from>to)return;
	if(l>=from&&r<=to)
	{
		maxv[o]=max(maxv[o],v);
		return;
	}
	if(from<=mid)update(lson,l,mid,from,to,v);
	if(to>mid)update(rson,mid+1,r,from,to,v);
}
int query(int o,int l,int r,int p)
{
	int ans=maxv[o];
	if(l==r)return ans;
	if(p<=mid)ans=max(ans,query(lson,l,mid,p));
	else ans=max(ans,query(rson,mid+1,r,p));
	return ans;
}
struct Edge
{
	int to;
	int nxt;
}e[1000005];
struct Node
{
	int dep;
	int in;
}tmp[1000005];
int n,m,edgenum,head[500005],pa[500005],dep[500005],d[500005],max1[500005],max2[500005],ans[500005];
int a[500005],top,_f[2000005],*f[2000005],tot;
int num[500005];
priority_queue<int>q,del;
bool cmp(Node a,Node b)
{
	return a.dep<b.dep;
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	f[node]=_f+tot;
	tot+=d[node]+2;
	dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		if(max1[to]+1>max1[node])
		{
			max2[node]=max1[node];
			max1[node]=max1[to]+1;
		}
		else if(max1[to]+1>max2[node])
		  max2[node]=max1[to]+1;
	}
}
void dfs2(int node)
{
	top=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		a[++top]=max1[to]+1;
	}
	if(pa[node])
	{
		if(max1[pa[node]]==max1[node]+1)a[++top]=max2[pa[node]]+1;
		else a[++top]=max1[pa[node]]+1;
	}
	a[++top]=0;
	sort(a+1,a+top+1);
	for(int i=1;i<=top;i++)f[node][top-i+1]=a[i];
	for(int i=1;i<=top;i++)
	{
		ans[f[node][i]*2]=max(ans[f[node][i]*2],i);
		if(f[node][i-1]!=f[node][i])ans[f[node][i]*2+1]=max(ans[f[node][i]*2+1],i);
	}
//	printf("%d:max1=%d,max2=%d\n",node,max1[node],max2[node]);
//	for(int i=1;i<=top;i++)printf("%d ",a[i]);
//	printf("\n");
//	for(int i=1;i<=d[node]+1;i++)printf("%d ",f[node][i]);
//	printf("\n");
	top=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])
		{
			tmp[++top].in=node;
			if(max1[pa[node]]==max1[node]+1)tmp[top].dep=max2[pa[node]]+1;
			else tmp[top].dep=max1[pa[node]]+1;
			continue;
		}
		tmp[++top].in=node;
		tmp[top].dep=max1[to]+1;
		for(int hd=head[to];hd;hd=e[hd].nxt)
		{
			int to2=e[hd].to;
			if(to2==node)continue;
			tmp[++top].in=to;
			tmp[top].dep=max1[to2]+1;
		}
	}
	while(!q.empty()) q.pop();
	while(!del.empty()) del.pop();
	sort(tmp+1,tmp+top+1,cmp);
	num[node]=d[node];
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		num[to]=d[to]-1;
		q.push(num[to]);
	}
	for(int i=1;i<=top;i++)
	{
		if(tmp[i].in==node)
		{
			while(!q.empty()&&!del.empty()&&q.top()==del.top())q.pop(),del.pop();
			if(q.empty())continue;
			update(1,1,n,1,tmp[i].dep,num[node]-1+q.top());
			num[node]--;
		}
		else
		{
			update(1,1,n,1,tmp[i].dep,num[node]-1+num[tmp[i].in]);
			del.push(num[tmp[i].in]);
			num[tmp[i].in]--;
			if(num[tmp[i].in])q.push(num[tmp[i].in]);
		}
	}
	if(pa[node])
	{
		int v=0;
		if(max1[node]+1==max1[pa[node]])v=max2[pa[node]];
		else v=max1[pa[node]];
		if(v+1>max1[node])
		{
			max2[node]=max1[node];
			max1[node]=v+1;
		}
		else if(v+1>max2[node])
		  max2[node]=v+1;
	}
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		dfs2(to);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)ans[i]=1;
	dfs1(1);
	dfs2(1);
	for(int i=n;i>=1;i--)ans[i]=max(ans[i],ans[i+1]);
	for(int i=1;i<=n;i++)
	{
		if(i&1)printf("%d ",ans[i]);
		else printf("%d ",max(ans[i],query(1,1,n,i/2)));
	}
	return 0;
}