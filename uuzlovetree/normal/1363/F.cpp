#include<bits/stdc++.h>
#define maxn 2005 
using namespace std;
int T,n;
int cs[maxn][30],ct[maxn][30];
char s[maxn],t[maxn];
int dp[maxn][maxn];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		memset(cs,0,sizeof(cs));
		memset(ct,0,sizeof(ct));
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)dp[i][j]=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<26;++j)cs[i][j]=cs[i-1][j];
			cs[i][s[i]-'a']++;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<26;++j)ct[i][j]=ct[i-1][j];
			ct[i][t[i]-'a']++;
		}
		bool yes=1;
		for(int i=0;i<26;++i)if(cs[n][i]!=ct[n][i])yes=0;
		if(!yes)
		{
			puts("-1");
		}
		else
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
					if(s[i]==t[j]&&i<=j)
					{
						bool ok=1;
						for(int k=0;k<26;++k)if(cs[i][k]>ct[j][k])ok=0; 
						if(ok)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
					}
				}
			}
			printf("%d\n",n-dp[n][n]);
		}
	}
}