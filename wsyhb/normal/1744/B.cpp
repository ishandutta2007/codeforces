#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int cnt[2]={0,0};
		long long sum[2]={0,0};
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			++cnt[a&1];
			sum[a&1]+=a;
		}
		for(int i=1;i<=q;++i)
		{
			int type,x;
			scanf("%d%d",&type,&x);
			sum[type]+=1ll*cnt[type]*x;
			if(x&1)
			{
				cnt[type^1]+=cnt[type];
				sum[type^1]+=sum[type];
				cnt[type]=0,sum[type]=0;
			}
			printf("%lld\n",sum[0]+sum[1]);
		}
	}
	return 0;
}