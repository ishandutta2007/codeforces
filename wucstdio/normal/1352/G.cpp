#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<=3)
		{
			printf("-1\n");
			continue;
		}
		if(n==4)
		{
			printf("3 1 4 2\n");
			continue;
		}
		if(n==5)
		{
			printf("2 4 1 3 5\n");
			continue;
		}
		if(n%2==1)
		{
			for(int i=1;i<=n;i+=2)printf("%d ",i);
			printf("%d %d ",n-3,n-1);
			for(int i=n-5;i>=1;i-=2)printf("%d ",i);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=n;i+=2)printf("%d ",i);
			printf("%d %d %d ",n-4,n,n-2);
			for(int i=n-6;i>=1;i-=2)printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}