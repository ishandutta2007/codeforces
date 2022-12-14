#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int x,y,a,b;
	scanf("%d%d%d%d",&x,&y,&a,&b);
	int ans=0;
	for(int i=a;i<=x;i++)
	{
		ans+=max(0,min(i-1,y)-b+1);
	}
	printf("%d\n",ans);
	for(int i=a;i<=x;i++)
	{
		for(int j=b;j<=min(i-1,y);j++)
		{
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}