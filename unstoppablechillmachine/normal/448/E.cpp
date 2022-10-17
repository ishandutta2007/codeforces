#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

map<int, vector<int>> mp;
vector<int> ans, d1, d2;

void out() {
	for (auto it : ans) {
		cout << it << ' ';
	}
	cout << '\n';
	exit(0);
}

void solve(int n, int m) {
	if (n == 1 || m == 0) {
		ans.pb(n);
		if (SZ(ans) == 1e5) {
			out();
		}
		return;
	}
	if (mp.find(n) == mp.end()) {
		for (int i = 0; i < SZ(d1); i++) {
			if (d1[i] > n) {
				break;
			}
			if (n % d1[i] == 0) {
				mp[n].pb(d1[i]);
			}
		}
	}
	for (auto it : mp[n]) {
		solve(it, m - 1);
	}	
}

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			d1.pb(i);
			if (i != n / i) {
				d2.pb(n / i);
			}
		}
	}
	while (!d2.empty()) {
		d1.pb(d2.back());
		d2.pop_back();
	}
	mp[n] = d1;
	solve(n, m);
	out();
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}