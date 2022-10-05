#include<bits/stdc++.h>
#define ll long long

const int N = 110;

ll n, m, k, x, y, cnt[N][N];

int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d", &n, &m, &k, &x, &y);
	if (n == 1){
		if (!(k % m)){
			return printf("%I64d %I64d %I64d\n", k / m, k / m, k / m), 0;
		}
		return printf("%I64d %I64d %I64d\n", k / m + 1, k / m, k % m >= y ? k / m + 1 : k / m), 0;
	}
	ll time = k / (2 * (n - 1) * m), nokori = k % (2 * (n - 1) * m);
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			cnt[i][j] = time * (i == 1 || i == n ? 1 : 2);
		}
	}
	for (int i = 1; i < n; ++ i){
		for (int j = 1; j <= m; ++ j, -- nokori){
			if (!nokori){
				break;
			}
			++ cnt[i][j];
		}
		if (!nokori){
			break;
		}
	}
	for (int i = n; i > 1; -- i){
		for (int j = 1; j <= m; ++ j, -- nokori){
			if (!nokori){
				break;
			}
			++ cnt[i][j];
		}
		if (!nokori){
			break;
		}
	}
	ll max = 0, min = LLONG_MAX;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			max = std::max(max, cnt[i][j]);
			min = std::min(min, cnt[i][j]);
		}
	}
	return printf("%I64d %I64d %I64d\n", max, min, cnt[x][y]), 0;
}