#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,a[1000005],num;
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<(1<<n);i++)
	{
		if((i^x)<i)continue;
		a[++num]=i;
	}
	printf("%d\n",num);
	for(int i=1;i<=num;i++)printf("%d ",a[i]^a[i-1]);
	printf("\n");
	return 0;
}