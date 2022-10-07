#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1&&m==1)
	{
		printf("0\n");
		return 0;
	}
	if(n==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=n+1;j<=n+m;j++)
			  printf("%d ",i*j);
			printf("\n");
		}
	}
	else
	{
		for(int i=m+1;i<=n+m;i++)
		{
			for(int j=1;j<=m;j++)
			  printf("%d ",i*j);
			printf("\n");
		}
	}
	return 0;
}