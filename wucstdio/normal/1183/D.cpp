#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n,cnt[200005];
ll ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			cnt[x]++;
		}
		sort(cnt+1,cnt+n+1);
		int now=1000000000;
		ans=0;
		for(int i=n;i>=1;i--)
		{
			now--;
			now=min(now,cnt[i]);
			if(now==0)break;
			ans+=now;
		}
		printf("%I64d\n",ans);
		for(int i=1;i<=n;i++)cnt[i]=0;
	}
	return 0;
}