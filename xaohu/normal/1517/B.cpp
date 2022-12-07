#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t, n, m, b[100][100], a[100][100], ord[10000], p[100];
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> b[i][j], a[i][j] = 0;

		iota(ord, ord + n * m, 0);
		sort(ord, ord + n * m, [&](int x, int y) {
			return b[x / m][x % m] < b[y / m][y % m];
		});

		for (int i = 0; i < m; i++) {
			int x = ord[i];
			a[x / m][i] = b[x / m][x % m];
		}

		fill(p, p + n, 0);
		for (int i = m; i < n * m; i++) {
			int r = ord[i] / m;
			int c = ord[i] % m;
			while (a[r][p[r]])
				p[r]++;
			a[r][p[r]] = b[r][c];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
	}

	return 0;
}