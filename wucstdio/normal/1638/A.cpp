#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,p[505];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&p[i]);
		int x=1;
		while(x<=n&&p[x]==x)x++;
		if(x>n)
		{
			for(int i=1;i<=n;i++)printf("%d ",p[i]);
			printf("\n");
		}
		else
		{
			int y=x;
			while(p[y]!=x)y++;
			for(int i=1;i<x;i++)printf("%d ",p[i]);
			for(int i=y;i>=x;i--)printf("%d ",p[i]);
			for(int i=y+1;i<=n;i++)printf("%d ",p[i]);
			printf("\n");
		}
	}
	return 0;
}