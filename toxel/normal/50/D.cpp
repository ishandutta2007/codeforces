#include<bits/stdc++.h>

const int N = 110;
const double EPS = 1e-10;

inline int sig(double p){return (p > EPS) - (p < -EPS);}
inline double sqr(double p){return p * p;}

double dp[N];
int x[N], y[N];

int main(){
	int n, k, eps;
	scanf("%d%d%d", &n, &k, &eps);
	int x0, y0;
	scanf("%d%d", &x0, &y0);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &x[i], &y[i]);
	}
	double left = 0, right = 1e4;
	for (int zzh = 0; zzh < 100; ++ zzh){
		double mid = (left + right) / 2;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; ++ i){
			double dis = std::sqrt(sqr(x[i] - x0) + sqr(y[i] - y0));
			double prob;
			if (sig(dis - mid) <= 0){
				prob = 1.0;
			}
			else{
				prob = sig(mid) ? std::exp(1 - sqr(dis) / sqr(mid)) : 0.0;
			}
			for (int j = N - 2; j >= 0; -- j){
				dp[j + 1] += dp[j] * prob;
				dp[j] *= 1 - prob;
			}
		}
		double sum = 0;
		for (int i = k; i < N; ++ i){
			sum += dp[i];
		}
		if (sum * 1e3 >= 1000 - eps){
			right = mid;
		}
		else{
			left = mid;
		}
	}
	printf("%.10lf\n", left);
	return 0;
}