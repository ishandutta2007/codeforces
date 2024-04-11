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
		if(n&1)printf("7"),n-=3;
		n/=2;
		for(int i=1;i<=n;i++)printf("1");
		printf("\n");
	}
	return 0;
}