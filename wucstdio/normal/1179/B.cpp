#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n/2;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d %d\n",i,j);
			printf("%d %d\n",n-i+1,m-j+1);
		}
	}
	if(n&1)
	{
		for(int i=1;i<=m/2;i++)
		{
			printf("%d %d\n",n/2+1,i);
			printf("%d %d\n",n/2+1,m-i+1);
		}
		if(m&1)printf("%d %d\n",n/2+1,m/2+1);
	}
	return 0;
}