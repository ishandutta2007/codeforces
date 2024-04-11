#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define mod 1000000007
using namespace std;
int a[500005],cnt[100];
signed main(int argc, char** argv) {
	int T;
	scanf("%lld",&T);
	while(T--)
	{
		int n;
		scanf("%lld",&n);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			for(int j=0;j<62;j++)
				if(a[i]&((int)1<<j)) ++cnt[j];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int And=0,Or=0;
			for(int j=0;j<62;j++)
			{
				if(a[i]&((int)1<<j))
				{
					Or+=n*(((int)1<<j)%mod)%mod;
					Or%=mod;
					And+=cnt[j]*(((int)1<<j)%mod)%mod;
					And%=mod;
				}
				else
				{
					Or+=cnt[j]*(((int)1<<j)%mod)%mod;
					Or%=mod;
				}
			}
			ans=(ans+And*Or)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}