#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vt vector
// ll m, k, x, y;

// string s;
ll n, m, q;
const int mxN = 3e5+1;
const int M = 1e9+7;
// int a[mxN+1];
// ll b[mxN+1];
// ll dp[mxN+1];
bool vis[mxN];
const ll NF=-1e18;
// set<ll> s;

void solve3(int p) {
	if(p&1) {
		cout << 1 << " " << (p>>1) << " " << (p>>1) << "\n";
	} else if(p%2 == 0 && p % 4) {
		cout << 2 << " " << (p>>1)-1 << " " << (p>>1)-1 << "\n";
	} else {
		cout << (p>>1) << " " << (p>>2) << " " << (p>>2) << "\n";
	}
}

void solve() {
	cin >> n >> m;

	for(int i=0;i<m-3;i++) {
		cout << 1 << " ";
	}

	solve3(n-(m-3));

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