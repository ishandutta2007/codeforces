#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool equal(vector <pair <int, int>> a, vector <pair <int, int>> b) {
	if (a.empty() && b.empty()) return 1;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a.size() != b.size()) return 0;
	for (int i = 0; i < (int) a.size(); i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	int n;
	cin >> n;
	vector <pair <int, int>> f, s;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		f.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		s.push_back(make_pair(x, y));
	}
	pair <int, int> ans;
	vector <pair <int, int>> need, have;
	for (int i = 1; i < n; i++) have.push_back(s[i]);
	for (int i = 0; i < n; i++) {
		ans = make_pair(f[i].first + s[0].first, f[i].second + s[0].second);
		need.clear();
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			need.push_back(make_pair(ans.first - f[j].first, ans.second - f[j].second));
		}
		if (equal(need, have)) {
			cout << ans.first << ' ' << ans.second << endl;
			return 0;
		}
	}
	return -1;
}