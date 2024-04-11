#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int n,a[mxN];
long long dp[mxN];
map<int,int> cnt;

int main() {
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> a[i], ++cnt[a[i]];
	dp[1]=cnt[1];
	for(int i=2; i<mxN; ++i)
		dp[i]=max(dp[i-1],dp[i-2]+(long long)cnt[i]*i);
	cout << dp[mxN-1];		
	return 0;
}