#include <bits/stdc++.h>
using namespace std;
const int CK = 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	shuffle(a.begin(), a.end(), rng);

	vector<long long> prime;
	for (int i = 0; i < CK && i < n; ++i) {
		for (auto k : {a[i] - 1, a[i], a[i] + 1}) {
			for (long long j = 2; j * j <= k; ++j) {
				if (k % j) continue;
				while (k % j == 0) {
					k /= j;
				}
				prime.push_back(j);
			}
			if (k > 1) {
				prime.push_back(k);
			}
		}
	}

	long long ans = n;
	for (auto j : prime) {
		long long res = 0;
		for (auto k : a) {
			res += (k < j ? j - k : min((k - j) % j, j - (k - j) % j));
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
}