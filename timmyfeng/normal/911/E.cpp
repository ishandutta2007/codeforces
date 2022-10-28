#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	set<int> cnt;
	vector<int> p;
	int mex = 1;

	auto add = [&](int a) {
		cnt.insert(a);
		p.push_back(a);
		while (*cnt.begin() == mex) {
			cnt.erase(cnt.begin());
			++mex;
		}
	};

	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		if (!cnt.empty() && a > *cnt.begin()) {
			cout << -1 << '\n';
			return 0;
		}
		add(a);
	}

	for (int i = k; i < n; ++i) {
		if (cnt.empty()) {
			add(n);
		} else {
			add(*cnt.begin() - 1);
		}
	}

	for (auto i : p) {
		cout << i << ' ';
	}
	cout << '\n';
}