#include<bits/stdc++.h>
#define maxn 205
using namespace std;
int T;
char s[maxn],t[maxn],p[maxn];
int dp[maxn][maxn];
int c[30];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s%s",s+1,t+1,p+1);
		int n=strlen(s+1),m=strlen(t+1);
		memset(dp,0,sizeof(dp));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				dp[i][j]=max(max(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]+(s[i]==t[j]));
			}
		if(dp[n][m]!=n)
		{
			puts("NO");
			continue;
		}
		for(int i=1;i<=m;++i)c[t[i]-'a']++;
		for(int i=1;i<=n;++i)c[s[i]-'a']--;
		int lp=strlen(p+1);
		for(int i=1;i<=lp;++i)c[p[i]-'a']--;
		bool yes=1;
		for(int i=0;i<26;++i)if(c[i]>0)
		{
			yes=0;break;
		}
		if(yes)puts("YES");
		else puts("NO");
	}
}