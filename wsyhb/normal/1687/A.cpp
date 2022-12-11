#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
long long sum[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			sum[i]=sum[i-1]+(a[i]-1);
		}
		long long ans=0;
		for(int i=1;i<=n;++i)
			ans=max(ans,sum[i]-sum[max(i-k,0)]);
		if(k>=n)
			ans+=(2*k-n+1ll)*n/2;
		else
			ans+=k*(k+1ll)/2;
		printf("%lld\n",ans);
	}
	return 0;
}