#include<bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int x = max(a, max(b, c));
		int f = x - a + x - b + x - c;
		if (f > n) {
			cout << "NO" << endl;
			continue;
		}
		if ((n - f) % 3 == 0) {
			cout << "YES" << endl;
			//continue;
		} else {
			cout << "NO" << endl;
		}
	}
}