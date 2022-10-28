#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> both = {0};
	vector<int> just_a = {0};
	vector<int> just_b = {0};
	for (int i = 0; i < n; ++i) {
		int t, a, b;
		cin >> t >> a >> b;

		if (a && b) {
			both.push_back(t);
		} else if (a) {
			just_a.push_back(t);
		} else if (b) {
			just_b.push_back(t);
		}
	}

	sort(both.begin(), both.end());
	sort(just_a.begin(), just_a.end());
	sort(just_b.begin(), just_b.end());

	for (int i = 1; i < int(just_a.size()); ++i) {
		just_a[i] += just_a[i - 1];
	}
	for (int i = 1; i < int(just_b.size()); ++i) {
		just_b[i] += just_b[i - 1];
	}

	int ans = 2e9 + 1;
	int cur = 0;
	for (int i = 0; i < int(both.size()); ++i) {
		cur += both[i];
		if (k - i >= 0 && k - i < int(min(just_a.size(), just_b.size()))) {
			ans = min(ans, just_a[k - i] + just_b[k - i] + cur);
		}
	}
	cout << (ans <= 2e9 ? ans : -1) << "\n";
}