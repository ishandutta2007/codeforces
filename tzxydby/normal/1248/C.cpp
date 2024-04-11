#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=1e9+7;
long long dp[N][2];
int main()
{
	long long n,m;
	cin>>n>>m;
	if(1)
	{
		dp[1][0]=2;
		for(int i=2;i<=max(n,m);i++)
		{
			dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
			dp[i][1]=dp[i-1][0];
		}
		cout<<(dp[n][0]+dp[n][1]+dp[m][0]+dp[m][1]-2)%mod<<endl;
	}
	return 0;
}