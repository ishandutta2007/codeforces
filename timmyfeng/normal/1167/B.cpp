#include <bits/stdc++.h>
using namespace std;

int vals[] = {4, 8, 15, 16, 23, 42};
int a[4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; ++i) {
		cout << "? " << i + 1 << ' ' << i + 2 << endl;
		cin >> a[i];
	}
	do {
		bool ok = true;
		for (int i = 0; i < 4; ++i) {
			if (vals[i] * vals[i + 1] != a[i]) {
				ok = false;
			}
		}
		if (ok) {
			cout << "! ";
			for (auto i : vals) {
				cout << i << ' ';
			}
			cout << '\n';
			return 0;
		}
	} while(next_permutation(vals, vals + 6));
}