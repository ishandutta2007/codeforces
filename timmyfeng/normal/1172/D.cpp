#include <bits/stdc++.h>
using namespace std;

vector<int> calc(vector<int> a) {
	vector<int> res(a.size());
	vector<int> perm(a.size());
	iota(perm.begin(), perm.end(), 0);
	for (int i = 1; i < int(a.size()); ++i) {
		int ndx = find(perm.begin(), perm.end(), a[i]) - perm.begin();
		res[i] = ndx;
		swap(perm[i], perm[ndx]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> r(n + 1);
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		r[a] = i;
	}

	vector<int> c(n + 1);
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		c[a] = i;
	}

	vector<int> a = calc(r);
	vector<int> b = calc(c);

	vector<vector<int>> ans;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == i && b[i] == i) {
			continue;
		}
		ans.push_back({i, b[i], a[i], i});
	}

	cout << ans.size() << "\n";
	for (auto& i : ans) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
}