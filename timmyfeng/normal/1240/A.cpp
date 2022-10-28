#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> pre_sum(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> pre_sum[i];
		pre_sum[i] /= 100;
	}
	sort(pre_sum.rbegin(), pre_sum.rend() - 1);

	for (int i = 1; i <= n; ++i) {
		pre_sum[i] += pre_sum[i - 1];
	}

	ll k;
	int x, a, y, b;
	cin >> x >> a >> y >> b >> k;
	if (x > y) {
		swap(x, y);
		swap(a, b);
	}

	int lb = 1;
	int rb = n + 1;
	while (lb < rb) {
		int mb = (lb + rb) / 2;

		int cnt_ab = mb / (1LL * a * b / __gcd(a, b));
		int cnt_a = mb / a - cnt_ab;
		int cnt_b = mb / b - cnt_ab;

		ll sum = pre_sum[cnt_ab] * x +
				pre_sum[cnt_b + cnt_ab] * (y - x) +
				pre_sum[cnt_a + cnt_b + cnt_ab] * x;

		if (sum < k) {
			lb = mb + 1;
		} else {
			rb = mb;
		}
	}

	cout << (lb <= n ? lb : -1) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}