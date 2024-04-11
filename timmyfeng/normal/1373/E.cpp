#include <bits/stdc++.h>
using namespace std;

int f(long long x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

long long get(int sum, int one) {
	if (sum < one)
		return sum;
	return get(sum - one, 9) * 10 + one;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		++k;

		if (k == 1) {
			cout << get(n, 9) << "\n";
			continue;
		}

		long long ans = 1e18;
		for (long long base = 10; base <= 1e10; base *= 10) {
			for (int i = 1; i <= 10; ++i) {
				int tgt = n;
				for (int j = 0; j < k; ++j) {
					tgt -= f(base - i + j);
				}

				if (tgt % k == 0 && tgt >= 0) {
					ans = min(ans, get(tgt / k, 8) * base + base - i);
				}
			}
		}
		cout << (ans == 1e18 ? -1 : ans) << "\n";
	}
}