#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MXS = 1e6 + 1;

int cnt[MXS];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	ll ans = 0;
	int done = 0;
	vector<int> right, left;
	for (int i = 0; i < n; ++i) {
		int l;
		cin >> l;
		vector<int> s(l);
		for (auto& j : s) {
			cin >> j;
		}

		bool ok = true;
		for (int i = 1; i < l; ++i) {
			ok &= (s[i] <= s[i - 1]);
		}

		if (ok) {
			int mn = *min_element(s.begin(), s.end());
			int mx = *max_element(s.begin(), s.end());
			left.push_back(mn);
			++cnt[mx];
		} else {
			ans += n;
			++done;
		}
	}

	for (int i = MXS - 2; i; --i) {
		cnt[i] += cnt[i + 1];
	}

	for (auto i : left) {
		ans += done + cnt[i + 1];
	}
	cout << ans << '\n';
}