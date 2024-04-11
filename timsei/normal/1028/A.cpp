#include <bits/stdc++.h>

using namespace std;

const int N = 205;

char s[N][N];

int n, m, ans;

bool pd(int x, int y) {
	bool ok = 1;
	for(int i = x; i <= x + ans - 1; ++ i) {
		for(int j = y; j <= y + ans - 1; ++ j) {
			ok &= (s[x][y] == 'B');
		}
	}
	return ok;
	
}

main(void) {
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) ans += (s[i][j] == 'B');
	}
	int r, c;
	ans = sqrt(ans);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if((i + ans - 1 <= n) && (j + ans - 1 <= m)) {
				if(pd(i, j)) {
					cout << i + ans / 2 << " " << j + ans / 2 << endl;
					return 0;
				}
			}
		}
	}
}