#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,k,a[200005],cnt[400005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=2*k;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n/2;i++)
		{
			cnt[1]+=2;
			cnt[min(a[i],a[n-i+1])+1]--;
			cnt[max(a[i],a[n-i+1])+k+1]++;
			cnt[a[i]+a[n-i+1]]--;
			cnt[a[i]+a[n-i+1]+1]++;
		}
		int ans=n;
		for(int i=1;i<=k*2;i++)
		{
			cnt[i]+=cnt[i-1];
			ans=min(ans,cnt[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}