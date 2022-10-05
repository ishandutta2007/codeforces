#include<bits/stdc++.h>

const int N = 100010;
const double eps = 1e-9;

double root(double b, double c){
	return (-b + sqrt(std::max(0.0, b * b - 4 * c))) / 2;
}

double p[2][N], ans[2][N];
int n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%lf", &p[0][i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%lf", &p[1][i]);
	}
	double pre1 = 0, pre2 = 0;
	for (int i = 0; i < n; ++ i){
		double b = p[0][i] + p[1][i];
		ans[1][i] = root(pre2 - pre1 - b, p[0][i] - pre2 * b);
		ans[0][i] = b - ans[1][i];
		pre1 += ans[0][i];
		pre2 += ans[1][i];
	}
	for (int i = 0; i < n; ++ i){
		printf("%.10lf%c", ans[0][i], " \n"[i == n - 1]);
	}
	for (int i = 0; i < n; ++ i){
		printf("%.10lf%c", ans[1][i], " \n"[i == n - 1]);	
	}
	return 0;
}