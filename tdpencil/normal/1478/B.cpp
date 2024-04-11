#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
#define pb push_back
// ll m, k, x, y;

// string s;
ll n, m,k;
const int mxN = 3e5+1;
const int M = 1e9+7;
void solve() {
	int q, d;
	cin >> q >> d;

	vector<int> dp(15*d);

	dp[0]=1;
	for(int i = 1; i < 14*d; i++) {
		for(int j = d; i - j >= 0; j += 10) {
			dp[i]|=dp[i-j];
		}
	}


	while(q--) {
		int x; cin >> x;
		if(x>10*d) {
			cout << "YES\n";
		} else if(dp[x]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
int main() {
	// prec();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t = 1; cin >> t;
	for(int case_num = 1; case_num <= t; case_num++) {
		//cout << "Case #" << case_num << ": ";
		solve();
	}
}