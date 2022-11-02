#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const double pi = acos(-1);

const int N = 20;
int n, l, r, x[N], y[N];

double a[N];

double dp[1 << N];

int sign(double x, double eps = 1e-9) {
	return x < -eps ? -1 : x > eps;
}

double pos(int i, double p) {
	/*
	double d1 = r - p;
	if (d1 < 1e-9) {
		return r;
	}
	double d2 = sqrt(y[i] * y[i] + (x[i] - p) * (x[i] - p));
	double d3 = sqrt(y[i] * y[i] + (x[i] - r) * (x[i] - r));
	double ang1 = acos((-d1 * d1 + d2 * d2 + d3 * d3) / d2 / d3 / 2);
	if (a[i] / 180.0 * pi > ang1) {
		return r;
	}
	double ang = a[i] / 180.0 * pi - atan2(y[i], x[i] - p);
	return min((double)r, x[i] + y[i] * tan(ang));
	*/
	if (sign(x[i] - p) <= 0) {
		double ang1 = atan2(p - x[i], y[i]);
		if (sign(ang1 + a[i] - pi / 2) >= 0) {
			return r;
		} else {
			return x[i] + y[i] * tan(ang1 + a[i]);
		}
	} else {
		double ang1 = atan2(x[i] - p, y[i]);
		if (sign(a[i] - ang1) <= 0) {
			return x[i] - y[i] * tan(ang1 - a[i]);
		} else {
			return x[i] + y[i] * tan(a[i] - ang1);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%lf", x + i, y + i, a + i);
		a[i] = a[i] / 180 * pi;
	}
	for (int i = 0; i < 1 << n; ++i) {
		dp[i] = l;
	}
	double ans = 0;
	for (int i = 0; i < 1 << n; ++i) {
		dp[i] = min(dp[i], (double)r);
		ans = max(ans, dp[i] - l);
		for (int j = 0; j < n; ++j) {
			if (~i >> j & 1) {
				dp[i | (1 << j)] = max(dp[i | (1 << j)], pos(j, dp[i]));
			}
		}
	}
	printf("%.12f\n", ans);
	return 0;
}