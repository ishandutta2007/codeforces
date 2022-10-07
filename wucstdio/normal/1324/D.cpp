#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[200005];
ll ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]-=x;
	}
	sort(a+1,a+n+1);
	int pre=n;
	for(int i=1;i<=n;i++)
	{
		while(pre>0&&a[pre]+a[i]>0)pre--;
		ans+=n-max(i,pre);
	}
	printf("%lld\n",ans);
	return 0;
}