#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[2005];
int dp[2005][2005];
int main()
{
	int t,n,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j<=n+1;j++)dp[i][j]=0;
		}
		for(int len=2;len<=n;len++)
		{
			for(int l=1;l<=n-len+1;l++)
			{
				int r=l+len-1;
				int maxn=-1,now;
				now=1;
				if(dp[l+2][r]==-1||dp[l+1][r-1]==-1)now=-1;
				if(dp[l+2][r]==0&&s[l+1]<s[l])now=-1;
				if(dp[l+2][r]==0&&s[l+1]==s[l])now=min(now,0);
				if(dp[l+1][r-1]==0&&s[r]<s[l])now=-1;
				if(dp[l+1][r-1]==0&&s[r]==s[l])now=min(now,0);
				maxn=max(maxn,now);
				now=1;
				if(dp[l][r-2]==-1||dp[l+1][r-1]==-1)now=-1;
				if(dp[l][r-2]==0&&s[r-1]<s[r])now=-1;
				if(dp[l][r-2]==0&&s[r-1]==s[r])now=min(now,0);
				if(dp[l+1][r-1]==0&&s[l]<s[r])now=-1;
				if(dp[l+1][r-1]==0&&s[l]==s[r])now=min(now,0);
				maxn=max(maxn,now);
				dp[l][r]=maxn;
			}
		}
		if(dp[1][n]==1)printf("Alice\n");
		else if(dp[1][n]==-1)printf("Bob\n");
		else printf("Draw\n");
	}
	return 0;
}