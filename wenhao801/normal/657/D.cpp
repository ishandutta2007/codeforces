#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const double eps = 1e-8;
int sgn (double x, double y = 0) { return (x - y > eps) - (x - y < -eps); }

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using pid = pair <int, ld>;
#define fr first
#define se second
const int MAXN = 150500;

ll T;
int n; pii a[MAXN];
set <pid> S;

ld p[MAXN];
bool check (ld c) {
	ll s = 0; int i, j, k; S.clear();
	for (i = 1; i <= n; i = j) {
		ll nex = s;
		for (j = i; j <= n && 1ll * a[j].fr * a[i].se == 1ll * a[j].se * a[i].fr; j++) nex += a[j].se;
		for (k = i; k < j; k++) {
			auto it = S.lower_bound({a[k].fr, -1e9});
			if (it != S.begin()) {
				--it;
				if (it->se > a[k].fr * (1 - c * nex / T)) return 0;
			}
		}
		for (k = i; k < j; k++) {
			const ld val = a[k].fr * (1 - c * (s + a[k].se) / T);
			auto it = S.lower_bound({a[k].fr, -1e9});
			if (it != S.end() && it->fr == a[k].fr && it->se > val) continue;
			if (it != S.begin()) {
				--it;
				if (it->fr <= a[k].fr && it->se > val) continue;
				++it;
			}
			while (it != S.end()) {
				auto nex = it; ++nex;
				if (it->se < val) S.erase(it); else break;
				it = nex;
			}
			S.insert({a[k].fr, val});
		}
		for (k = i; k < j; k++) {
			auto it = S.lower_bound({a[k].fr, -1e9});
			if (it != S.begin()) {
				--it;
				if (it->se > a[k].fr * (1 - c * nex / T)) return 0;
			}
		}
		s = nex;
	}
	return 1;
}

int main() {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) a[i].fr = read();
	for (i = 1; i <= n; i++) a[i].se = read(), T += a[i].se;
	sort(a + 1, a + n + 1, [](pii u, pii v) { return 1ll * u.fr * v.se > 1ll * u.se * v.fr; });
	double L = 0, R = 1, ans = -1;
	while (R - L > eps) {
		double mid = (L + R) / 2;
		if (check(mid)) ans = mid, L = mid + eps; else R = mid - eps;
	}
	printf("%.7lf\n", ans);
	return 0;
}