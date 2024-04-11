#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[505][505],b[505][505];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&b[i][j]);
	for(int i=1;i<n;i++)
	for(int j=1;j<m;j++)
	{
		if(a[i][j]!=b[i][j])
		{
			a[i][j]^=1;
			a[i+1][j]^=1;
			a[i][j+1]^=1;
			a[i+1][j+1]^=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][m]!=b[i][m])
		{
			printf("No\n");
			return 0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[n][i]!=b[n][i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}