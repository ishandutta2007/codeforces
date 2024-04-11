#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	static int a[103];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	static int dp[103][3];
	for(int i=0;i<n;i++) {
		dp[i+1][0] = max(dp[i][0],max(dp[i][1],dp[i][2]));
		dp[i+1][1] = a[i]&1 ? max(dp[i][0],dp[i][2])+1 : 0;
		dp[i+1][2] = a[i]&2 ? max(dp[i][0],dp[i][1])+1 : 0;
	}
	cout<<n-max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}