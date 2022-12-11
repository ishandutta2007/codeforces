#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		int ans=a[n]-a[1]+max(a[n]-a[n-1],a[2]-a[1]);
		for(int i=1;i<=n-2;++i)
			ans=max(ans,-2*a[i]+a[i+1]+a[n]);
		for(int i=n;i>=3;--i)
			ans=max(ans,2*a[i]-a[i-1]-a[1]);
		printf("%d\n",ans);
	}
	return 0;
}