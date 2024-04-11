#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int x, n, m;
		cin >> x >> n >> m;
		while (n--) {
			int newx = x / 2 + 10;
			if (newx < x) {
				x = newx;
			} else {
				break;
			}
		}
		x -= m * 10;
		if (x <= 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}