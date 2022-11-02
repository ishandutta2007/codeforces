#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 5005;
int n;
double x[N], y[N], z[N];

double sqr(const double x) {
	return x * x;
}

double dist(const int i, const int j) {
	return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]));
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf%lf", x + i, y + i, z + i);
	}
	double ans = 1e20;
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ans = min(ans, dist(i, j) + dist(0, i) + dist(0, j));
		}
	}
	printf("%.12f\n", ans / 2);
	return 0;
}