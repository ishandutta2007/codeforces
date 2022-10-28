#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s, t;
	cin >> n >> s >> t;

	set<int> zero, one;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0' && t[i] == '1') {
			zero.insert(i);
		} else if (s[i] == '1' && t[i] == '0') {
			one.insert(i);
		}
	}

	if (zero.size() != one.size()) {
		cout << -1 << "\n";
		return 0;
	}

	int ans = 0;
	while (!zero.empty()) {
		if (*zero.begin() > *one.begin()) {
			swap(zero, one);
		}

		int cur = 0;
		while (true) {
			auto it0 = zero.lower_bound(cur);
			if (it0 == zero.end()) {
				break;
			}
			auto it1 = one.lower_bound(*it0);
			if (it1 == one.end()) {
				break;
			}
			cur = *it1;
			zero.erase(it0);
			one.erase(it1);
		}
		++ans;
	}
	cout << ans << "\n";
}