#include <bits/stdc++.h>
using namespace std;

const double pi = atan2(0, -1);

struct Point{
	int x, y;
	double alpha;
	Point (int _x = 0, int _y = 0) : x(_x), y(_y) {}
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	friend long long operator * (const Point &a, const Point &b) {
		return 1ll * a.x * b.x + 1ll * a.y * b.y;
	}
	friend long long operator / (const Point &a, const Point &b) {
		return 1ll * a.x * b.y - 1ll * a.y * b.x;
	}
	bool operator () (const Point &a, const Point &b) {
		int ta, tb;
		if (a.y < 0 || (a.y == 0 && a.x > 0)) ta = 0;
		else ta = 1;
		if (b.y < 0 || (b.y == 0 && b.x > 0)) tb = 0;
		else tb = 1;
		if (ta != tb) return ta < tb;
		return a / b > 0;
	}
}P[5005], Q[10005];

int n, cnt;
long long ans;

int main() {
	
//	freopen("E.in", "r", stdin);
	
//	printf("%lf\n", atan2(0, -1));
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i) scanf("%d%d", &P[i].x, &P[i].y);
	for (int i = 1; i <= n; ++ i) {
		
//		printf("cent (%d %d)\n", P[i].x, P[i].y);
		
		cnt = 0;
		for (int j = 1; j <= n; ++ j) {
			if (j != i) {
				Q[++ cnt] = P[j] - P[i];
				Q[cnt].alpha = atan2(Q[cnt].y, Q[cnt].x);
			}
		}
		sort(Q + 1, Q + 1 + cnt, Point());
		for (int j = 1; j <= cnt; ++ j) {
			
//			printf("%d %d %lf\n", Q[j].x, Q[j].y, Q[j].alpha);
			
			Q[cnt + j] = Q[j];
			Q[cnt + j].alpha += 2 * pi;
		}
		int t = 1;
		for (int j = 1; j <= cnt; ++ j) {
			while (Q[t].alpha <= Q[j].alpha + 1.5 * pi && Q[j] / Q[t] >= 0) ++ t;
//			printf("[%d, %d)\n", j, t);
			ans += 1ll * (t - j - 1) * (t - j - 2) * (t - j - 3) / 3 / 2;
		}
	}
	
//	printf("%lld\n", ans);
	
	ans = 5ll * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 5 / 4 / 3 / 2 - ans;
	printf("%lld\n", ans);
	return 0;
}