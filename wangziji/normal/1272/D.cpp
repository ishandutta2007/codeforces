#include <iostream>
using namespace std;
int dp[200005][3],a[200005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1]) dp[i][0]=dp[i-1][0]+1,dp[i][1]=dp[i-1][1]+1;
		else dp[i][0]=1,dp[i][1]=1;
		if(i-1&&a[i]>a[i-2]) dp[i][1]=max(dp[i][1],dp[i-2][0]+1);
		ans=max(dp[i][0],max(dp[i][1],ans));
	}
	cout << ans;
	return 0;
}