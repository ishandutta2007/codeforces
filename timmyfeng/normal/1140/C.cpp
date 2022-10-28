#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> song(n);
	for (auto& [a, b] : song) {
		cin >> b >> a;
	}
	sort(song.begin(), song.end(), greater<pair<int, int>>());

	ll ans = 0, sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto [a, b] : song) {
		pq.push(b);
		sum += b;
		if ((int)pq.size() > k) {
			sum -= pq.top();
			pq.pop();
		}
		ans = max(ans, a * sum);
	}
	cout << ans << '\n';
}