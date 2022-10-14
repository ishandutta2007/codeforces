#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<long long> fact(1, 1);
	while (fact.back() < 1e12) fact.push_back(fact.back() * (fact.size() + 1));
	int tt;
	cin >> tt;
	while (tt--) {
		long long n;
		cin >> n;
		int ans = 1e9;
		for (int i = 0; i < (1 << fact.size()); i++) {
			long long s = 0;
			for (int j = 0; j < (int) fact.size(); j++) {
				if (i >> j & 1) {
					s += fact[j];
				}
			}
			if (s <= n) ans = min(ans, __builtin_popcount(i) + __builtin_popcountll(n - s));
		}
		cout << (ans == 1e9 ? -1 : ans) << '\n';
	}
}