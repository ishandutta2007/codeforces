#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == n) {
			pos = i;
		}
	}

	for (int i = pos; i; --i) {
		if (a[i] < a[i - 1]) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	for (int i = pos; i + 1 < n; ++i) {
		if (a[i] < a[i + 1]) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
}