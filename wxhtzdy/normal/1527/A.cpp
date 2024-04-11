#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int mx = 0;
		for (int i = 0; i < 30; i++) {
			if ((1 << i) <= n) {
				mx = i;
			}
		}
		cout << (1 << mx) - 1 << '\n';
	}
	return 0;
}