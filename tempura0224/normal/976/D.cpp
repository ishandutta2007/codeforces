#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& d: a) cin >> d;
	vector<pair<int, int>> ans;
	int l = 0, r = n;
	int st = 0;
	while (a.size()) {
		int m = a.back() + 1;
		for (int i = 0; i < a[0]; i++) {
			for (int j = i + 1; j < m; j++) {
				ans.emplace_back(st + i, st + j);
			}
		}
		st += a[0];
		vector<int> na;
		for (int i = 1; i + 1 < a.size(); i++) {
			na.push_back(a[i] - a[0]);
		}
		a.swap(na);
	}
	cout << ans.size() << endl;
	for (auto p : ans) cout << p.first + 1 << " " << p.second + 1 << "\n";
}