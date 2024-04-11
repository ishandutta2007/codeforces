#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[505][505];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	for(int i=1;i<=n+1;i++)a[i][m+1]=10000;
	for(int i=1;i<=m+1;i++)a[n+1][i]=10000;
	for(int i=n;i>=1;i--)
	for(int j=m;j>=1;j--)
	{
		if(a[i][j]>=a[i+1][j]||a[i][j]>=a[i][j+1])
		{
			printf("-1\n");
			return 0;
		}
		if(a[i][j]==0)a[i][j]=min(a[i+1][j],a[i][j+1])-1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    ans+=a[i][j];
	printf("%d\n",ans);
	return 0;
}