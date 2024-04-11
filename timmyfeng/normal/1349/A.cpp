#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

vector<int> exps[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int j = 2; j * j <= a; ++j) {
			if (a % j)
				continue;
			int cnt = 0;
			while (a % j == 0) {
				a /= j;
				++cnt;
			}
			exps[j].push_back(cnt);
		}
		if (a > 1) {
			exps[a].push_back(1);
		}
	}

	ll ans = 1;
	for (int i = 2; i < MX; ++i) {
		int sz = exps[i].size();
		if (sz >= n - 1) {
			sort(exps[i].begin(), exps[i].end());
			for (int j = 0; j < exps[i][sz - n + 1]; ++j) {
				ans *= i;
			}
		}
	}
	cout << ans << '\n';
}