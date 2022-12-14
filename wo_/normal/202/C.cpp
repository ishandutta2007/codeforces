#include<cstdio>

using namespace std;

int x;

int main()
{
	scanf("%d",&x);
	if(x==3)
	{
		printf("5\n");
		return 0;
	}
	for(int ans=1;;ans+=2)
	{
		int a=(ans-1)/2;
		int can=(a+1)*(a+1)+a*a;
		if(can>=x)
		{
			printf("%d\n",ans);
			return 0;
		}
	}
	return 0;
}