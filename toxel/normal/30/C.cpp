#include<bits/stdc++.h>

typedef std::pair <std::pair <int, int>, std::pair <int, double>> piiid;
const int N = 1010;
inline int sqr(int n){return n * n;}

piiid p[N];
double dp[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		int x, y, t;
		double p;
		scanf("%d%d%d%lf", &x, &y, &t, &p);
		::p[i] = {{t, x}, {y, p}};
	}
	std::sort(p, p + n);
	for (int i = 0; i < n; ++ i){
		double max = 0;
		for (int j = 0; j < i; ++ j){
			if (p[i].first.first - p[j].first.first >= 10000 || sqr(p[i].first.second - p[j].first.second) + 
				sqr(p[i].second.first - p[j].second.first) <=
				sqr(p[i].first.first - p[j].first.first)){
				max = std::max(max, dp[j]);
			}
		}
		dp[i] = max + p[i].second.second;
	}
	double max = 0;
	for (int i = 0; i < n; ++ i){
		max = std::max(max, dp[i]);
	}
	printf("%.10lf\n", max);
	return 0;
}