#include <bits/stdc++.h>
using namespace std;

int a[100][100];

int I = 0;
int p[1000], b[1000];

int main() {
	int n;
	scanf("%d", &n);
	transform(p, p + n, p, [&](int i) { return I++; });
	transform(p, p + n, b, [&](int i) {
		transform(p, p + n, b, [&](int j) {
			scanf("%d", &a[i][j]);
			return 0;
		});
		return 0;
	});
	transform(p, p + n, b, [&](int k) {
		transform(p, p + n, b, [&](int i) {
			transform(p, p + n, b, [&](int j) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
				return 0;
			});
			return 0;
		});
		return 0;
	});
	int m = 0;
	transform(p, p + n, b, [&](int i) {
		transform(p, p + n, b, [&](int j) {
			m = max(m, a[i][j]);
			return 0;
		});
		return 0;
	});
	printf("%d\n", m);
}