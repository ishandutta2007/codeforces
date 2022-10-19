#include<bits/stdc++.h>
using namespace std;
#define INF 1<<29
vector<int>v;
int sum[6000],dp[6000];
char buf[10010];
string s;
int main()
{
	int m;
	scanf("%d",&m);
	gets(buf);
	gets(buf);
	s=buf;
	int pre=-2;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='.'||s[i]=='?'||s[i]=='!')
		{
			int tmp=i-pre-1;
			v.push_back(tmp);
			pre=i;
		}
	}
	int n=v.size();
	for(int i=0;i<n;i++)
		sum[i+1]=sum[i]+v[i];
	for(int i=0;i<=n;i++)
		dp[i]=INF;
	dp[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			if(sum[i]-sum[j]+(i-j-1)<=m)
				dp[i]=min(dp[i],dp[j]+1);
	if(dp[n]==INF)
		printf("Impossible\n");
	else
		printf("%d\n",dp[n]);
	return 0;
}