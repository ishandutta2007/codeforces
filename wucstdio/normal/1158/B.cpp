#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	if(n==k)
	{
		for(int i=1;i<=n;i++)putchar('1');
		putchar('\n');
		return 0;
	}
	if(k==1)
	{
		putchar('1');
		for(int i=2;i<=n;i++)putchar('0');
		putchar('\n');
		return 0;
	}
	int num=(n-k)/2;
	num=min(num,k-2);
	if(num==k-2)
	{
		for(int i=1;i<=n-2*(k-1);i++)printf("0");
		printf("1");
		for(int i=1;i<=k-2;i++)printf("0");
		printf("1");
		for(int i=1;i<=k-2;i++)printf("0");
		printf("\n");
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(i%(num+1)==0)printf("1");
			else printf("0");
		}
		printf("\n");
		return 0;
	}
	return 0;
}