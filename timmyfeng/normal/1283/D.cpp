#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	
	queue<pair<int, int>> que;
	set<int> tree;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		tree.insert(a);
		que.emplace(1, a - 1);
		que.emplace(1, a + 1);
	}

	ll sum = 0;
	set<int> ans;
	while ((int)ans.size() < m) {
		auto [d, a] = que.front();
		que.pop();
		if (ans.count(a) || tree.count(a))
			continue;
		ans.insert(a);
		sum += d;
		que.emplace(d + 1, a + 1);
		que.emplace(d + 1, a - 1);
	}

	cout << sum << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}