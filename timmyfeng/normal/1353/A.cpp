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
		if (n == 1) {
			cout << 0 << '\n';
		} else if (n == 2) {
			cout << k << '\n';
		} else {
			cout << 2 * k << '\n';
		}
	}
}