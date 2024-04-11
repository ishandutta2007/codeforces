#include <bits/stdc++.h>
using namespace std;

vector<long long> a;

long long cost(int k) {
	long long res = 0;
	for (auto i : a) {
		res += min(i % k, k - i % k);
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	for (auto& i : a) {
		cin >> i;
	}

	for (int i = 1; i < n; ++i) {
		a[i] += a[i - 1];
	}
	
	int tmp = a.back();
	long long ans = 1e18;
	for (int i = 2; i * i <= tmp; ++i) {
		if (tmp % i) continue;
		ans = min(ans, cost(i));
		while (tmp % i == 0) {
			tmp /= i;
		}
	}
	if (tmp > 1) {
		ans = min(ans, cost(tmp));
	}
	cout << (ans == 1e18 ? -1 : ans) << '\n';
}