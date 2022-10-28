
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n0, n1, n2;
		cin >> n0 >> n1 >> n2;
		if (n0 && !n1) {
			cout << string(n0 + 1, '0') << '\n';
		} else if (n2 && !n1) {
			cout << string(n2 + 1, '1') << '\n';
		} else {
			cout << string(n0 + 1, '0');
			cout << string(n2 + 1, '1');
			for (int i = 1; i < n1; ++i) {
				cout << char('1' - (i % 2));
			}
			cout << '\n';
		}
	}
}