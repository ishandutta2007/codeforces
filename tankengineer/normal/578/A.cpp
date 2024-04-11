#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const double INF = 1e100;

double solve(int x, int bar) {
	if (x < 0) {
		return INF;
	}
	if (x == 0) {
		return 2 * bar;
	}
	if (2 * bar > x) {
		return INF;
	}
	int k = x / (2 * bar);
	while (x / (k + 1) >= 2 * bar) {
		++k;
	}
	return (double)x / k / 2;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	double ans = min(solve(a - b, b), solve(a + b, b));
	if (ans > 1e90) {
		printf("-1\n");
		return 0;
	}
	printf("%.12f\n", ans);
	return 0;
}