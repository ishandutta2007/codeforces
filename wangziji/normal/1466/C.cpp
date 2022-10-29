#include <iostream>
using namespace std;
int dp[100005][2][2];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int n=a.size();
		a=' '+a;
		for(int i=0;i<=n;i++)
			dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=1e9;
		dp[1][0][0]=0,dp[1][1][0]=1;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=1;j++)//i-2
			{
				for(int k=0;k<=1;k++)//i-1
				{
					for(int l=0;l<=1;l++)//i
					{
						if(!l&&!k&&a[i]==a[i-1]) continue;
						if(!l&&!j&&a[i]==a[i-2]) continue;
						dp[i][l][k]=min(dp[i][l][k],dp[i-1][k][j]+l); 
					}
				}
			}
		}
		cout << min(dp[n][0][0],min(dp[n][0][1],min(dp[n][1][0],dp[n][1][1]))) << "\n";
	}
	return 0;
}