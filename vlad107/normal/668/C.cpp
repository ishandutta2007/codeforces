#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>
 
using namespace std;

const int N = 1e6 + 100;
const double EPS = 1e-11;

int n;
double u[N], v[N], a[N], b[N];

long double solve(long double b, long double c) {
	long double d = b * b - 4 * c;
	if (d < EPS) d = 0;
	d = sqrt(d);
	return (-b + d) * 0.5;
}

void checkAns() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			u[max(i, j)] -= a[i] * b[j];
			v[min(i, j)] -= a[i] * b[j];
		}
	}
	for (int i = 0; i < n; i++) {
		assert(fabs(u[i]) < EPS);
		assert(fabs(v[i]) < EPS);
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lf", &u[i]);
	for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
	long double sa = 0, sb = 0;
	for (int i = 0; i < n; i++) {
		long double ss = u[i] + v[i];
		long double res;
		res = solve(-sb + sa - u[i] - v[i], u[i] - (u[i] + v[i]) * sa);
		a[i] = res;
		b[i] = u[i] + v[i] - a[i];
		sa += a[i];
		sb += b[i];
	}
	for (int i = 0; i < n; i++) printf("%.10lf ", (double)a[i]);
	puts("");
	for (int i = 0; i < n; i++) printf("%.10lf ", (double)b[i]);
	puts("");
//	checkAns();
}