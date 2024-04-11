
#include "bits/stdc++.h"

using namespace std;

#pragma GCC optimize("Ofast")
typedef long long ll;

void io(const string s="") {
	if(s != "") {
		freopen((s+".in").c_str(), "r", stdin);
		freopen((s+".out").c_str(), "w", stdout);
	} else {
		ios_base::sync_with_stdio(false); cin.tie(0);
	}
}
ll pow(ll x, ll y) {
	if(y == 0)
		return 1;

	ll mid = pow(x, y / 2);
	if(y&1)
		return mid * mid * x;
	
	return mid * mid;
}
const int mxN = 2e5;

int a[mxN];
void solve() {
	int n, k;
	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}


	sort(a, a+n);
	if(k == 0) {
		if(a[0] == 1) {
			cout << -1;
		} else {
			cout << 1;
		}
		return;
	}
	for(int i = 0; i < n; i++) {
		int res = upper_bound(a, a+n, a[i]) - a;
		
		if(res == k) {
			cout << a[i] << "\n";
			return;
		}
	}

	cout << -1 << "\n";
}

int main() {
	
	
	io();
	int t = 1;
	// cin >> t;
	

	auto begin = std::chrono::high_resolution_clock::now();
	while(t--) solve();
	
	
	auto end = std::chrono::high_resolution_clock::now();
	cerr << setprecision(4) << fixed;
	cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	
}