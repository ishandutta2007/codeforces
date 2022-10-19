#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

int T, n, m, x, y, A[N][N], B[N][N], C[N][N], S[N], S2[N];

char s[N];

int ans = 1e9;

int main() {
	for(cin >> T; T --;) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++ i) {
			scanf("%s", s + 1);\
			for(int j = 1; j <= m; ++ j) A[i][j] = s[j] - '0';
		}
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= m; ++ j) B[i][j] = A[i][j] + B[i - 1][j], C[i][j] = A[i][j] + C[i][j - 1];
		}
		
		ans = 1e9;
		
		for(int l = 1; l <= n; ++ l) {
			for(int r = l + 4; r <= n; ++ r) {
				int Min = 1e9;
				for(int x = 1; x <= m; ++ x) {
					S[x] = S[x - 1] + (1 - A[l][x]) + (1 - A[r][x]) + B[r - 1][x] - B[l][x];
				}
				for(int x = 4; x <= m; ++ x) {
					Min = min(Min, (r - l - 1) - (B[r - 1][x - 3] - B[l][x - 3]) - S[x - 3]);
					ans = min(ans, Min + S[x - 1] + (r - l - 1) - (B[r - 1][x] - B[l][x]));
				}
			}
		}
		cout << ans << endl;
	}
}