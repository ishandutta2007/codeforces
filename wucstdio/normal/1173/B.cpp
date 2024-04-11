#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int main()
{
	scanf("%d",&n);
	printf("%d\n",m=n/2+1);
	for(int i=1;i<=n;i++)
	{
		if(i<=m)printf("1 %d\n",i);
		else printf("%d %d\n",i-m+1,m);
	}
	return 0;
}