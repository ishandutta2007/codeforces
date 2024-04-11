#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1&&j==1)putchar('W');
				else putchar('B');
			}
			putchar('\n');
		}
	}
	return 0;
}