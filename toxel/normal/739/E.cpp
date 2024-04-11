#include<bits/stdc++.h>
#define ll long long

const int N = 2010;
const int M = 1000000;
const double eps = 1e-9;

//int p[N], u[N], q[N];
double p[N], u[N], q[N];
int n, a, b;
std::pair <double, int> dp[N][N];

std::pair <double, int> max(std::pair <double, int> p1, std::pair <double, int> p2){
	if (p2.first > p1.first + eps){
		return p2;
	}
	return p1;
}

int check(double mid){
	for (int i = 1; i <= n; ++ i){
		for (int j = 0; j <= a; ++ j){
			dp[i][j] = {0, 0};
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], {dp[i - 1][j].first + u[i] - mid, dp[i - 1][j].second + 1});
			if (j){
				dp[i][j] = max(dp[i][j], {dp[i - 1][j - 1].first + p[i], dp[i - 1][j - 1].second});
				dp[i][j] = max(dp[i][j], {dp[i - 1][j - 1].first + q[i] - mid, dp[i - 1][j - 1].second + 1});
			}
		}
	}
	return dp[n][a].second;
}

int main(){
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; ++ i){
		//double f;
		//scanf("%lf", &f);
		//p[i] = f * M;
		scanf("%lf", &p[i]);
	}
	for (int i = 1; i <= n; ++ i){
		/*double f;
		scanf("%lf", &f);
		u[i] = f * M;
		q[i] = p[i] + u[i] - 1ll * p[i] * u[i] / M;*/
		scanf("%lf", &u[i]);
		q[i] = p[i] + u[i] - p[i] * u[i];
	}
	double left = -1e4, right = 1e4;
	while (right - left > eps){
		double mid = (left + right) / 2;
		if (check(mid) < b){
			right = mid;
		}
		else{
			left = mid;
		}
	}
	return printf("%.10lf\n", (dp[n][a].first + left * b)), 0;
}