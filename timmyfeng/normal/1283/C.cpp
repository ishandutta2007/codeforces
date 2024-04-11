#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> f(n + 1);
	vector<bool> vstd(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> f[i];
		vstd[f[i]] = true;
	}

	vector<pair<int, int>> path;
	for (int i = 1; i <= n; ++i) {
		if (f[i] && !vstd[i]) {
			int cur = f[i];
			for ( ; f[cur]; cur = f[cur]);
			path.emplace_back(i, cur);
		} else if (!f[i] && !vstd[i]) {
			path.emplace_back(i, i);
		}
	}

	for (int i = 1; i < (int)path.size(); ++i) {
		f[path[i - 1].second] = path[i].first;
	}
	f[path.back().second] = path[0].first;
	
	for (int i = 1; i <= n; ++i) {
		cout << f[i] << ' ';
	}
	cout << '\n';
}