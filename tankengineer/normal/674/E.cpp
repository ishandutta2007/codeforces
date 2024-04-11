#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int B = 61;

const int N = 500005;

int n;

long double f[N][B];

int fa[N];

int main() {
	n = 1;
	fa[0] = -1;
	for (int i = 0; i < B; ++i) {
		f[0][i] = 1;
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int op, v;
		scanf("%d%d", &op, &v);
		--v;
		if (op == 1) {
			int u = n++;
			fa[u] = v;
			for (int i = 0; i < B; ++i) {
				f[u][i] = 1;
			}
			long double oldp = f[v][0], newp = (f[v][0] /= 2);
			u = v;
			v = fa[v];
			for (int j = 1; j < B && v != -1; ++j) {
				long double noldp = f[v][j];
				f[v][j] = f[v][j] / (0.5 + 0.5 * oldp) * (0.5 + 0.5 * newp);
				oldp = noldp;
				newp = f[v][j];
				u = v;
				v = fa[v];
			}
		} else {
			long double ans = 0;
			for (int i = 1; i < B; ++i) {
				ans += (f[v][i] - f[v][i - 1]) * i;
			}
			printf("%.12f\n", (double)ans);
		}
	}
	return 0;
}