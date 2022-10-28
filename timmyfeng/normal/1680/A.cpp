#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >>t ;

	while (t--) {
		int a,b , c, d; cin >> a >> b >> c >> d;

		if (b < c || d < a) {
			cout << a + c << "\n";
		} else {
			cout << max(a, c) << "\n";
		}
	}
}