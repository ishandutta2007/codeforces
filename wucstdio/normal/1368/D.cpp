#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[200005],cnt[35];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=0;j<20;j++)
		  cnt[j]+=(bool)((1<<j)&a[i]);
		a[i]=0;
	}
	for(int i=0;i<20;i++)
	  for(int j=1;j<=cnt[i];j++)
	    a[j]|=1<<i;
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=1ll*a[i]*a[i];
	printf("%lld\n",ans);
	return 0;
}