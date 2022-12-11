#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
struct Cave
{
	int k,need;
}c[max_n];
inline bool operator < (const Cave &a,const Cave &b)
{
	return a.need<b.need;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&c[i].k);
			c[i].need=0;
			for(int j=1;j<=c[i].k;++j)
			{
				int x;
				scanf("%d",&x);
				c[i].need=max(c[i].need,(x+1)-(j-1));
			}
		}
		sort(c+1,c+n+1);
		int ans=0,sum=0;
		for(int i=1;i<=n;++i)
		{
			ans=max(ans,c[i].need-sum);
			sum+=c[i].k;
		}
		printf("%d\n",ans);
	}
	return 0;
}