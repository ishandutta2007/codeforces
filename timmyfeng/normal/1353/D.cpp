#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ans(n);
		priority_queue<pair<int, int>> pq;
		pq.emplace(n, 0);
		for (int i = 1; i <= n; ++i) {
			auto [len, left] = pq.top();
			pq.pop();
			left = -left;
			int mid = left + (len - 1) / 2;
			ans[mid] = i;
			if (mid != left) {
				pq.emplace(mid - left, -left);
			}
			if (mid != left + len - 1) {
				pq.emplace(left + len - 1 - mid, -(mid + 1));
			}
		}
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}