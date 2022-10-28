#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> c(n + 1), a(n + 1);
	for (int i=  1; i <= n; ++i) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	int ans = 0;
	vector<int> col(n + 1);
	for (int i = 1; i <= n; ++i) {
		vector<int> stk;
		int u = i;
		while (!col[u]) {
			col[u] = 1;
			stk.push_back(u);
			u = a[u];
		}
		if (col[u] == 1) {
			int mn = c[u];
			while (stk.back() != u) {
				mn = min(c[stk.back()], mn);
				col[stk.back()] = 2;
				stk.pop_back();
			}
			ans += mn;
		}
		for (auto i : stk) {
			col[i] = 2;
		}
	}

	cout << ans << '\n';
}