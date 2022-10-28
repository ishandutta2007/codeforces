#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		bool ok = true;
		if (k % 3) {
			ok = n % 3;
		} else {
			n %= k + 1;
			ok = (n % 3 || n == k);
		}
		cout << (ok ? "Alice" : "Bob") << '\n';
	}
}