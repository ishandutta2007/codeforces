#include<bits/stdc++.h>
#define ll long long

const int N = 110;

int mat[N][N], dis[N][N], n, min[N];

ll lcm(ll a, ll b){
	return a / std::__gcd(a, b) * b;
}

int main(){
	scanf("%d\n", &n);
	for (int i = 1, x; i <= n; ++ i){
		scanf("%d", &x);
		mat[i][x] = 1;
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j){
			if (mat[i][j])
				dis[i][j] = mat[i][j];
			else
				dis[i][j] = 1e9;
		}
	for (int k = 1; k <= n; ++ k){
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= n; ++ j){
				if (i == k || k == j)
					continue;
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		min[i] = INT_MAX;
		for (int j = 1; j <= n; ++ j){
			if (dis[i][j] >= 1e9 - 10 || dis[j][i] >= 1e9 - 10)
				continue;
			int len = dis[i][j] + dis[j][i];
			if (len & 1)
				min[i] = std::min(min[i], len);
			else
				min[i] = std::min(min[i], len >> 1);
		}
	}
	ll ans = 1;
	for (int i = 1; i <= n; ++ i){
		if (min[i] == INT_MAX)
			return printf("-1\n"), 0;
		ans = lcm(ans, min[i]);
	}
	return printf("%I64d", ans), 0;
}