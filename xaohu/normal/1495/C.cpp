#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = b; i >= a; --i)

using ll = long long;
using namespace std;

char s[505][505];
int n, m;

void solve() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", s[i] + 1);
	rep(i, 1, n)
		for (int j = 1; j <= m; j += 3)
			s[i][j] = 'X';
	for (int j = 1; j + 3 <= m; j += 3) {
		if (n == 1) {
			s[1][j + 1] = s[1][j + 2] = 'X';
		}
		else {
			if (s[2][j + 1] == 'X') {
				s[2][j + 2] = 'X';
			}
			else if (s[2][j + 2] == 'X') {
				s[2][j + 1] = 'X';
			}
			else {
				s[1][j + 1] = s[1][j + 2] = 'X';
			}
		}
	}
	if (m % 3 == 0)
		rep(i, 1, n)
			if (s[i][m] == 'X')
				s[i][m - 1] = 'X';
	
	rep(i, 1, n) {
		rep(j, 1, m) printf("%c", s[i][j]);
		puts("");
	}	
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}