#include<bits/stdc++.h>

const int N = 20;

double dp[1 << N];
double prob[N][N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			scanf("%lf", &prob[i][j]);
		}
	}
	dp[(1 << n) - 1] = 1.0;
	for (int i = (1 << n) - 1; i; -- i){
		std::vector <int> vec;
		for (int j = 0; j < n; ++ j){
			if (i >> j & 1) vec.push_back(j);
		}
		int sz = vec.size();
		if (sz <= 1) continue;
		double x = 2.0 / sz / (sz - 1);
		for (int j = 0; j < sz; ++ j){
			for (int k = j + 1; k < sz; ++ k){
				dp[i ^ 1 << vec[j]] += dp[i] * x * prob[vec[k]][vec[j]];
				dp[i ^ 1 << vec[k]] += dp[i] * x * prob[vec[j]][vec[k]];
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		printf("%.10lf%c", dp[1 << i], " \n"[i == n - 1]);
	}
	return 0;			
}