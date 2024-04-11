#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, x;
	cin >> n >> x;
	vector<ll> d(n);
	for (auto& i : d) {
		cin >> i;
	}
	for (int i = 0; i < n; ++i) {
		d.push_back(d[i]);
	}

	ll ans = 0, cur = 0, sum = 0, cnt = 0;
	int j = 0;
	for ( ; sum < x; ++j) {
		cnt = min(d[j], x - sum);
		cur += cnt * (cnt + 1) / 2;
		sum += d[j];
	}

	for (int i = 0; i < n; ++i) {
		ll overlap = min(d[i], sum - x);
		cur += overlap * cnt;
		cnt += overlap;
		ans = max(ans, cur);
		while (j < 2 * n && sum < x + d[i]) {
			cnt = min(d[j], x + d[i] - sum);
			cur += (x - sum) * cnt;
			ans = max(ans, cur);
			sum += d[j];
			++j;
		}
		sum -= d[i];
	}
	cout << ans << '\n';
}