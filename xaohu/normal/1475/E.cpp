#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;

int power(int a, int b) {
	int res = 1;
	for (; b; b /= 2, a = 1ll * a * a % P)
		if (b & 1) res = 1ll * res * a % P;
	return res;
}

int t, n, k, a;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		map<int, int> cnt;
		while (n--) {
			cin >> a;
			cnt[-a]++;
		}
		for (auto [a, b] : cnt) {
			if (k > b) {
				k -= b;
				continue;
			}
			long long ans = 1;
			for (int i = 1; i <= b; i++)
				ans = ans * i % P;
			for (int i = 1; i <= k; i++)
				ans = ans * power(i, P - 2) % P;
			for (int i = 1; i <= b - k; i++)
				ans = ans * power(i, P - 2) % P;
			cout << ans << "\n";
			break;
		}
	}
	
	return 0;
}