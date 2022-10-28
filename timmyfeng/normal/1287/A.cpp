#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		cin.ignore();
		int sol = 0;
		int srk = -1;
		while (k--) {
			if (cin.get() == 'A') {
				srk = 0;
			} else if (srk >= 0) {
				++srk;
				sol = max(sol, srk);
			}
		}
		cout << sol << "\n";
	}
}