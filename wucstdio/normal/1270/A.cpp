#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		int max1=0,max2=0;
		for(int i=1;i<=a;i++)
		{
			int x;
			scanf("%d",&x);
			max1=max(max1,x);
		}
		for(int i=1;i<=b;i++)
		{
			int x;
			scanf("%d",&x);
			max2=max(max2,x);
		}
		if(max1>max2)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}