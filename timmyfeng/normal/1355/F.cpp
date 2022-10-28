#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e4;
const int INF = 1e9;
const ll INF64 = 1e18;

bool sieve[MX];

ll test(int a) {
	ll res = 1;
	while (a <= INF / res) {
		res *= a;
	}
	return res;
}

void solve() {
	ll i = 2, cur = 1, ans = 1, sec = 1;
	for (int j = 0; j < 16; ++j) {
		cur = 1;
		for ( ; i <= INF64 / cur; ++i) {
			if (!sieve[i]) {
				cur *= i;
			}
		}
		cout << "? " << cur << endl;

		int qry;
		cin >> qry;
		vector<int> pos;
		for (int k = 2; k * k <= qry; ++k) {
			if (qry % k)
				continue;
			qry /= k;
			pos.push_back(k);
		}
		if (qry > 1) {
			pos.push_back(qry);
		}

		int sz = pos.size();
		for (int k = 0; k < sz; k += 2) {
			ll ask = test(pos[k]);
			if (k + 1 < sz) {
				ask *= test(pos[k + 1]);
			}
			cout << "? " << ask << endl;

			cin >> qry;
			for (int l = k; l < k + 2 && l < sz; ++l) {
				int cnt = 0;
				while (qry % pos[l] == 0) {
					++cnt;
					sec *= pos[l];
					qry /= pos[l];
				}
				ans *= cnt + 1;
			}
		}

		if (i * i * i > INF / sec) {
			cout << "! " << 2 * ans << endl;
			return;
		}
	}
	cout << "! " << 8 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i < MX; ++i) {
		if (sieve[i])
			continue;
		for (int j = i * 2; j < MX; j += i) {
			sieve[j] = true;
		}
	}
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}