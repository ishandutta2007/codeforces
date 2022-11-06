#include<cstdio>
#include<cmath>
using namespace std;
int x[1001];
double y[1001];
int main() {
	int n, r;
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", x + i);
		double m = r;
		for (int j = 1; j < i; j++) {
			if (x[j] < x[i] - 2*r || x[j] > x[j] + 2*r) continue;
			double dy = 4.0*r*r - (x[j] - x[i])*(x[j] - x[i]);
			dy = sqrt(dy);
			if (m < y[j] + dy) m = y[j] + dy;
		}
		y[i] = m;
		printf("%.10lf ", y[i]);
	}
	return 0;
}