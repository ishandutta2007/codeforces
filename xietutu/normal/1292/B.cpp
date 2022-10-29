#include <bits/stdc++.h>
using namespace std;

long long x[105], y[105], ax, ay, bx, by, sx, sy, t, ans;

int main() {
	scanf("%lld%lld%lld%lld%lld%lld", x, y, &ax, &ay, &bx, &by);
	scanf("%lld%lld%lld", &sx, &sy, &t);
	int n;
	for (n = 1; ; ++ n) {
		x[n] = x[n - 1] * ax + bx;
		y[n] = y[n - 1] * ay + by;
		if (x[n] > sx + t) break;
		if (y[n] > sy + t) break;
	}
	-- n;
	ans = 0;
	for (int i = 0; i <= n; ++ i) {
		long long base_t = abs(sx - x[i]) + abs(sy - y[i]), cost, tmp;
		if (base_t > t) continue;
		// go back
		tmp = 1;
		cost = base_t;
		for (int j = i - 1; j >= 0; -- j) {
			cost += abs(x[j + 1] - x[j]) + abs(y[j + 1] - y[j]);
			if (cost > t) break;
			++ tmp;
		}
		ans = max(ans, tmp);
		// go foward
		tmp = 1;
		cost = base_t;
		for (int j = i + 1; j <= n; ++ j) {
			cost += abs(x[j - 1] - x[j]) + abs(y[j - 1] - y[j]);
			if (cost > t) break;
			++ tmp;
		}
		ans = max(ans, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}