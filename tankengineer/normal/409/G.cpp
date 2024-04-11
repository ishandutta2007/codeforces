#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
double x[N], y[N];

int main() {
	int n;
	scanf("%d", &n);
	double ans = 5;
	vector<pair<double, double> > p;
	for (int i = 0; i < n; ++i) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		ans += y / n;
	}
	printf("%.3f\n", ans);
	return 0;
}