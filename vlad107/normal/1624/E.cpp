#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <array>
#include <limits>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n); 
		for (int i = 0; i < n; i++) cin >> a[i];
		string s;
		cin >> s;
		unordered_map<string, vector<int>> p;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j + 1 < m; j++) {
				string t = a[i].substr(j, 2);
				p[t] = {j, j + 1, i + 1};
				if (j + 2 < m) {
					string t2 = a[i].substr(j, 3);
					p[t2] = {j, j + 2, i + 1};
				}
			}
		}
		vector<int> pr(m + 1, -1);
		pr[0] = 0;
		for (int i = 0; i < m; i++) {
			if (pr[i] == -1) continue;
			if (i + 1 < m) {
				string t = s.substr(i, 2);
				if (p.find(t) != p.end()) {
					pr[i + 2] = i;
				}
			}
			if (i + 2 < m) {
				string t = s.substr(i, 3);
				if (p.find(t) != p.end()) {
					pr[i + 3] = i;
				}
			}
		}
		if (pr[m] == -1) {
			cout << -1 << "\n";
		} else {
			vector<vector<int>> res;
			for (int i = m; i != 0; i = pr[i]) {
				string t = s.substr(pr[i], i - pr[i]);
				res.push_back(p[t]);
			}
			reverse(res.begin(), res.end());
			cout << res.size() << "\n";
			for (int i = 0; i < res.size(); i++) {
				cout << res[i][0] + 1 << " " << res[i][1] + 1 << " " << res[i][2] << "\n";
			}
		}
	}
	return 0;
}