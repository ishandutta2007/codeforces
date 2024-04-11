#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n,a[5005],cnt[5005];
ll ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)cnt[i]=0;
		ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			ans+=max(0,a[i]-cnt[i]-1);
			if(cnt[i]>a[i]-1)cnt[i+1]+=cnt[i]-a[i]+1;
			a[i]=min(a[i],n-i);
			for(int j=i+a[i];j>i+1;j--)cnt[j]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}