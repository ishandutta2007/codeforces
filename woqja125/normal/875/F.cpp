#include<stdio.h>
#include<algorithm>
struct E {
	int w, x, y;
	bool operator<(const E &A) const {
		return w < A.w;
	}
} d[200010];
int n, m;
int p[200010];
int chk[200010];
int R(int x) {
	if (p[x] == x) return x;
	else return p[x] = R(p[x]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)scanf("%d%d%d", &d[i].x, &d[i].y, &d[i].w);
	std::sort(d + 1, d + m + 1);
	long long ans = 0;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = m; i >= 1; i--) {
		int x = d[i].x;
		int y = d[i].y;
		x = R(x);
		y = R(y);
		if (x != y && chk[x] + chk[y] <= 1) {
			p[x] = y;
			chk[y] += chk[x];
			ans += d[i].w;
		}
		else if(x == y && chk[x] == 0) {
			chk[x] = 1;
			ans += d[i].w;
		}
	}
	printf("%d\n", ans);
	return 0;
}