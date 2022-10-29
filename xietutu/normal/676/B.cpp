#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
using namespace std;
const double eps = 1e-8;
int n, full, t;
double a[13][13], b[13][13];
int dcmp(double x) {
	if (fabs(x) <= eps) return 0;
	return x > 0 ? 1 : -1;
}
void work() {
	memset(b, 0, sizeof(b));
	b[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		bool flag = false;
		for (int j = 1; j <= i; ++j) {
			if (dcmp(a[i][j] + b[i][j] - 1.0) > 0) {
				b[i + 1][j] += (a[i][j] + b[i][j] - 1) / 2;
				b[i + 1][j + 1] += (a[i][j] + b[i][j] - 1) / 2;	
				flag = true;
			}
			a[i][j] = min(1.0, a[i][j] + b[i][j]);
		}
		if (!flag) break;
	}
}
int main() {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= t; ++i) work();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			if (dcmp(a[i][j] - 1) == 0) ++full;
	printf("%d\n", full);
}