#include <iostream>
#define int long long
using namespace std;
int dp[200005][2],a[200005],b[200005];
signed main(int argc, char** argv) {
	int n,c;
	cin >> n >> c;
	--n;
	cout << "0 ";
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		dp[i][0]=dp[i][1]=2927;
	}
	for(int i=1;i<=n;i++)
		cin >> b[i];
	dp[0][1]=2927;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0]+a[i],dp[i-1][1]+a[i]);
		dp[i][1]=min(dp[i-1][1]+b[i],dp[i-1][0]+c+b[i]);
		cout << min(dp[i][0],dp[i][1]) << " ";
	}
	return 0;
}