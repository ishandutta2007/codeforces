#include <iostream>
#include <vector>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		int x;
		cin >> x;
		for (int i = 0; i < n; i++) a[i] -= x;
		vector<long long> c(n + 1);
		for (int i = 0; i < n; i++) {
			c[i + 1] = c[i] + a[i];
		}
		vector<vector<int>> f(n + 1, vector<int>(3, -1));
		f[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				if (f[i][j] != -1) {
					// don't take ith element
					f[i + 1][0] = max(f[i + 1][0], f[i][j]);
					// take ith element
					bool canTake = true;
					if ((j >= 1) && (c[i + 1] - c[i - 1] < 0)) canTake = false;
					if ((j >= 2) && (c[i + 1] - c[i - 2] < 0)) canTake = false;
					if (canTake) {
						int nj = min(j + 1, 2);
						f[i + 1][nj] = max(f[i + 1][nj], f[i][j] + 1);
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < 3; i++) res = max(res, f[n][i]);
		cout << res << "\n";
	}
	return 0;
}