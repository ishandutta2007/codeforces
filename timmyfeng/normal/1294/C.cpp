#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> pf;
		int m = n;
		for (int i = 2; i * i <= m; ++i) {
			if (m % i) continue;
			pf.emplace_back(i, 0);
			while (m % i == 0) {
				m /= i;
				++pf.back().second;
			}
		}
		if (m > 1) {
			pf.emplace_back(m, 1);
		}
		if (((int)pf.size() == 1 && pf[0].second < 6) || ((int)pf.size() == 2 && pf[1].second + pf[0].second < 4)) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
			if ((int)pf.size() == 1) {
				int a = pf[0].first;
				cout << a << ' ' << a * a << ' ' << n / a / a / a << '\n';
			} else {
				cout << pf[0].first << ' ' << pf[1].first << ' ' << n / pf[0].first / pf[1].first << '\n';
			}
		}
	}
}