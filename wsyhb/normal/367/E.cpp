#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
int main()
{
	int n,m,x;
	scanf("%d%d%d",&n,&m,&x);
	if(n>m)
	{
		puts("0");
		return 0;
	}
	vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1)));
	dp[0][0][0]=1;
	for(int i=1;i<=m;++i)
		for(int j=0;j<=i-1&&j<=n;++j)
			for(int k=0;j+k<=i-1&&j+k<=n;++k)
			{
//				fprintf(stderr,"1 i-1=%d j=%d k=%d\n",i-1,j,k);
				int v=dp[i-1][j][k];
//				fprintf(stderr,"2 i-1=%d j=%d k=%d\n",i-1,j,k);
				if(v)
				{
					if(i!=x)
					{
						add(dp[i][j][k],v);
						if(j>0)
							add(dp[i][j-1][k+1],v);
					}
					if(j+k<n)
					{
						add(dp[i][j+1][k],v);
						add(dp[i][j][k+1],v);
					}
				}
//				fprintf(stderr,"3 i-1=%d j=%d k=%d\n",i-1,j,k);
			}
	int ans=dp[m][0][n];
	for(int i=1;i<=n;++i)
		ans=1ll*ans*i%mod;
	printf("%d\n",ans);
	return 0;
}