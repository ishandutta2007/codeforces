#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int x = 86400 - a[i];
		t -= x;
		if (t <= 0) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	return 0;
}