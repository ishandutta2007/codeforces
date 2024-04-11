#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m,a[55][55],b[55][55];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&b[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int x=a[i][j],y=b[i][j];
		a[i][j]=min(x,y);
		b[i][j]=max(x,y);
	}
	for(int i=1;i<=n;i++)
	for(int j=2;j<=m;j++)
	{
		if(a[i][j]<=a[i][j-1]||b[i][j]<=b[i][j-1])
		{
			printf("Impossible\n");
			return 0;
		}
	}
	for(int i=2;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j]<=a[i-1][j]||b[i][j]<=b[i-1][j])
		{
			printf("Impossible\n");
			return 0;
		}
	}
	printf("Possible\n");
	return 0;
}