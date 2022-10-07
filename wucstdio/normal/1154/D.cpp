#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,maxb;
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	maxb=b;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			if(a&&b!=maxb)a--,b++;
			else if(b)b--;
			else if(a)a--;
			else
			{
				printf("%d\n",i-1);
				return 0;
			}
		}
		else
		{
			if(b)b--;
			else if(a)a--;
			else
			{
				printf("%d\n",i-1);
				return 0;
			}
		}
	}
	printf("%d\n",n);
	return 0;
}