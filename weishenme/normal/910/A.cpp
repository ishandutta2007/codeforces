#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,dp[N];
char s[N];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",&s);
	memset(dp,-1,sizeof dp);
	dp[0]=0;
	for (int i=0;i<n;i++)
	 if (dp[i]!=-1)for (int j=1;j<=m;j++)
	  if (i+j<n&&s[i+j]!='0'&&(dp[i+j]==-1||dp[i+j]>dp[i]+1))
	   dp[i+j]=dp[i]+1;
	printf("%d",dp[n-1]);   
}