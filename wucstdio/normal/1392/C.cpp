#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n,a[200005];
ll ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		ans=0;
		for(int i=2;i<=n;i++)ans+=max(a[i-1]-a[i],0);
		printf("%lld\n",ans);
	}
	return 0;
}