#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5;
const int MXA = 1e7 + 1;

int d[MX][2], sieve[MXA];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i < MXA; ++i) {
		if (sieve[i])
			continue;
		for (int j = i; j < MXA; j += i) {
			sieve[j] = i;
		}
	}

	int n;
	cin >> n;

	memset(d, -1, sizeof d);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;

		vector<array<int, 2>> factors;
		int aa = a;
		while (aa > 1) {
			int cnt = 0;
			int cur = sieve[aa];
			while (aa % cur == 0) {
				aa /= cur;
				++cnt;
			}
			factors.push_back({cur, cnt});
		}

		for (auto k : factors) {
			int d1 = 1;
			int d2 = a;
			for (int j = 0; j < k[1]; ++j) {
				d1 *= k[0];
				d2 /= k[0];
			}
			if (d2 != 1 && __gcd(d1 + d2, a) == 1) {
				d[i][0] = d1;
				d[i][1] = d2;
				break;
			}
		}
	}

	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < n; ++i) {
			cout << d[i][k] << ' ';
		}
		cout << '\n';
	}
}