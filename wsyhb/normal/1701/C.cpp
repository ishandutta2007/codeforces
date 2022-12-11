#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_n=2e5+5;
int cnt[max_n];
inline bool check(int t)
{
	long long rem=0;
	for(int i=1;i<=n;++i)
	{
		int c=cnt[i];
		int used=min(c,t);
		rem+=c-used;
		rem-=(t-used)>>1;
	}
	return rem<=0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			int a;
			scanf("%d",&a);
			++cnt[a];
		}
		int L=1,R=4e5,ans=4e5;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if(check(mid))
				ans=mid,R=mid-1;
			else
				L=mid+1;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)
			cnt[i]=0;
	}
	return 0;
}