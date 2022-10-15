#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=4e3;
int n, k, t[mxN+1], d[mxN+1], dp[mxN+1], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for(int i=0; i<n; ++i)
		cin >> t[i] >> d[i];
	t[n]=86401;
	for(int i=0; i<=n; ++i) {
		ans=max(t[i]-dp[k]-1, ans);
		for(int j=k; ~j; --j) {
			dp[j]=max(dp[j], t[i]-1)+d[i];
			if(j)
				dp[j]=min(dp[j-1], dp[j]);
		}
	}
	cout << ans;
}