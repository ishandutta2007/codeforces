#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;
const int M = N * N;

int n, f[N][N], m, u[M], v[M], w[M];

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= n; ++ j) {
				if(i != j) {
					f[i][j] = 1e9;
				}
			}
		}
		for(int i = 1; i <= m; ++ i) {
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
			f[u[i]][v[i]] = f[v[i]][u[i]] = 1;
		}
		
		for(int k = 1; k <= n; ++ k) {
			for(int i = 1; i <= n; ++ i) {
				for(int j = 1; j <= n; ++ j) {
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
				}
			}
		}
		
		long long ans= 1e18;
		
		for(int i = 1; i <= m; ++ i) {
			ans = min(ans, (long long)(1 + f[1][u[i]] + f[v[i]][n]) * (long long)w[i]);
			ans = min(ans, (long long)(1 + f[1][v[i]] + f[u[i]][n]) * (long long)w[i]);
		}
		for(int i = 1; i <= m; ++ i) {
			for(int j = 1; j <= n; ++ j) {
				ans = min(ans, (long long)(2 + f[1][j] + f[j][n] + min(f[j][u[i]], f[j][v[i]])) * (long long)w[i]);
			}
		}
		cout << ans << endl;
	}
}