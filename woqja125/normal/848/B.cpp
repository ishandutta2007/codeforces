#include<stdio.h>
#include<algorithm>
using namespace std;
struct D {
	int g, x, t, i;
	bool operator<(const D &A)const {
		if (x - t == A.x - A.t) return g == A.g ? (x<A.x) : (g<A.g);
		return x - t < A.x - A.t;
	}
} in[100001];
int ans[100001][2];
int main() {
	int n, w, h;
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &in[i].g, &in[i].x, &in[i].t);
		in[i].i = i;
	}
	sort(in + 1, in + n + 1);
	int j, k, a, b;
	for (int i = 1; i <= n; i = j) {
		a = b = 0;
		for (j = i; j<=n && in[i].x - in[i].t == in[j].x - in[j].t; j++) if (in[j].g == 1) a++; else b++;
		k = i + a;
		int m = a > b ? b : a;
		for (int d = k - 1; d >= i; d--) {
			if (k - d <= m) {
				ans[in[d].i][0] = w;
				ans[in[d].i][1] = in[k + (k - 1 - d)].x;
			}
			else {
				ans[in[d].i][0] = in[d + m].x;
				ans[in[d].i][1] = h;
			}
		}
		for (int d = j - 1; d >= k; d--) {
			if (j - d <= m) {
				ans[in[d].i][0] = in[i + (j - 1 - d)].x;
				ans[in[d].i][1] = h;
			}
			else {
				ans[in[d].i][0] = w;
				ans[in[d].i][1] = in[d + m].x;;
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}