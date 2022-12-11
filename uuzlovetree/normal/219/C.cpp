#include<bits/stdc++.h>
#define maxn 500005
using namespace std;
int n,m;
char s[maxn];
int dp[maxn][26],pre[maxn][26];
void print(int x,int c)
{
	if(!x)return;
	print(x-1,pre[x][c]);
	printf("%c",c+'A');
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	memset(dp,127/2,sizeof(dp));
	for(int j=0;j<26;++j)dp[1][j]=(s[1]!=j+'A');
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<m;++j)
		{
			for(int k=0;k<m;++k)if(j!=k)
			{
				if(s[i]!=j+'A')
				{
					if(dp[i][j]>dp[i-1][k]+1)dp[i][j]=dp[i-1][k]+1,pre[i][j]=k;
				}
				else
				{
					if(dp[i][j]>dp[i-1][k])dp[i][j]=dp[i-1][k],pre[i][j]=k;
				}
			}
		}
	}
	int ans=n+1,id=0;
	for(int j=0;j<m;++j)if(ans>dp[n][j])ans=dp[n][j],id=j;
	printf("%d\n",ans);
	print(n,id);
	return 0;
}