#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int k; cin >> k;

		vector<long long> c(k);
		for (auto &i : c) cin >> i;

		long long sum = accumulate(c.begin(), c.end(), 0LL);

		vector<long long> fib = {0, 1};
		while (accumulate(fib.begin(), fib.end(), 0LL) < sum) {
			fib.push_back(fib.end()[-1] + fib.end()[-2]);
		}

		int prev = -1;
		while (fib.size() > 1u) {
			long long f = fib.back();

			int next = -1;
			for (int i = 0; i < k; ++i) {
				if (i == prev) continue;
				if (next == -1 || c[i] > c[next]) next = i;
			}
			if (next == -1 || c[next] < f) break;

			c[next] -= f;
			prev = next;
			fib.pop_back();
		}

		cout << (fib.size() == 1u ? "YES" : "NO") << "\n";
	}
}