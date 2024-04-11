#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	unsigned long long ans = 0, b = 0, w = 0, c = 1;
	for (int i = 0; i < n; i++) {
		b = 0;
		w = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				b++;
			} else {
				w++;
			}
		}
		ans += (c << b) - 1;
		ans += (c << w) - 1;
	}
	for (int j = 0; j < m; j++) {
		b = 0;
		w = 0;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == 0) {
				b++;
			} else {
				w++;
		}
		}
		ans += (c << b) - 1;
		ans += (c << w) - 1;
	}
	cout << ans - n * m << endl;
	return 0;
}