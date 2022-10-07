#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,c[2];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		c[0]=c[1]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			c[x&1]=1;
		}
		if(!c[1])puts("NO");
		else if(!c[0]&&n%2==0)puts("NO");
		else puts("YES");
	}
	return 0;
}