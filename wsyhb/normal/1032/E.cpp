#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
const int max_a=100+5;
const int max_w=1e4+5;
int cnt[max_a],dp[max_n][max_w];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		++cnt[a];
	}
	int cnt_kinds=0;
	for(int i=1;i<=100;++i)
		cnt_kinds+=cnt[i]>0;
	if(cnt_kinds==2)
	{
		printf("%d\n",n);
		return 0;
	}
	int w=0,c=0;
	dp[0][0]=1;
	for(int k=1;k<=100;++k)
	{
		if(!cnt[k])
			continue;
		w+=cnt[k]*k,c+=cnt[k];
		for(int i=c;i>=1;--i)
			for(int j=w;j>=k;--j)
				for(int x=1;x<=cnt[k];++x)
				{
					if(i>=x&&j>=x*k)
						dp[i][j]=min(dp[i][j]+dp[i-x][j-x*k],2);
				}
	}
	int ans=0;
	for(int i=1;i<=100;++i)
	{
		for(int j=cnt[i];j>=1;--j)
		{
			if(dp[j][j*i]==1)
			{
				ans=max(ans,j);
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}