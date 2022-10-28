#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<tuple<int, int, int>> pts;
		for (int i = 0; i < n; ++i) {
			int l, r;
			cin >> l >> r;
			pts.emplace_back(l, 0, i);
			pts.emplace_back(r, 1, i);
		}
		sort(pts.begin(), pts.end());

		int og = 0;
		set<int> cur;
		bool pre = false;
		bool intersect = false;
		vector<int> cnt(n);
		for (auto [x, type, i] : pts) {
			if (type) {
				cur.erase(i);
				if (cur.size() == 1u) {
					pre = true;
				} else if (cur.empty()) {
					++og;
				}
			} else {
				if (cur.size() == 1u) {
					intersect = true;
					if (pre) {
						++cnt[*cur.begin()];
					}
				}
				cur.insert(i);
				pre = false;
			}
		}

		cout << og + *max_element(cnt.begin(), cnt.end()) - !intersect << '\n';
	}
}