#include <bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> cnt;
const int N=200050;
int a[N];
int main()
{
	int n,k,i,xo,all;
	scanf("%i %i",&n,&k);all=(1<<k)-1;
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	cnt[0]++;xo=0;
	int pre=0;
	for(i=1;i<=n;i++)
	{
		pre^=a[i];
        if(cnt[pre]>cnt[pre^all])
		{
			pre^=all;
			a[i]^=all;
		}
		cnt[pre]++;
	}
	cnt.clear();
	cnt[0]=1;
	ll sol=0;
	pre=0;
	for(i=1;i<=n;i++)
	{
		pre^=a[i];
        sol+=cnt[pre];
        cnt[pre]++;
	}
	ll ans=(ll)n*(n+1)/2-sol;
	printf("%lld\n",ans);
	return 0;
}