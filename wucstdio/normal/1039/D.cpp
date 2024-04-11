#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int next;
}e[200005];
int n,edgenum,head[100005],f[100005],ans[100005],pa[100005],num,max1,max2,len;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	f[node]=0;
	int max1=0,max2=0;
	for(int hd=head[node];hd;hd=e[hd].next)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		if(f[to]>max1)max2=max1,max1=f[to];
		else if(f[to]>max2)max2=f[to];
	}
	if(max1+max2+1>=len)num++;
	else f[node]=max1+1;
}
int ff(int v)
{
	if(ans[v]!=-1)return ans[v];
	len=v;
	num=0;
	dfs(1);
	return ans[v]=num;
}
void solve(int l,int r,int ll,int rr)
{
	if(l>r)return;
	if(ll==rr)
	{
		for(int i=l;i<=r;i++)
		  ans[i]=ll;
		return;
	}
	int mid=l+r>>1;
	ans[mid]=ff(mid);
	solve(l,mid-1,ans[mid],rr);
	solve(mid+1,r,ll,ans[mid]);
}
int main()
{
	scanf("%d",&n);
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	solve(1,n,0,n);
	for(int i=1;i<=n;i++)
	  printf("%d\n",ans[i]);
	return 0;
}