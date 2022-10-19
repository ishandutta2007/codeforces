#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

int query(int x, int y) {
	cout << x <<" " << y << endl;
	fflush(stdout);
	cin >> x;
	if(!x) exit(0);
	return x;
}

void solve(int xl, int xm, int xr, int yl, int ym, int yr) {
	// [xl, xm) * [yl, ym)
	// [xm, xr) * [yl, ym)
	// [xl, xm) * [ym, yr)
	long double S1 = (long double)(xm - xl) * (ym - yl), S2 = (long double)(xr - xm) * (ym - yl), S3 = (long double)(xm - xl) * (yr - ym);
	if(S1 + S2 < S3) {
		int it = (xl + xm) >> 1;
		int now = query(it, ym);
		if(now == 3) {
			solve(xl, it, xr, yl, ym, yr);
		}
		else if(now == 1) {
			solve(it + 1, xm, xr, yl, ym, yr);
		}
		else solve(xl, xm, xm, ym + 1, yr, yr);
		return;
	}
	else if(S1 + S3 < S2) {
		int it = (yl + ym) >> 1;
		int now = query(xm, it);
		if(now == 3) {
			solve(xl, xm, xr, yl, it, yr);
		}
		else if(now == 2) {
			solve(xl, xm, xr, it + 1, ym, yr);
		}
		else solve(xm + 1, xr, xr, yl, ym, ym);
		return;
	}
	else {
		int X = (xl + xm) >> 1, Y = (yl + ym) >> 1;
		int now = query(X, Y);
		if(now == 1) {
			solve(X + 1, xm, xr, yl, ym, yr);
		}
		else if(now == 2) solve(xl, xm, xr, Y + 1, ym, yr);
		else solve(xl, X, xr, yl, Y, yr);
		return;
	}
}

main(void) {
	cin >> n;
	solve(0, n + 1, n + 1, 0, n + 1, n + 1);
}