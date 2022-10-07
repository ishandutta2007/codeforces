#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[20000005];
int n,m,r,g,edgenum,d[10005],head[10005],dep[10005],f[10005][1005],tmp[10005][1005];
int flag[1000505];
queue<int>q;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&d[i]);
	sort(d+1,d+m+1);
	for(int i=1;i<=m;i++)flag[d[i]]=i;
	scanf("%d%d",&g,&r);
	for(int i=m;i>=1;i--)
	{
		f[i][0]=i;
		for(int l=1;l<=g;l++)
			f[i][l]=tmp[i+1][l-(d[i+1]-d[i])];
		for(int l=0;l<=g;l++)
		{
			tmp[i][l]=f[i][l];
			if(l>=d[i]-d[i-1])tmp[i][l]=max(tmp[i][l],tmp[i][l-(d[i]-d[i-1])]);
		}
	}
	for(int i=0;i<=g;i++)
	{
		for(int j=1;j<=m;j++)
		  f[j][i]=max(f[j][i],f[j-1][i]);
	}
	for(int j=1;j<=m;j++)
	{
		for(int k=j+1;k<=m&&d[k]-d[j]<=g;k++)
		{
			int x=g+(d[k]-d[j]);
			if(x&1)continue;
			x/=2;
			if(f[j][x]>=k)
			{
				add(j,k);
				add(k,j);
			}
		}
	}
	dep[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(!dep[to])
			{
				dep[to]=dep[node]+1;
				q.push(to);
			}
		}
	}
	int ans=1e9;
	for(int i=1;i<=m;i++)
	{
		if(dep[i]&&d[m]-d[i]<=g)
		  ans=min(ans,(dep[i]-1)*(g+r)+(d[m]-d[i]));
	}
	if(ans==1e9)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}