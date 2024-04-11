#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[600005];
int t,n,m,edgenum,head[300005],dep[300005],pa[300005],mx1[300005],mx2[300005],nxt[300005];
int d[300005],v[300005],pre[300005],st[25][600005],lg2[300005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	mx1[node]=dep[node];
	mx2[node]=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dep[to]=dep[node]+1;
		dfs(to);
		if(mx1[to]>mx1[node])
		{
			mx2[node]=mx1[node];
			mx1[node]=mx1[to];
			nxt[node]=to;
		}
		else if(mx1[to]>mx2[node])
			mx2[node]=mx1[to];
	}
}
void Pre()
{
	for(int i=2;i<=m;i++)
		lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=m;i++)
	{
		pre[i]=max(pre[i-1],d[i]+v[i]);
		st[0][i]=v[i]-i;
	}
	for(int i=m+1;i<=2*m;i++)st[0][i]=0;
	for(int i=1;i<=lg2[m];i++)
		for(int j=1;j<=m;j++)
			st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int ask(int l,int r)
{
	int k=lg2[r-l+1];
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
pair<int,int>calc(int l,int k)
{
	if(l>=k-1)return make_pair(pre[k-1],d[m]+v[m]);
	int mid=(l+k+1)>>1;
	int v1=pre[mid];
	int v2=ask(mid+1,k)+k+l;
//	printf("calc(%d,%d),v:%d %d %d\n",l,k,v1,v2,v[m]+d[m]-d[k]+l);
	return make_pair(max(v1,v2),v[m]+d[m]-d[k]+l);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)head[i]=pa[i]=dep[i]=nxt[i]=0;
		edgenum=m=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs(1);
		int cur=1;
		while(cur)
		{
			d[++m]=dep[cur];
			v[m]=max(0,mx2[cur]-dep[cur]);
			cur=nxt[cur];
//			printf("%d ",v[m]);
		}
//		printf("\n");
		Pre();
		cur=1;
		for(int i=1;i<=n;i++)
		{
			if(cur==m)
			{
				pair<int,int>a=calc(i,cur);
				int sa=max(a.first,a.second);
				printf("%d ",sa);
				continue;
			}
			pair<int,int>a=calc(i,cur);
			pair<int,int>b=calc(i,cur+1);
			int sa=max(a.first,a.second),sb=max(b.first,b.second);
			int ans=min(sa,sb);
			while(b.first<b.second&&cur<m-1)
			{
				cur++;
				a=b;
				b=calc(i,cur+1);
				ans=min(ans,max(b.first,b.second));
			}
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}