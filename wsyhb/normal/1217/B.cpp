#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int mx=100+5;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,d,h,Max=0,Max1=-2e9,ans;
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&d,&h);
			Max=max(Max,d);
			Max1=max(Max1,d-h);
		}
		if(Max>=x)
		{
			printf("1\n");
			continue;
		}
		if(Max1<=0)
		{
			printf("-1\n");
			continue;
		}
		ans=(x-Max)/Max1+((x-Max)%Max1?1:0)+1;
		printf("%d\n",ans);
	}
	return 0;
}