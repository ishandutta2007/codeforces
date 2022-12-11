#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;++i)
		{
			int x;
			scanf("%d",&x);
			x?++cnt1:++cnt0;
		}
		if(cnt0>=(n>>1))
		{
			printf("%d\n",n>>1);
			for(int i=1;i<=(n>>1);++i)
				printf("%d%c",0,i<(n>>1)?' ':'\n');
		}
		else
		{
			if((n>>1)&1)
			{
				printf("%d\n",(n>>1)+1);
				for(int i=1;i<=(n>>1)+1;++i)
					printf("%d%c",1,i<=(n>>1)?' ':'\n');
			}
			else
			{
				printf("%d\n",n>>1);
				for(int i=1;i<=(n>>1);++i)
					printf("%d%c",1,i<(n>>1)?' ':'\n');
			}
		}
	}
	return 0;
}