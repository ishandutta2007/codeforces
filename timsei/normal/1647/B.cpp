#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

int n, m, x, y, A[N];
char s[N][N];

bool solve(int i, int l, int r) {
	int ans = 0;
	for(int j = l; j <= r; ++ j) ans += (s[i][j] == '1');
	return (ans == (r - l + 1) || ans == 0);
}

int main() {
	int t;
	for(cin >> t; t --;) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++ i) scanf("%s", s[i] + 1);
		bool ok = 1;
		for(int i = 1; i <= n; ++ i) {
			int beg = -1;
			for(int j = 1; j <= m; ++ j) {
				if(s[i][j] == '1') {
					if(beg == -1) {
						beg = j;
					}
				} else {
					if(beg == -1) continue;
					if(i < n) ok &= solve(i + 1, beg, j - 1);
					if(i > 1) ok &= solve(i - 1, beg, j - 1);
					beg = -1;
				}
			}
			if(beg != -1) {
				if(i < n) ok &= solve(i + 1, beg, m);
				if(i > 1) ok &= solve(i - 1, beg, m);
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
}