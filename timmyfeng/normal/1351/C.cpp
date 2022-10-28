#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		set<pair<pair<int, int>, pair<int, int>>> vstd;
		int x = 0, y = 0, ans = 0;
		for (auto c : s) {
			int nx = x, ny = y;
			if (c == 'N') {
				++ny;
			} else if (c == 'S') {
				--ny;
			} else if (c == 'W') {
				--nx;
			} else {
				++nx;
			}
			if (vstd.count({{x, y}, {nx, ny}})) {
				++ans;
			} else {
				ans += 5;
				vstd.emplace(make_pair(x, y), make_pair(nx, ny));
				vstd.emplace(make_pair(nx, ny), make_pair(x, y));
			}
			x = nx;
			y = ny;
		}
		cout << ans << '\n';
	}
}