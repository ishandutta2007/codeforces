#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> pts(n);
	for (auto& [x, y] : pts) {
		cin >> x >> y;
	}

	vector<int> ans;
	while (true) {
		vector<int> a, aa;
		for (int i = 0; i < n; ++i) {
			if ((pts[i].first + pts[i].second) % 2) {
				a.push_back(i);
			}
			if (pts[i].first % 2) {
				aa.push_back(i);
			}
		}

		if (a.empty() || int(a.size()) == n) {
			if (aa.empty() || int(aa.size()) == n) {
				for (auto& [x, y] : pts) {
					if (x % 2) {
						++x;
					}
					if (y % 2) {
						++y;
					}
					x /= 2;
					y /= 2;
				}
			} else {
				ans = aa;
				break;
			}
		} else {
			ans = a;
			break;
		}
	}

	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i + 1 << " ";
	}
	cout << "\n";
}