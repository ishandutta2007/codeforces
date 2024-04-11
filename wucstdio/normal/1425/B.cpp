#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
struct Edge
{
	int to;
	int nxt;
}e[10005];
int n,m,edgenum,head[2005],a[2005];
ll f[2005][4005][2];
bool flag[2005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int dfs(int node)
{
	flag[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(!flag[to])return dfs(to)+1;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	m=n,n=0;
	flag[1]=1;
	for(int hd=head[1];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(!flag[to])a[++n]=dfs(to)+1;
	}
	f[0][2000][0]=1;
	for(int i=0;i<n;i++)
	for(int j=-m;j<=m;j++)
	{
		f[i][j+2000][0]%=MOD;
		f[i][j+2000][1]%=MOD;
		f[i+1][j+2000][0]+=f[i][j+2000][0];
		f[i+1][j+2000][1]+=f[i][j+2000][1];
		f[i+1][j+a[i+1]+2000][0]+=f[i][j+2000][0];
		f[i+1][j+a[i+1]+2000][1]+=f[i][j+2000][1];
		f[i+1][j-a[i+1]+2000][0]+=f[i][j+2000][0];
		f[i+1][j-a[i+1]+2000][1]+=f[i][j+2000][1];
		for(int x=1;x<a[i+1];x++)
		{
			int y=a[i+1]-x;
			f[i+1][j+x-y+2000][1]+=f[i][j+2000][0]*2;
			y--;
			if(y)f[i+1][j+x-y+2000][1]+=f[i][j+2000][0]*2;
		}
	}
	ll ans=f[n][2000][1];
	memset(f,0,sizeof(f));
	f[0][2000][0]=1;
	for(int i=0;i<n;i++)
	for(int j=-m;j<=m;j++)
	{
		f[i][j+2000][0]%=MOD;
		f[i][j+2000][1]%=MOD;
		f[i+1][j+a[i+1]+2000][0]+=f[i][j+2000][0];
		f[i+1][j+a[i+1]+2000][1]+=f[i][j+2000][1];
		f[i+1][j-a[i+1]+2000][0]+=f[i][j+2000][0];
		f[i+1][j-a[i+1]+2000][1]+=f[i][j+2000][1];
		f[i+1][j+a[i+1]-1+2000][1]+=f[i][j+2000][0]*2;
		f[i+1][j-a[i+1]+1+2000][1]+=f[i][j+2000][0]*2;
	}
	ans+=f[n][2000][0]+f[n][2000][1];
	printf("%lld\n",ans%MOD);
	return 0;
}