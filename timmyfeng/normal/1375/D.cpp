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
		vector<int> a(n);
		for (auto& i : a) {
			cin >> i;
		}

		auto mex = [&a]() {
			set<int> s;
			for (auto& i : a) {
				s.insert(i);
			}
			int res = 0;
			while (s.count(res)) {
				++res;
			}
			return res;
		};

		vector<int> ans;
		while (true) {
			int cur = mex();
			if (cur == n)
				break;
			a[cur] = cur;
			ans.push_back(cur + 1);
		}

		for (int i = 0; i < n; ++i) {
			if (a[i] == i)
				continue;

			while (true) {
				int ndx = find(a.begin(), a.end(), i) - a.begin();
				if (ndx == n)
					break;
				ans.push_back(ndx + 1);
				a[ndx] = mex();
			}

			a[i] = i;
			ans.push_back(i + 1);
		}

		cout << ans.size() << "\n";
		for (auto& i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
}