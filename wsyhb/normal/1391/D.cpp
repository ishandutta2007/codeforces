#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
using namespace std;
const int N=1e6+5;
int a[4][N];
char s[N];
int dp[8][N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>=4&&m>=4)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(n<=3) a[i][j]=s[j]-'0';
			else a[j][i]=s[j]-'0';
		}
	}
	if(n>3) swap(n,m);
	if(n==1) printf("0");
	else if(n==2)
	{
		for(int j=1;j<=m;j++)
			for(int i=0;i<4;i++)
				dp[i][j]=min(dp[i^1][j-1],dp[i^2][j-1])+((i&1)^a[2][j])+(((i>>1)&1)^a[1][j]);
		int ans=1e9;
		for(int i=0;i<4;i++) ans=min(ans,dp[i][m]);
		printf("%d",ans);
	}
	else
	{
		for(int j=1;j<=m;j++)
			for(int i=0;i<8;i++)
			{
				dp[i][j]=1e9;
				for(int k=0;k<8;k++)
					if((((i^k)&3)==1||((i^k)&3)==2)&&(((i^k)>>1)==1||((i^k)>>1)==2)) dp[i][j]=min(dp[i][j],dp[k][j-1]);
				dp[i][j]+=((i&1)^a[3][j])+(((i>>1)&1)^a[2][j])+(((i>>2)&1)^a[1][j]);
			}
		int ans=1e9;
		for(int i=0;i<8;i++) ans=min(ans,dp[i][m]);
		printf("%d",ans);
	}
	return 0;
}