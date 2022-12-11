#include<bits/stdc++.h>
using namespace std;
const int max_n=50+5;
char a[max_n],b[max_n];
bool dp[max_n][2];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d%s%s",&n,&m,a+1,b+1);
		if(n==m)
		{
			bool same=true;
			for(int i=1;i<=n;++i)
				same&=a[i]==b[i];
			puts(same?"YES":"NO");
			continue;
		}
		memset(dp,false,sizeof(dp));
		dp[1][a[1]^'0']=true;
		for(int i=2;i<=n-m+1;++i)
		{
			if(dp[i-1][0])
			{
				dp[i][0]=true;
				dp[i][a[i]^'0']=true; 
			}
			if(dp[i-1][1])
			{
				dp[i][1]=true;
				dp[i][a[i]^'0']=true;
			}
		}
		if(!dp[n-m+1][b[1]^'0'])
		{
			puts("NO");
			continue;
		}
		bool ans=true;
		for(int i=2;i<=m;++i)
			ans&=b[i]==a[n-m+i];
		puts(ans?"YES":"NO");
	}
	return 0;
}