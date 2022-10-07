#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll sum[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		sum[x-i+500000]+=x;
	}
	ll ans=0;
	for(int i=0;i<=1000000;i++)ans=max(ans,sum[i]);
	printf("%lld\n",ans);
	return 0;
}