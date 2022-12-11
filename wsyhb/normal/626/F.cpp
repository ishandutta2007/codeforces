#include<bits/stdc++.h>
using namespace std;
const int max_n=200+5;
const int max_k=1e3+5;
int a[max_n],dp[max_n][max_n][max_k];
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	dp[1][1][0]=dp[1][0][0]=1;
	for(int i=1;i<=n-1;++i)
		for(int j=0;j<=i;++j)
			for(int l=0;l<=k;++l)
			{
				int l_new=l+j*(a[i+1]-a[i]);
				if(l_new<=k)
				{
					int v=dp[i][j][l];
					if(v>0)
					{
						add(dp[i+1][j][l_new],v);
						add(dp[i+1][j+1][l_new],v);
						if(j>0)
						{
							v=1ll*v*j%mod;
							add(dp[i+1][j][l_new],v);
							add(dp[i+1][j-1][l_new],v);
						}
					}
				}
				else
					break;
			}
	int ans=0;
	for(int l=0;l<=k;++l)
		add(ans,dp[n][0][l]);
	printf("%d\n",ans);
	return 0;
}
/*
3 2
5 4 2
---
3
*/