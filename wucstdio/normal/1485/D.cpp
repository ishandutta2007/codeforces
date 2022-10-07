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
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i+j)&1)printf("720720 ");
			else printf("%d ",720720-a[i][j]*a[i][j]*a[i][j]*a[i][j]);
		}
		printf("\n");
	}
	return 0;
}