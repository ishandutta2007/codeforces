#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int n;

int a[N];

double cal(double x) {
	double mins = 0, maxs = 0, cur = 0, ret = 0;
	for (int i = 0; i < n; ++i) {
		cur += a[i] - x;
		maxs = max(maxs, cur);
		mins = min(mins, cur);
		ret = max(ret, max(maxs - cur, cur - mins));
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	double l = -1e5 - 10, r = 1e5 + 10;
	for (int i = 0; i < 100; ++i) {
		double m1 = (l + l + r) / 3, m2 = (l + r + r) / 3;
		if (cal(m1) < cal(m2)) {
			r = m2;
		} else {
			l = m1;
		}
		//printf("%.12f %.12f\n", l, r);
	}
	printf("%.12f\n", cal((l + r) / 2));
	return 0;
}