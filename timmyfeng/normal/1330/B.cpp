#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	map<int, int> freq1, freq2;
	vector<int> ans;
	for (auto i : a) {
		++freq2[i];
	}
	auto valid = [](map<int, int>& freq, int i) {
		return freq.begin()->first == 1 && prev(freq.end())->first == i && freq.size() == i;
	};
	for (int i = 1; i < n; ++i) {
		--freq2[a[i - 1]];
		if (!freq2[a[i - 1]]) {
			freq2.erase(a[i - 1]);
		}
		++freq1[a[i - 1]];
		if (valid(freq1, i) && valid(freq2, n - i)) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto& i : ans) {
		cout << i << ' ' << n - i << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}