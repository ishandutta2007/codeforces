#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x > 3) {
			cout << "YES" << '\n';
		} else if (x > 1 && y <= 3) {
			cout << "YES" << '\n';
		} else if (y == 1) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}