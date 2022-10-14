#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> x(n);
		int pref = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			int add = 0;
			for (int j = 0; j < 30; j++) {
				if ((pref & (1 << j)) > (x[i] & (1 << j))) {
					add += (1 << j);
				}
			}
			cout << add << " ";
			x[i] = x[i] | add;
			pref = pref | x[i];
		}
		cout << '\n';
	}
	return 0;
}