#include<bits/stdc++.h>

const int N = 100010;
const double eps = 1e-7;

int n, p;
int a[N], b[N];

bool check(double mid){
	double sum = 0;
	for (int i = 0; i < n; ++ i){
		double x = a[i] * mid - b[i];
		if (x > -eps){
			sum += x;
		}
	}
	return sum < mid * p + eps;
}

int main(){
	scanf("%d%d", &n, &p);
	long long sum = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &a[i], &b[i]);
		sum += a[i];
	}
	if (sum <= p){
		return printf("-1\n"), 0;
	}
	double left = 0, right = 1e12;
	while (right - left > eps){
		double mid = (left + right) / 2;
		if (check(mid)){
			left = mid;
		}
		else{
			right = mid;
		}
	}
	return printf("%.10lf\n", left), 0;
}