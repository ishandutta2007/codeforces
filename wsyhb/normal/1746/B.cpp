#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],sum[max_n];
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
			scanf("%d",a+i);
			sum[i]=sum[i-1]+a[i];
		}
		int ans=1e9;
		for(int i=1;i<=n+1;++i)
		{
			int x=sum[i-1];
			int y=n-i+1-(sum[n]-sum[i-1]);
			ans=min(ans,max(x,y));
		}
		printf("%d\n",ans);
	}
	return 0;
}