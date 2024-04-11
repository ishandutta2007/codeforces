#include<bits/stdc++.h>

const int N = 1010;
const double eps = 1e-9;

inline double sqr(double x){return x * x;}
inline double sig(double x){return (x > eps) - (x < - eps);}

int x[N];
int n, r;
double ans[N];

int main(){
	scanf("%d%d", &n, &r);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; ++ i){
		ans[i] = r;
		for (int j = 0; j < i; ++ j){
			double y = sqr(r * 2.0) - sqr(x[i] - x[j]);
			if (sig(y) < 0) continue;
			ans[i] = std::max(ans[i], std::sqrt(y) + ans[j]);
		}
	}
	for (int i = 0; i < n; ++ i){
		printf("%.10lf%c", ans[i], " \n"[i == n - 1]);
	}
	return 0;
}