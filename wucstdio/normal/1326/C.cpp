#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,k,p[200005];
ll ans=1;
int main()
{
	scanf("%d%d",&n,&k);
	int last=0;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if(p[i]>=n-k+1)
		{
			if(last)ans*=i-last;
			ans%=MOD;
			last=i;
			sum+=p[i];
		}
	}
	printf("%lld %lld\n",sum,ans);
	return 0;
}