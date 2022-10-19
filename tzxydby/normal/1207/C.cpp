#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long dp[N][2];
string s;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long n,x,y;
		cin>>n>>x>>y;
		cin>>s;
		for(int i=0;i<=n;i++)
			dp[i][0]=dp[i][1]=1e18;
		dp[0][0]=y;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
			{	
				dp[i][1]=min(dp[i-1][1]+2*y+x,dp[i-1][0]+2*y+2*x);
				dp[i][0]=min(dp[i-1][1]+y+2*x,dp[i-1][0]+y+x);
			}
			else
				dp[i][1]=dp[i-1][1]+2*y+x;
		}	
		cout<<dp[n][0]<<endl;
	} 
	return 0;
}