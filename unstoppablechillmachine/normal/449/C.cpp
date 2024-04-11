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

const int N = 1e5 + 10;
bool used[N];
vector<int> hh[N];

bool prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

signed main() {
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		if (prime(i)) {
			for (int j = 1; i * j <= n; j++) {
				hh[i].pb(i * j);
			}
		}
	}
	vector<int> cur;
	vector<pair<int, int>> ans;
	for (int i = 3; i <= n; i++) {
		cur = {};
		for (auto it : hh[i]) {
			if (!used[it]) {
				cur.pb(it);
			}
		}
		if (SZ(cur) <= 1) {
			continue;
		}
		if (SZ(cur) & 1) {
			ans.pb({cur[0], cur[2]});
			used[cur[0]] = true;
			used[cur[2]] = true;
			for (int i = 3; i + 1 < SZ(cur); i += 2) {
				ans.pb({cur[i], cur[i + 1]});
				used[cur[i]] = used[cur[i + 1]] = true;
			}
		}
		else {
			for (int i = 0; i + 1 < SZ(cur); i += 2) {
				ans.pb({cur[i], cur[i + 1]});
				used[cur[i]] = used[cur[i + 1]] = true;
			}
		}
	}
	cur = {};
	for (int i = 2; i <= n; i += 2) {
		if (!used[i]) {
			cur.pb(i);
		}
	}
	for (int i = 0; i + 1 < SZ(cur); i += 2) {
		ans.pb({cur[i], cur[i + 1]});
		used[cur[i]] = used[cur[i + 1]] = true;
	}
	cout << SZ(ans) << '\n';
	for (auto it : ans) {
		cout << it.F << ' ' << it.S << '\n';
	}
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}