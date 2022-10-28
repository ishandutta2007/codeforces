#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<ll> rem;
		for (int i = 0; i < n; ++i) {
			bitset<60> a;
			cin >> a;
			rem.push_back(a.to_ullong());
		}

		ll k = (1LL << m) - n;
		ll lb = 0, rb = (1LL << m) - 1;
		while (lb <= rb) {
			ll mb = (lb + rb) / 2;
			ll res = mb;
			for (auto i : rem) {
				if (i < mb) {
					--res;
				}
			}
			if (res <= (k - 1) / 2) {
				lb = mb + 1;
			} else {
				rb = mb - 1;
			}
		}

		string ans = "";
		for (int i = 0; i < m; ++i) {
			if (rb % 2) {
				ans = '1' + ans;
			} else {
				ans = '0' + ans;
			}
			rb /= 2;
		}
		cout << ans << '\n';
	}
}