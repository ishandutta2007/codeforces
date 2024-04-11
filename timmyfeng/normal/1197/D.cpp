#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MXM = 10;

priority_queue<ll, vector<ll>, greater<ll>> buc[MXM];
ll ext[MXM];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	buc[m - 1].push(k);
	ll sum = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		buc[i % m].push(sum - ext[i % m]);
		ll mn = 1e18;
	   	for (int j = 0; j < m; ++j) {
			if (buc[j].empty()) continue;
			mn = min(mn, buc[j].top() + ext[j]); 
		}
		ans = max(ans, sum - mn);
		ext[i % m] += k;
	}
	cout << ans << '\n';
}