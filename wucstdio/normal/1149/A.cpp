#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n==1)
	{
		printf("%d\n",a[1]);
		return 0;
	}
	int num=0;
	for(int i=1;i<=n;i++)
	  if(a[i]==2)num++;
	if(!num)
	{
		while(n--)printf("1 ");
		printf("\n");
		return 0;
	}
	else if(num==n)
	{
		while(n--)printf("2 ");
		printf("\n");
		return 0;
	}
	else
	{
		printf("2 1 ");
		num--;
		for(int i=1;i<=num;i++)printf("2 ");
		for(int i=1;i<=n-num-2;i++)printf("1 ");
		printf("\n");
		return 0;
	}
	return 0;
}