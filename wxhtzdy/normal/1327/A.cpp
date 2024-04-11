#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n, k;
		cin >> n >> k;
		if (n < k || n % 2 != k % 2 || n < k * k) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}
	}
	return 0;
}