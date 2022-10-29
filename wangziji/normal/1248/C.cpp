#include <iostream>
#define mod 1000000007
#define int long long
using namespace std;
int dp[100005][3];
signed main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	dp[1][1]=2;
	if(n<m)
		swap(n,m);
	for(int i=2;i<=n;i++)
	{
		dp[i][1]+=dp[i-1][2]+dp[i-1][1];
		dp[i][2]+=dp[i-1][1];
		dp[i][1]%=mod;
		dp[i][2]%=mod; 
	}
	cout << (dp[n][1]+dp[n][2]-2+dp[m][1]+dp[m][2]+mod)%mod << endl;
	return 0;
}