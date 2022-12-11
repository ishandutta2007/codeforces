#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,k;
char s[maxn];
int val[maxn];
int c[30],num;
int dp[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int l=1;l<=k;++l)
	{
		int t=s[l]-'a';
		if(!c[t])num++;
		c[t]++;
	}
	for(int r=k;r<=n;++r)
	{
		if(num==1)val[r]=1;
		int l=r-k+1;
		if(c[s[l]-'a']==1)num--;
		c[s[l]-'a']--;
		if(r!=n)
		{
			if(!c[s[r+1]-'a'])num++;
			c[s[r+1]-'a']++;
		}
	}
	int ans=0;
	for(int p=0;p<26;++p)
	{
		for(int i=k;i<=n;++i)
		{
			dp[i]=dp[i-1];
			if(s[i]-'a'==p&&dp[i]<dp[i-k]+val[i])dp[i]=dp[i-k]+val[i];
		}
		ans=max(ans,dp[n]);
	}
	printf("%d\n",ans);
	return 0;
}