#include<bits/stdc++.h>
using namespace std;
const int max_R=3e4+5;
const int max_D=244+5;
int dp[max_R][max_D<<1],cnt[max_R];
inline void upd(int &a,int b)
{
	a=max(a,b);
}
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)
	{
		int p;
		scanf("%d",&p);
		++cnt[p];
	}
	const int R=3e4,D=244;
	for(int i=d;i<=R;++i)
		for(int j=max(0,D+1-d);j<=2*D;++j)
			dp[i][j]=-1e9;
	dp[d][D]=cnt[d];
	for(int i=d;i<=R;++i)
		for(int j=max(0,D+1-d);j<=2*D;++j)
		{
			int v=dp[i][j];
			if(v>=0)
			{
				int l=d-D+j;
				if(i+l-1<=R)
				{
					if(l>1)
					{
						assert(j>0);
						upd(dp[i+l-1][j-1],v+cnt[i+l-1]);
					}
					if(i+l<=R)
					{
						upd(dp[i+l][j],v+cnt[i+l]);
						if(i+l+1<=R)
						{
							assert(j+1<=2*D);
							upd(dp[i+l+1][j+1],v+cnt[i+l+1]);
						}
					}
				}
				else
					break;
			}
		}
	int ans=0;
	for(int i=d;i<=R;++i)
		for(int j=max(0,D+1-d);j<=2*D;++j)
			ans=max(ans,dp[i][j]);
	printf("%d\n",ans);
	return 0;
}