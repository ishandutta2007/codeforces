#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,h,ans[105][105];
int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    ans[i][j]=h;
	for(int i=1;i<=m;i++)
	{
		int v;
		scanf("%d",&v);
		for(int j=1;j<=n;j++)
		  ans[j][i]=min(ans[j][i],v);
	}
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		for(int j=1;j<=m;j++)
		  ans[i][j]=min(ans[i][j],v);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int v;
		scanf("%d",&v);
		ans[i][j]*=v;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		  printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}