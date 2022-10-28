#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const ll INF = 4e18;

ll delta(int a, int b) {
	return a - 3LL * b * b + 3LL * b - 1;
}

int calc(int a, ll k) {
	int lb = 0, rb = a;
	while (lb < rb) {
		int mb = lb + (rb - lb + 1) / 2;
		if (delta(a, mb) >= k) {
			lb = mb;
		} else {
			rb = mb - 1;
		}
	}
	return lb;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	ll lb = -INF, rb = INF;
	while (lb < rb) {
		ll mb = lb + (rb - lb + 1) / 2;
		ll cnt = 0;
		for (auto i : a) {
			cnt += calc(i, mb);
		}
		if (cnt >= k) {
			lb = mb;
		} else {
			rb = mb - 1;
		}
	}

	ll cnt = 0;
	for (auto i : a) {
		int b = calc(i, lb);
		cnt += b;
	}

	for (auto i : a) {
		int b = calc(i, lb);
		if (delta(i, b) == lb && cnt > k) {
			--cnt;
			--b;
		}
		cout << b << ' ';
	}
	cout << '\n';
}