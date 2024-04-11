#include<bits/stdc++.h>
using namespace std;
const int max_n=5e3+5;
int p[max_n],cnt[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",p+i);
		long long ans=0;
		for(int b=1;b<=n;++b)
		{
			for(int i=1;i<=n;++i)
				cnt[i]=0;
			for(int a=1;a<b;++a)
				++cnt[p[a]];
			for(int i=1;i<=n;++i)
				cnt[i]+=cnt[i-1];
			int now=0;
			for(int d=b+1;d<=n;++d)
			{
				if(p[b]>p[d])
					ans+=now;
				now+=cnt[p[d]-1];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}