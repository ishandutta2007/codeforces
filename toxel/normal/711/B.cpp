#include<bits/stdc++.h>

#define ll long long

const int N = 510;

ll a[N][N];
int n;

int main(){
	scanf("%d", &n);
	std::pair <int, int> sit;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			scanf("%I64d", &a[i][j]);
			if (!a[i][j]){
				sit = {i, j};
			}
		}
	}
	if (n == 1){
		return printf("1\n"), 0;
	}
	ll sum = 0, sum1 = 0;
	for (int j = 0; j < n; ++ j){
		sum += a[(sit.first + 1) % n][j];
		sum1 += a[sit.first][j];
	}
	a[sit.first][sit.second] = sum - sum1;
	if (a[sit.first][sit.second] <= 0){
		return printf("-1\n"), 0;
	}
	for (int i = 0; i < n; ++ i){
		ll sum1 = 0;
		for (int j = 0; j < n; ++ j){
			sum1 += a[i][j];
		}
		if (sum1 != sum){
			return printf("-1\n"), 0;
		}
	}
	for (int j = 0; j < n; ++ j){
		ll sum1 = 0;
		for (int i = 0; i < n; ++ i){
			sum1 += a[i][j];
		}
		if (sum1 != sum){
			return printf("-1\n"), 0;
		}
	}
	sum1 = 0;
	for (int i = 0; i < n; ++ i){
		sum1 += a[i][i];
	}
	if (sum1 != sum){
		return printf("-1\n"), 0;
	}
	sum1 = 0;
	for (int i = 0; i < n; ++ i){
		sum1 += a[i][n - 1 - i];
	}
	if (sum1 != sum){
		return printf("-1\n"), 0;
	}
	return printf("%I64d\n", a[sit.first][sit.second]), 0;
}