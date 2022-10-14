#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0, j = 0;
	for (int i = 0; i < n; i++) {
		while (a[i] - a[j] > 5) {
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << '\n';
	return 0;
}