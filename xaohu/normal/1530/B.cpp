#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int t, n, m, s[30][30];
int main() {
	cin >> t;
	while (t--) {
		memset(s, 0, sizeof s);
		cin >> n >> m;
		s[1][1] = s[1][m] = s[n][1] = s[n][m] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if ((i == 1 || i == n || j == 1 || j == m) && !s[i - 1][j] && !s[i + 1][j] && !s[i][j - 1] && !s[i][j + 1])
					s[i][j] = 1;
				else
					s[i][j] = 0;
				cout << s[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}