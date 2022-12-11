#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
char s[max_n];
int a[max_n],sum[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;++i)
		{
			a[i]=(s[i]^'0')-1;
			sum[i]=sum[i-1]+a[i];
		}
		map<int,int> cnt;
		++cnt[0];
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			ans+=cnt[sum[i]];
			++cnt[sum[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}