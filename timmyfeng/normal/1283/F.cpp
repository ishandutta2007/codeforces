#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n - 1), cnt(n + 1);
	for (auto& i : a) {
		cin >> i;
		++cnt[i];
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; ++i) {
		if (!cnt[i]) {
			pq.push(i);
		}
	}

	vector<pair<int, int>> ans;
	while (!a.empty()) {
		int u = pq.top();
		int v = a.back();
		a.pop_back();
		pq.pop();
		ans.emplace_back(u, v);
		if (!--cnt[v]) {
			pq.push(v);
		}
	}

	cout << pq.top() << '\n';
	for (auto [u, v] : ans) {
		cout << u << ' ' << v << '\n';
	}
}