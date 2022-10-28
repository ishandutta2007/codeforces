#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	
	if (max(a, b) > n || min(a, b) != 1 || (a == 1 && b == 1 && (n == 2 || n == 3))) {
		cout << "NO" << '\n';
		return 0;
	}

	cout << "YES" << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			bool res = (abs(i - j) == 1 && max(i, j) <= n - max(a, b));
			res ^= (a == 1);
			res &= (i != j);
			cout << (char)('0' + res);
		}
		cout << '\n';
	}
}