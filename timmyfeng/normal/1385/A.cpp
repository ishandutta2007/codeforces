#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == y && x >= z) {
			cout << "YES\n";
			cout << x << " " << z << " " << z << "\n";
		} else if (x == z && x >= y) {
			cout << "YES\n";
			cout << x << " " << y << " " << y << "\n";
		} else if (z == y && z >= x) {
			cout << "YES\n";
			cout << z << " " << x << " " << x << "\n";
		} else {
			cout << "NO\n";
		}
	}
}