#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[505][505],f[505][2005],now[505][2005],ans[505];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int v=0;v<1024;v++)
		{
			for(int j=1;j<=m;j++)
			{
				if(f[i][v])break;
				f[i][v]|=f[i-1][v^a[i][j]];
				now[i][v]=j;
			}
		}
	}
	for(int i=1;i<1024;i++)
	{
		if(f[n][i])
		{
			printf("TAK\n");
			int nowx=n,nowy=i;
			while(nowx)
			{
				ans[nowx]=now[nowx][nowy];
				nowy^=a[nowx][ans[nowx]];
				nowx--;
			}
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);
			printf("\n");
			return 0;
		}
	}
	printf("NIE\n");
	return 0;
}