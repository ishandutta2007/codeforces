#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
const int max_n=60+5;
int dp[max_n][max_n][max_n][3];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		dp[n+1][0][0][2]=1;
		for(int i=n;i>=1;--i)
			for(int x=0;x<=n/2;++x)
				for(int y=0;y<=n/2;++y)
				{
					for(int t=0;t<=1;++t)
					{
						int v=dp[i+1][x][y][t];
						add(dp[i][x+1][y][t],v);
						add(dp[i][x][y+1][t],v);
					}
					int v=dp[i+1][x][y][2],nxt;
					if(x+1>y&&(x+1)%2)
						nxt=0;
					else
						nxt=2;
					add(dp[i][x+1][y][nxt],v);
					if(y+1>x&&(y+1)%2==0)
						nxt=1;
					else
						nxt=2;
					add(dp[i][x][y+1][nxt],v);
				}
		printf("%d %d %d\n",dp[1][n>>1][n>>1][0],dp[1][n>>1][n>>1][1],dp[1][n>>1][n>>1][2]);
	}
	return 0;
}