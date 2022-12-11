#include<bits/stdc++.h>
using namespace std;
const int R=8192;
const int max_R=R+5;
int dp[max_R];
vector<int> pos[max_R];
int main()
{
	int n;
	scanf("%d",&n);
	dp[0]=0;
	for(int i=1;i<=R;++i)
		pos[i].push_back(0); 
	for(int i=1;i<=R;++i)
		dp[i]=R;
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		while(!pos[a].empty())
		{
			int x=pos[a].back();
			pos[a].pop_back();
			assert(dp[x]<a);
			if(dp[x^a]>a)
			{
				int b=dp[x^a];
				dp[x^a]=a;
				for(int j=b;j>=a+1;--j)
					pos[j].push_back(x^a);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=R;++i)
		ans+=dp[i]<R;
	printf("%d\n",ans);
	for(int i=0;i<=R;++i)
	{
		if(dp[i]<R)
			printf("%d ",i);
	}
	puts("");
	return 0;
}