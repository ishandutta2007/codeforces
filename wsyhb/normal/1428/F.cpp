#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5;
char s[max_n];
int cnt[max_n];
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	long long ans=0,sum=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')
		{
			++cnt[0];
			ans+=sum;
			continue;
		}
		int j=i;
		while(j+1<=n&&s[j+1]=='1')
			++j;
		int k=j-i+1;
		for(int t=1;t<=k;++t)
		{
			sum+=cnt[t-1];
			cnt[t]+=cnt[t-1];
			cnt[t-1]=0;
			ans+=sum+(t*(t+1ll)>>1);
		}
		sum+=k*(k+1ll)>>1;
		for(int t=1;t<=k;++t)
			++cnt[t];
		i=j;
	}
	printf("%lld\n",ans);
	return 0;
}