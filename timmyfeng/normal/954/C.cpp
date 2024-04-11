#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	int y = 1;
	for (int i = 1; i < n; ++i) {
		y = max(y, abs(a[i] - a[i - 1]));
	}
	
	for (int i = 1; i < n; ++i) {
		int p = min(a[i], a[i - 1]);
		int q = max(a[i], a[i - 1]);
		if (q - p == 1) {
			if (y != 1 && p % y == 0) {
				cout << "NO" << '\n';
				return 0;
			}
		} else if (q - p != y) {
			cout << "NO" << '\n';
			return 0;
		}
	}

	cout << "YES" << '\n';
	cout << (int)1e9 << ' ' << y << '\n';
}