#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

bool cmp(ll a, ll b, ll c, ll d) {
	return 4 * (a + b) * (a + b) * c * d < 4 * (c + d) * (c + d) * a * b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> freq;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			++freq[a];
		}

		int prev = 0, ans_a = 0, ans_b = 0;
		for (auto [a, b] : freq) {
			if (b < 2)
				continue;
			if (prev) {
				if (!ans_a || cmp(prev, a, ans_a, ans_b)) {
					ans_a = prev, ans_b = a;
				}
			}
			if (b >= 4) {
				if (!ans_a || cmp(a, a, ans_a, ans_b)) {
					ans_a = a, ans_b = a;
				}
			}
			prev = a;
		}
		for (auto [a, b] : freq) {
			if (b >= 2 && a != prev) {
				if (cmp(prev, a, ans_a, ans_b)) {
					ans_a = prev, ans_b = a;
				}
			}
		}
		cout << ans_a << ' ' << ans_a << ' ' << ans_b << ' ' << ans_b << '\n';
	}
}