#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	
	vector<int> ans;
	int i = 1;
	while (i <= n && m > 0) {
		ans.push_back(i);
		m -= (i - 1) / 2;
		++i;
	}
	
	if (m > 0) {
		cout << -1 << '\n';
		return 0;
	}
	
	while (m) {
		ans.back() += 2;
		++m;
	}
	i = (ans.empty() ? 1 : ans.back() + 1);

	for (int j = i * n; (int)ans.size() < n; j += i) {
		ans.push_back(j);
	}	
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}