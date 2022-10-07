#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
ll a[200005],k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		ll minn=1e18,maxx=-1e18;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			minn=min(minn,a[i]);
			maxx=max(maxx,a[i]);
		}
		if(k&1)
		{
			for(int i=1;i<=n;i++)
			  printf("%lld ",maxx-a[i]);
		}
		else
		{
			for(int i=1;i<=n;i++)
			  printf("%lld ",a[i]-minn);
		}
		printf("\n");
	}
	return 0;
}