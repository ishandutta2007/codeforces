#include <bits/stdc++.h>
using namespace std;
const int N = 128;
struct mat {
	double a[N][N];
	mat() {memset(a, 0, sizeof(a));}
};
mat operator * (const mat &a, const mat &b) {
	mat c = mat();
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < N; ++ j) {
			for (int k = 0; k < N; ++ k) {
				c.a[i][j] += a.a[i][k] * b.a[k][j];
			}
		}
	}
	return c;
}
mat mpow(mat a, int n) {
	mat res = a;
	-- n;
	while (n) {
		if (n & 1) res = res * a;
		a = a * a;
		n >>= 1;
	}
	return res;
}
double P[N];
int main() {
	int n, m;
	scanf("%d%d", &m, &n);
	mat L = mat(), R = mat();
	L.a[0][0] = 1.;
	for (int i = 0; i <= n; ++ i) scanf("%lf", &P[i]);
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < N; ++ j) {
			R.a[i][j] = P[i ^ j];
		}
	}
	mat ans = L * mpow(R, m);
	printf("%.10f\n", 1. - ans.a[0][0]);
}