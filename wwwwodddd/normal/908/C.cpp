#include <bits/stdc++.h>
using namespace std;
int n, r;
int x[1020];
double y[1020];
int main() {
	scanf("%d%d", &n, &r);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; i++) {
		double yy = r;
		for (int j = 0; j < i; j++) {
			if (abs(x[j] - x[i]) <= r * 2) {
				yy = max(yy, y[j] + sqrt(r * r * 4 - (x[j] - x[i]) * (x[j] - x[i])));
			}
		}
		y[i] = yy;
	}
	for (int i = 0; i < n; i++) {
		printf("%.12f%c", y[i], i == n - 1 ? '\n' : ' ');
	}
	return 0;
}