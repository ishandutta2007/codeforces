#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll cur = n * (n + 1) / 2;
	if (k < cur) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> p(n + 1), q(n + 1);
	iota(p.begin(), p.end(), 0);
	iota(q.begin(), q.end(), 0);
	for (int i = n / 2; i; --i) {
		if (k - cur >= (n + 1) / 2) {
			cur += (n + 1) / 2;
			swap(q[i + (n + 1) / 2], q[i]);
		} else {
			swap(q[i + k - cur], q[i]);
			cur = k;
			break;
		}
	}
	cout << cur << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << p[i] << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << q[i] << ' ';
	}
	cout << '\n';
}