#include <bits/stdc++.h>
using namespace std;

long long pow(long long b, int e) {
	if (e == 0) return 1;
	if (e % 2) return b * pow(b, e - 1);
	long long tmp = pow(b, e / 2);
	return tmp * tmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	map<long long, long long> freq;
	vector<pair<int, int>> pf;
	while (n--) {
		int a;
		cin >> a;
		pf.clear();
		for (int i = 2; i * i <= a; ++i) {
			if (a % i) continue;
			pf.emplace_back(i, 0);
			while (a % i == 0) {
				++pf.back().second;
				a /= i;
			}
		}
		if (a > 1) {
			pf.emplace_back(a, 1);
		}
		long long me = 1, other = 1;
		for (auto [p, c] : pf) {
			me *= pow(p, c % k); 
			other *= pow(p, (k - c % k) % k);
		}
		ans += freq[other];
		++freq[me];
	}
	cout << ans << '\n';
}