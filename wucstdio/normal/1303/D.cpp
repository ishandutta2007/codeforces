#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll n,m,a[100005],cnt[105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		memset(cnt,0,sizeof(cnt));
		ll s=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&a[i]);
			s+=a[i];
			ll v=a[i],x=0;
			while(v)x++,v/=2;
			cnt[x-1]++;
		}
		if(s<n)
		{
			puts("-1");
			continue;
		}
		int last=-1,ans=0;
		for(int i=0;i<=60;i++)
		{
			if((1ll<<i)&n)
			{
				if(!cnt[i])
				{
					if(last==-1)last=i;
				}
				else cnt[i]--;
			}
			if(cnt[i]&&last!=-1)
			{
				ans+=i-last;
				cnt[i]--;
				last=-1;
			}
			cnt[i+1]+=cnt[i]/2;
		}
		printf("%d\n",ans);
	}
	return 0;
}