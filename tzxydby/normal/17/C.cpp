#include<bits/stdc++.h>
using namespace std;
const int N=155,M=55,mod=51123987;
int dp[N][M][M][M],nxt[N][3];
char s[N];
inline void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int j=0;j<3;j++)
		nxt[n+1][j]=n+1;
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<3;j++)
		{
			nxt[i][j]=nxt[i+1][j];
			if(s[i]=='a'+j)
				nxt[i][j]=i;
		}
	}
	int ma=(n+2)/3,ans=0;
	dp[1][0][0][0]=1;
	for(int t=1;t<=n;t++)
	{
		for(int i=0;i<=ma;i++)
		{
			for(int j=0;j<=ma;j++)
			{
				for(int k=0;k<=ma;k++)
				{
					if(i+j+k==n&&abs(i-j)<=1&&abs(j-k)<=1&&abs(k-i)<=1)
					{
						add(ans,dp[t][i][j][k]);
						continue;
					}
					if(nxt[t][0]<=n) add(dp[nxt[t][0]][i+1][j][k],dp[t][i][j][k]);	
					if(nxt[t][1]<=n) add(dp[nxt[t][1]][i][j+1][k],dp[t][i][j][k]);
					if(nxt[t][2]<=n) add(dp[nxt[t][2]][i][j][k+1],dp[t][i][j][k]);
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}