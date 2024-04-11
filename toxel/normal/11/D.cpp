#include<bits/stdc++.h>

const int N = 20;
typedef long long ll;

ll dp[1 << N][N];
int n;
bool mat[N][N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++ i){
		scanf("%d%d", &u, &v);
		-- u, -- v;
		mat[u][v] = mat[v][u] = true;
	}
	ll ans = 0;
	for (int i = 0; i < 1 << n; ++ i){
		std::vector <int> vec;
		for (int j = 0; j < n; ++ j){
			if (i >> j & 1){
				vec.push_back(j);
			}
		}
		if (vec.size() <= 1) continue;
		if (vec.size() == 2){
			if (mat[vec[0]][vec[1]]){
				dp[i][vec[1]] = 1;
			}
			continue;
		}
		for (int j = 1, sz = vec.size(); j < sz; ++ j){
			for (int k = 1; k < sz; ++ k){
				if (j == k) continue;
				if (mat[vec[k]][vec[j]]){
					dp[i][vec[j]] += dp[i ^ 1 << vec[j]][vec[k]];
				}
			}
		}
		for (int j = 1, sz = vec.size(); j < sz; ++ j){
			if (mat[vec[j]][vec[0]]){
				ans += dp[i][vec[j]];
			}
		}
	}
	return printf("%I64d\n", ans >> 1), 0;
}