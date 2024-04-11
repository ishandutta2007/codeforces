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
		map<int, int> freq;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			++freq[a];
		}
		int mx = 0;
		for (auto i : freq) {
			mx = max(mx, i.second);
		}
		if (mx > freq.size()) {
			cout << freq.size() << '\n';
		} else if (mx == freq.size()) {
			cout << mx - 1 << '\n';
		} else {
			cout << mx << '\n';
		}
	}
}