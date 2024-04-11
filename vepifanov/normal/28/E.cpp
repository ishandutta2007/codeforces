#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

const int MAX = 300;
const ld eps = 1e-13;
const ld eps2 = 1e-11;

int n;
int m;
int x1, y1, z1, x2, y2, z2, f, x[10001], y[10001];

int vect (int x1, int y1, int x2, int y2) {
	re x1 * y2 - x2 * y1;
}

int scal (int x1, int y1, int x2, int y2) {
	re x1 * x2 + y1 * y2;
}

int _in (ll xx, ll yy) {
	ll sum = 0, rl = 0;
	for (int i = 0; i < n; i++) {
		sum += abs ((x[i] - xx) * (y[i + 1] - yy) - (x[i + 1] - xx) * (y[i] - yy));
		rl += x[i] * y[i + 1] - x[i + 1] * y[i];
	}
	if (sum != abs (rl)) re 0;
	re 1;
}

int _in2 (ld xx, ld yy) {
	ld sum = 0, rl = 0;
	for (int i = 0; i < n; i++) {
		sum += fabs ((x[i] - xx) * (y[i + 1] - yy) - (x[i + 1] - xx) * (y[i] - yy));
		rl += x[i] * y[i + 1] - x[i + 1] * y[i];
	}
	if (fabs (sum - abs (rl)) > eps) re 0;
	re 1;
}

int cross (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4, ld *t, int r1, int r2) {
	ll a = x2 - x1;
	ll b = x3 - x4;
	ll c = x3 - x1;
	ll d = y2 - y1;
	ll e = y3 - y4;
	ll f = y3 - y1;
	if (a * e - b * d != 0) {
		ll Q = (a * e - b * d);
		ll T = (c * e - b * f);
		ll S = (a * f - c * d);
		if (Q < 0) { T = -T; S = -S; Q = -Q; }
		int ok = 1;
		if (r1 & 1) ok &= int (T >= 0);
		if (r1 & 2) ok &= int (T <= Q);
		if (r2 & 1) ok &= int (S >= 0);
		if (r2 & 2) ok &= int (S <= Q);
		if (ok) {
			*t = (ld)T / Q;
			re 1;
		}
	}
	re 0;
}

int cross2 (ld x1, ld y1, ld x2, ld y2, ld x3, ld y3, ld x4, ld y4, ld *t, int r1, int r2) {
	ld a = x2 - x1;
	ld b = x3 - x4;
	ld c = x3 - x1;
	ld d = y2 - y1;
	ld e = y3 - y4;
	ld f = y3 - y1;
	if (a * e - b * d != 0) {
		ld Q = (a * e - b * d);
		ld T = (c * e - b * f);
		ld S = (a * f - c * d);
		if (Q < 0) { T = -T; S = -S; Q = -Q; }
		int ok = 1;
		if (r1 & 1) ok &= int (T > -eps * Q);
		if (r1 & 2) ok &= int (T < Q * (1 + eps));
		if (r2 & 1) ok &= int (S > -eps * Q);
		if (r2 & 2) ok &= int (S < Q * (1 + eps));
		if (ok) {
			*t = (ld)T / Q;
			re 1;
		}
	}
	re 0;
}

int check (ll x1, ll y1, ll x2, ll y2, ld *t, int r1, int r2) {
	if (_in (x1, y1)) {
		*t = 0;
		re 1;
	}
	int ok = 0;
	ld nt;
	*t = 1e20;
	for (int i = 0; i < n; i++)
		if (cross (x1, y1, x2, y2, x[i], y[i], x[i + 1], y[i + 1], &nt, r1, r2)) {
			*t = min (*t, nt);
			ok = 1;
		}
	re ok;
}

int check2 (ld x1, ld y1, ld x2, ld y2, ld *t, int r1, int r2) {
	if (_in2 (x1, y1)) {
		*t = 0;
		re 1;
	}
	int ok = 0;
	ld nt;
	*t = 1e20;
	for (int i = 0; i < n; i++)
		if (cross2 (x1, y1, x2, y2, x[i], y[i], x[i + 1], y[i + 1], &nt, r1, r2)) {
			*t = min (*t, nt);
			ok = 1;
		}
	re ok;
}

int check3 (ld x1, ld y1, ld x2, ld y2, int i) {
	re int ((x[i] - x1) * (x[i] - x2) + (y[i] - y1) * (y[i] - y2) < eps);
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
	int X, Y;
	scanf ("%d%d", &X, &Y);
	for (int i = 0; i < n; i++) { x[i] -= X; y[i] -= Y; }
	x[n] = x[0];
	y[n] = y[0];
	scanf ("%d%d%d", &x1, &y1, &z1);
	scanf ("%d", &f); f = -f;
	scanf ("%d%d%d", &x2, &y2, &z2); z2 = -z2;
	int x3 = x1 * z2 + x2 * z1, y3 = y1 * z2 + y2 * z1;
	ld t1 = 1e20, t2 = 1e20, t, tt;
	if (check (0, 0, x1, y1, &t, 1, 3)) {
		check2 (x1 * t + x2 * ((z1 * t) / z2), y1 * t + y2 * ((z1 * t) / z2), x1 * t, y1 * t, &tt, 3, 3);
		tt *= ((z1 * t) / f);
		if (t1 > t + eps || fabs (t - t1) < eps && t2 > tt + eps) {
			t1 = t;
			t2 = tt;
		}
	}
	if (check (0, 0, x3, y3, &t, 1, 3)) {
		t *= z2;
		check2 (x1 * t + x2 * ((z1 * t) / z2), y1 * t + y2 * ((z1 * t) / z2), x1 * t, y1 * t, &tt, 3, 3);
		tt *= ((z1 * t) / f);
		if (t1 > t + eps || fabs (t - t1) < eps && t2 > tt + eps) {
			t1 = t;
			t2 = tt;
		}
	}
	if (vect (x1, y1, x2, y2) != 0) {
		ld T = 1e20, r;
		for (int i = 0; i < n; i++)
			if (cross (0, 0, x1, y1, x[i], y[i], x[i] - x2 * z1, y[i] - y2 * z1, &r, 1, 1)) T = min (T, r);
		if (T < 5e19) {
			ld t = T, tt;
			if (check2 (x1 * T + x2 * ((z1 * T) / z2), y1 * T + y2 * ((z1 * T) / z2), x1 * T, y1 * T, &tt, 3, 3)) {
				tt *= ((z1 * T) / f);
				if (t1 > t + eps || fabs (t - t1) < eps && t2 > tt + eps) {
					t1 = t;
					t2 = tt;
				}
                	}
		}
	}
	if (t1 > 5e19) printf ("-1 -1\n"); else printf ("%.15f %.15f\n", (double)t1, (double)t2);
	return 0;
}