#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, p;
	cin >> n >> p;
	for (int i = 1; n >= 0; ++i) {
		n -= p;
		if (i >= __builtin_popcount(n) && i <= n) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}