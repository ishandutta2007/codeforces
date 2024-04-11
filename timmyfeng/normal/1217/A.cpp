#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a + c <= b) {
			cout << 0 << '\n';
		} else if (a + c > b) {
			cout << min(c + 1, (a + c - b + 1) / 2) << '\n';
		}
	}
}