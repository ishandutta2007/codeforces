#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

struct man{
	int x, dx, pos;
	man() {}
	man(int x, int dx, int pos) {
		this->x = x;
		this->dx = dx;
		this->pos = pos;
	}
};

signed main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <man> plus, minus;
	vector <pair <int, int>> have, need;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		have.push_back({x, i + 1});
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		need.push_back({x, i + 1});
	}
	sort(have.begin(), have.end());
	sort(need.begin(), need.end());
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n; i++) {
		if (have[i].first == need[i].first) continue;
		if (have[i].first < need[i].first) {
			plus.push_back(man(have[i].first, need[i].first - have[i].first, have[i].second));
			s1 += need[i].first - have[i].first;
		} else {
			minus.push_back(man(have[i].first, have[i].first - need[i].first, have[i].second));
			s2 += have[i].first - need[i].first;
		}
	}
	if (s1 != s2) {
		cout << "NO" << endl;
		return 0;
	}
	vector <man> st;
	vector <pair <pair <int, int>, int>> ans;
	int l = 0, r = 0;
	while (l != plus.size() || r != minus.size()) {
		if (r == minus.size() || (l != plus.size() && plus[l].x < minus[r].x)) {
			st.push_back(plus[l]);
			l++;
		} else {
			while (!st.empty() && minus[r].dx != 0) {
				int a = st.back().dx, b = minus[r].dx;
				int d = min(a, b);
				st.back().dx -= d;
				minus[r].dx -= d;
				ans.push_back({{st.back().pos, minus[r].pos}, d});
				if (st.back().dx == 0) st.pop_back();
			}
			if (st.empty() && minus[r].dx != 0) {
				cout << "NO" << endl;
				return 0;
			}
			r++;
		}
	}
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for (auto elem : ans) {
		cout << elem.first.first << ' ' << elem.first.second << ' ' << elem.second << "\n";
	}
	return 0;

}