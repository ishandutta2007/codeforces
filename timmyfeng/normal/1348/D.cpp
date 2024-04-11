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

		vector<int> diff = {1};
		int cur = 1;
		while (cur < n) {
			if (n - cur <= diff.back() * 2) {
				diff.push_back(n - cur);
			} else if (n - cur >= diff.back() * 2 * 2) {
				diff.push_back(diff.back() * 2);
			} else {
				diff.push_back((n - cur) / 2);
			}
			cur += diff.back();
		}

		cout << diff.size() - 1u << '\n';
		for (int i = 1; i < diff.size(); ++i) {
			cout << diff[i] - diff[i - 1] << ' ';
		}
		cout << '\n';
	}
}