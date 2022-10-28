#include <bits/stdc++.h>
using namespace std;

bool seen[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	vector<int> ans;
	set<int> cur;
	set<int> seen;
	int prev = 0;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if (a > 0) {
			if (seen.count(a)) {
				cout << -1;
				return 0;
			} else {
				cur.insert(a);
				seen.insert(a);
			}
		} else {
			if (!cur.count(-a)) {
				cout << -1;
				return 0;
			} else {
				cur.erase(-a);
				if (cur.empty()) {
					ans.push_back(i - prev);
					prev = i;
					seen.clear();
				}
			}
		}
	}
	if (!cur.empty()) {
		cout << -1;
	} else {
		cout << ans.size() << '\n';
		for (auto i : ans) {
			cout << i << ' ';
		}
	}
	cout << '\n';
}