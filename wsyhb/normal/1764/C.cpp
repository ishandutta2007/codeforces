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
		if(a[1]==a[n])
		{
			printf("%d\n",n/2);
			continue;
		}
		long long ans=0;
		for(int i=1;i+1<=n;++i)
		{
			if(a[i]!=a[i+1])
				ans=max(ans,1ll*i*(n-i));
		}
		printf("%lld\n",ans);
	}
	return 0;
}