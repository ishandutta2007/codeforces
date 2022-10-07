#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll ans,sum,n;
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%I64d",&x);
		ans=max(ans,x);
		sum+=x;
	}
	ans=max(ans,(sum-1)/(n-1)+1);
	printf("%I64d\n",ans);
	return 0;
}