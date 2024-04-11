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
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
		}
		printf("%d\n",3*n);
		for(int i=1;i<=n;i+=2)
		{
			int x=i,y=i+1;
			for(int j=1;j<=6;++j)
				printf("%d %d %d\n",j&1?1:2,x,y);
		}
	}
	return 0;
}