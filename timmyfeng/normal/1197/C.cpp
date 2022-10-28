#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int prev;
	cin >> prev;
	vector<int> diff;
	for (int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		diff.push_back(a - prev);
		prev = a;
	}
	sort(diff.begin(), diff.end());

	int ans = 0;
	for (int i = 0; i + k < n; ++i) {
		ans += diff[i];
	}
	cout << ans << '\n';
}