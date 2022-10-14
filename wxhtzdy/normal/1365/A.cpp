#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		bool col[n], row[m];
		for (int i = 0; i < n; i++) {
			col[i] = false;
		}
		for (int i = 0; i < m; i++) {
			row[i] = false;
		}
		int a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 1) {
					col[i] = true;
					row[j] = true;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (col[i] == false && row[j] == false) {
					ans++;
					col[i] = true;
					row[j] = true;
				}
			}
		}
		if (ans % 2 == 0) {
			cout << "Vivek" << endl;
		} else {
			cout << "Ashish" << endl;
		}
	}
	return 0;
}