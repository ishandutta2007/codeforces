#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
const LL mod=1e9+7;

LL dp[202][110][1005];
int T[202], n, k;

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
		scanf("%d", T+i);
	sort(T+1, T+1+n);
	dp[1][0][0]=1;
	dp[1][1][0]=1;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=n/2+1; j++)
		{
			for(int l=0; l<=k; l++)
			{
				int x=l+j*(T[i+1]-T[i]);
				if(x<=k)
				{
					dp[i+1][j][x]=(dp[i+1][j][x]+dp[i][j][l]*(LL)(j+1))%mod;
					if(j>0)
						dp[i+1][j-1][x]=(dp[i+1][j-1][x]+dp[i][j][l]*(LL)j)%mod;
					dp[i+1][j+1][x]=(dp[i+1][j+1][x]+dp[i][j][l])%mod;
				}
			}	
		}
	}
	LL res=0;
	for(int i=0; i<=k; i++)
	{
		res+=dp[n][0][i];
		res%=mod;
	}
	printf("%d\n", (int)res);
	return 0;
}