#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

using ll = long long;
inline ll read() {
	ll ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100100;
const ll inf = 4e18;
inline void chkmin (ll &x, ll y) { x = min(x, y); }
inline void chkmax (ll &x, ll y) { x = max(x, y); }

int n;
ll a[MAXN][3];

ll X, Y, Z;
bool check (ll lim) {
	int i, j, k;
	ll L[4], R[4];
	for (i = 0; i < 4; i++) L[i] = -inf, R[i] = inf;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 8; j++) {
			ll sum = lim;
			for (k = 0; k < 3; k++) sum += (((j >> k) & 1) ? -1 : 1) * a[i][k];
			const int pc = __builtin_popcount(j);
			if (pc == 0) chkmin(R[3], sum);
			else if (pc == 3) chkmax(L[3], -sum);
			else if (pc == 1) {
				for (k = 0; k < 3; k++) if ((j >> k) & 1) break;
				chkmin(R[k], sum);
			}
			else {
				for (k = 0; k < 3; k++) if (!((j >> k) & 1)) break;
				chkmax(L[k], -sum);
			}
		}
	}
	for (int par = 0; par <= 1; par++) {
		ll savL[4], savR[4];
		for (i = 0; i < 4; i++) savL[i] = L[i], savR[i] = R[i];
		#define fail { for (i = 0; i < 4; i++) L[i] = savL[i], R[i] = savR[i]; continue; }
		for (i = 0; i < 4; i++) {
			if ((L[i] & 1) != par) ++L[i];
			if ((R[i] & 1) != par) --R[i];
			if (L[i] > R[i]) break;
		}
		if (i < 4) fail;
		ll A = L[0], B = L[1], C = L[2];
		if (A + B + C > R[3]) fail;
		auto up = [&](ll x) { return x + ((x & 1) != par); };
		if (A + B + C < L[3]) {
			ll d = min(up(L[3] - (A + B + C)), R[0] - L[0]);
			A += d;
			if (A + B + C < L[3]) {
				ll dd = min(up(L[3] - (A + B + C)), R[1] - L[1]);
				B += dd;
				if (A + B + C < L[3]) {
					ll ddd = min(up(L[3] - (A + B + C)), R[2] - L[2]);
					C += ddd;
					if (A + B + C < L[3]) fail;
				}
			}
		}
		X = (B + C) >> 1, Y = (A + C) >> 1, Z = (A + B) >> 1;
		return 1;
	}
	return 0;
}

int main () {
	int T = read(); while (T--) {
		n = read(); int i, j;
		for (i = 1; i <= n; i++) for (j = 0; j < 3; j++) a[i][j] = read();
		ll L = 0, R = 3e18, ans = -1;
		while (L <= R) {
			ll mid = (L + R) >> 1;
			if (check(mid)) ans = mid, R = mid - 1;
			else L = mid + 1;
		}
		check(ans);
		printf("%lld %lld %lld\n", X, Y, Z);
	}
	return 0;
}