#include<bits/stdc++.h>

const int N = 50;

int t[N], m, n, k, sum;

int solve(int x){
	int mm = m - x * sum;
	if (mm < 0){
		return 0;
	}
	int ret = x * (k + 1);
	for (int j = 0; j < k; ++ j){
		for (int i = 0; i < n - x; ++ i){
			if (mm < t[j]){
				return ret;
			}
			mm -= t[j];
			++ ret;
		}
	}
	return ret;
}

int main(){
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < k; ++ i){
		scanf("%d", &t[i]);
		sum += t[i];
	}
	std::sort(t, t + k);
	int ans = 0;
	for (int i = 0; i <= n; ++ i){
		ans = std::max(ans, solve(i));
	}
	return printf("%d\n", ans), 0;
}