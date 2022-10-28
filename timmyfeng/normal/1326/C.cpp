#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int k, n;
	cin >> n >> k;
	vector<int> p(n);
	for (auto& i : p) {
		cin >> i;
	}

	long long mx = 0, ct = 1;
	int i = 0;
	while (p[i] <= n - k) {
		++i;
	}
	int prev = i;
	mx += p[i];
	for (++i ; i < n; ++i) {
		if (p[i] > n - k) {
			mx += p[i];
			ct *= i - prev, ct %= MOD;
			prev = i;
		}
	}
	cout << mx << ' ' << ct << '\n';
}