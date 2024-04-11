#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,a[305][305];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		  for(int j=1;j<=m;j++)
		    scanf("%d",&a[i][j]);
		bool flag=1;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int v=4-(i==1)-(i==n)-(j==1)-(j==m);
			if(a[i][j]>v)
			{
				flag=0;
				break;
			}
			a[i][j]=v;
		}
		if(flag==0)printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				  printf("%d ",a[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}