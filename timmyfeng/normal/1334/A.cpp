#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int pp = 0, pc = 0;
		bool ok = true;
		while (n--) {
			int p, c;
			cin >> p >> c;
			if (p < pp || c < pc) {
				ok = false;
			}
			if (c - pc > p - pp) {
				ok = false;
			}
			pp = p;
			pc = c;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}