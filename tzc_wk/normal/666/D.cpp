#include <bits/stdc++.h>
using namespace std;
#define pb push_back
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
int x[5], y[5], p[5], mn = 1e9, resx[5], resy[5];
int calc(int X[4], int Y[4], int P[4]) {
	if (Y[0] != Y[1] || Y[2] != Y[3] || X[1] != X[2] || X[3] != X[0]) return 1e9;
	for (int i = 0; i < 4; i++) if (abs(X[i] - X[(i + 1) & 3]) + abs(Y[i] - Y[(i + 1) & 3]) != abs(X[0] - X[1])) return 1e9;
	if (X[0] == X[1]) return 1e9;
	for (int i = 0; i < 4; i++) {
		int sum = (X[i] == x[P[i]]) + (Y[i] == y[P[i]]);
		if (sum == 0) return 1e9;
	}
	int mx = 0;
	for (int i = 0; i < 4; i++) chkmax(mx, abs(X[i] - x[P[i]]) + abs(Y[i] - y[P[i]]));
	return mx;
}
void solve() {
	memset(resx, 0, sizeof(resx)); memset(resy, 0, sizeof(resy)); mn = 1e9;
	for (int i = 0; i < 4; i++) scanf("%d%d", &x[i], &y[i]);
	for (int rv = 0; rv < 2; rv++) {
		for (int i = 0; i < 4; i++) p[i] = i;
		do {
			for (int msk = 0; msk < 16; msk++) {
				static int nwx[5], nwy[5];
				auto upd = [&](int cst) {
					if (mn > cst) {
						mn = cst;
						for (int i = 0; i < 4; i++) {
							if (!rv) resx[p[i]] = nwx[i], resy[p[i]] = nwy[i];
							else resx[p[i]] = nwy[i], resy[p[i]] = nwx[i];
						}
					}
				};
				for (int i = 0; i < 4; i++) nwx[i] = x[p[i]], nwy[i] = y[p[i]];
				if (msk == 10) {
					nwy[0] = y[p[1]]; nwx[1] = x[p[2]]; nwy[2] = y[p[3]]; nwx[3] = x[p[0]];
					upd(calc(nwx, nwy, p));
				} else if (msk == 0) {
					int A = x[p[1]] - x[p[0]];
					vector<int> vec; vec.pb(y[p[0]] - A); vec.pb(y[p[1]] - A); vec.pb(y[p[2]]); vec.pb(y[p[3]]);
					sort(vec.begin(), vec.end()); int dw = vec[0] + vec[3] >> 1, up = dw + A;
					nwy[0] = nwy[1] = up; nwy[2] = nwy[3] = dw;
					upd(calc(nwx, nwy, p));
				} else {
					if ((~msk & 1) && (~msk >> 1 & 1)) {
						int A = abs(nwx[0] - nwx[1]);
						for (int i = 2; i <= 3; i++) if (msk >> i & 1) {
							nwx[i] = nwx[3 - i]; nwy[i ^ 1] = nwy[i];
							nwy[0] = nwy[1] = nwy[i] + A; nwx[i ^ 1] = nwx[3 - (i ^ 1)];
							break;
						}
						upd(calc(nwx, nwy, p));
					} else if ((~msk >> 2 & 1) && (~msk >> 3 & 1)) {
						int A = abs(nwx[3] - nwx[2]);
						for (int i = 0; i <= 1; i++) if (msk >> i & 1) {
							nwx[i] = nwx[3 - i]; nwy[i ^ 1] = nwy[i];
							nwy[2] = nwy[3] = nwy[i] - A; nwx[i ^ 1] = nwx[3 - (i ^ 1)];
							break;
						}
						upd(calc(nwx, nwy, p));
					}
				}
			}
		} while (next_permutation(p, p + 4));
		for (int i = 0; i < 4; i++) swap(x[i], y[i]);
	}
	if (mn > 200000000) puts("-1");
	else {
		printf("%d\n", mn);
		for (int i = 0; i < 4; i++) printf("%d %d\n", resx[i], resy[i]);
	}
}
int main() {int qu; scanf("%d", &qu); while (qu--) solve(); return 0;}