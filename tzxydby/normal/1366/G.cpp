#include<bits/stdc++.h>
using namespace std;
const int N=10005;
char s[N],t[N];
int dp[N][N],n,m;
void chmin(int &a,int b){if(a>b)a=b;}
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j]=1e9;
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			chmin(dp[i+1][j],dp[i][j]+1);
			if(j<m&&s[i+1]==t[j+1])
				chmin(dp[i+1][j+1],dp[i][j]);
		}
		int p=i+1,b=0;
		if(s[i+1]!='.')
		{
			while(p<=n)
			{
				if(s[p]!='.')
					b++;
				else
					b--;
				if(b==0)
					break;
				p++;
			}
			for(int j=0;j<=m;j++)
				chmin(dp[p][j],dp[i][j]);
		}
	}
	printf("%d\n",dp[n][m]);
	return 0;
}