#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		long long l=1,ans=0;
		const int mod=1e9+7;
		for(int i=1;l<=n;++i)
		{
			l=l/gcd(l,i)*i;
			long long cnt=n/l;
			long long d=gcd(l,i+1),v=(i+1)/d;
			ans=(ans+(cnt-cnt/v)*(i+1))%mod;
		}
		printf("%lld\n",ans);
	}
    return 0;
}