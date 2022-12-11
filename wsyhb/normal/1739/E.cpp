#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
char s[3][max_n];
int dp[max_n][4][2];
inline void upd(int &a,int b)
{
	a=max(a,b);
}
int main()
{
	int n;
	scanf("%d%s%s",&n,s[1]+1,s[2]+1);
	s[1][0]=s[2][0]=s[1][n+1]=s[2][n+1]='0';
	memset(dp,128,sizeof(dp));
	dp[n+1][0][0]=dp[n+1][0][1]=0;
	for(int i=n;i>=0;--i)
	{
		for(int t=0;t<=1;++t)
			for(int S=0;S<4;++S)
				dp[i][0][t]=max(dp[i][0][t],dp[i+1][S][t]);
		for(int S=0;S<4;++S)
		{
			if(~S>>1&1)
				upd(dp[i][1][0],dp[i+1][S][1]+1);
			upd(dp[i][1][1],dp[i+1][S][1]+1);
		}
		for(int S=0;S<4;++S)
		{
			upd(dp[i][2][0],dp[i+1][S][0]+1);
			if(~S&1)
				upd(dp[i][2][1],dp[i+1][S][0]+1);
		}
		for(int S=0;S<4;++S)
		{
			if(~S>>1&1)
				upd(dp[i][3][0],dp[i+1][S][1]+2);
			if(~S&1)
				upd(dp[i][3][1],dp[i+1][S][0]+2);
		}
		int val=(s[1][i]^'0')<<1|(s[2][i]^'0');
		for(int S=0;S<4;++S)
			for(int t=0;t<=1;++t)
			{
				if((S&val)!=S)
					dp[i][S][t]=-1e9;
			}
	}
	printf("%d\n",dp[0][0][0]);
	return 0;
}