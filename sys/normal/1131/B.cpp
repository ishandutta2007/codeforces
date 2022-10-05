#include <bits/stdc++.h>
using namespace std;
int n,a,b;
long long ans=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if((x!=a||y!=b)&&min(x,y)-max(a,b)>=0)
			ans+=min(x,y)-max(a,b)+1-(a==b);
		a=x,b=y;
	}
	printf("%lld\n",ans);
	return 0;
}