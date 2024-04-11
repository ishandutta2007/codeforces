#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k,q;
short f[1005][1005][45],d[1005][1005][45],dis[45][45];
int col[1005][1005];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&col[i][j]);
	memset(dis,0x3f,sizeof(dis));
	memset(d,0x3f,sizeof(d));
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		for(int x=1;x<=k;x++)
		{
			f[i][j][x]=min(f[i-1][j][x]+1,f[i][j-1][x]+1);
			dis[col[i][j]][x]=dis[x][col[i][j]]=min(dis[x][col[i][j]],f[i][j][x]);
			d[i][j][x]=min(d[i][j][x],f[i][j][x]);
		}
		f[i][j][col[i][j]]=0;
	}
	for(int i=1;i<=n;i++)
	for(int j=m;j>=1;j--)
	{
		for(int x=1;x<=k;x++)
		{
			f[i][j][x]=min(f[i-1][j][x]+1,f[i][j+1][x]+1);
			dis[col[i][j]][x]=dis[x][col[i][j]]=min(dis[x][col[i][j]],f[i][j][x]);
			d[i][j][x]=min(d[i][j][x],f[i][j][x]);
		}
		f[i][j][col[i][j]]=0;
	}
	for(int i=n;i>=1;i--)
	for(int j=1;j<=m;j++)
	{
		for(int x=1;x<=k;x++)
		{
			f[i][j][x]=min(f[i+1][j][x]+1,f[i][j-1][x]+1);
			dis[col[i][j]][x]=dis[x][col[i][j]]=min(dis[x][col[i][j]],f[i][j][x]);
			d[i][j][x]=min(d[i][j][x],f[i][j][x]);
		}
		f[i][j][col[i][j]]=0;
	}
	for(int i=n;i>=1;i--)
	for(int j=m;j>=1;j--)
	{
		for(int x=1;x<=k;x++)
		{
			f[i][j][x]=min(f[i+1][j][x]+1,f[i][j+1][x]+1);
			dis[col[i][j]][x]=dis[x][col[i][j]]=min(dis[x][col[i][j]],f[i][j][x]);
			d[i][j][x]=min(d[i][j][x],f[i][j][x]);
		}
		f[i][j][col[i][j]]=0;
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    d[i][j][col[i][j]]=0;
	for(int i=1;i<=k;i++)dis[i][i]=0;
	for(int x=1;x<=k;x++)
	  for(int i=1;i<=k;i++)
	    for(int j=1;j<=k;j++)
	      dis[i][j]=min((int)dis[i][j],dis[i][x]+dis[x][j]+1);
	scanf("%d",&q);
	while(q--)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&b,&x,&y);
		if(a==x&&b==y)
		{
			printf("0\n");
			continue;
		}
		if(col[a][b]==col[x][y])
		{
			printf("1\n");
			continue;
		}
		int ans=2147483647;
		for(int i=1;i<=k;i++)
		  for(int j=1;j<=k;j++)
		    ans=min(ans,dis[i][j]+d[a][b][i]+1+d[x][y][j]+(i!=j));
		ans=min(ans,abs(a-x)+abs(b-y));
		printf("%d\n",ans);
	}
	return 0;
}