#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n],cnt[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			cnt[i]=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			++cnt[a[i]];
		}
		int ans_x=1,ans_y=n;
		for(int x=1,y=0,tot=0;x<=n;++x)
		{
			while(tot-(n-tot)<k&&y+1<=n)
				tot+=cnt[++y];
			assert(y>=x);
			if(tot-(n-tot)<k)
				break;
			if(y-x<ans_y-ans_x)
				ans_x=x,ans_y=y;
			tot-=cnt[x];
		}
		printf("%d %d\n",ans_x,ans_y);
		int tot=0;
		for(int i=1;i<=n;++i)
		{
			if(tot==k-1)
			{
				printf("%d %d\n",i,n);
				break;
			}
			int now=0;
			for(int j=i;j<=n;++j)
			{
				if(a[j]>=ans_x&&a[j]<=ans_y)
					++now;
				else
					--now;
				if(now==1)
				{
					printf("%d %d\n",i,j);
					i=j;
					++tot;
					break;
				}
			}
		}
		assert(tot==k-1);
	}
	return 0;
}