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

int n;
int m;
vii v;
ii w[10000];

bool l1 (ii a, ii b) {
	re a.fi * a.fi + a.se * a.se < b.fi * b.fi + b.se * b.se;
}

bool l2 (ii a, ii b) {
	re atan2 (a.se + .0, a.fi + .0) < atan2 (b.se + .0, b.fi + .0) - 1e-5;
}

int main() {
	scanf ("%d", &n);
	for (int a = 0; a < 200; a++)
		for (int b = 1; b < 200; b++)
			v.pb (mp (a, b));
	sort (all (v), l1);
	int r = 0;
	for (int i = 0; i < sz (v); i++)
		if (i == 0 || l1 (v[i - 1], v[i]))
			v[r++] = v[i];
	int s = 0;
	for (int i = 0; i < n; i++) s += v[i].fi + v[i].se;
	if (s & 1)
		for (int i = n - 1; i >= 0; i--)
			if (((v[i].fi + v[i].se) & 1) != ((v[n].fi + v[n].se) & 1)) {
				for (int j = i; j < n; j++) v[j] = v[j + 1];
				break;
			}
	int sx = 0, sy = 0;
	for (int i = n - 1; i >= 0; i--) {
		int nx = 1e9, ny = 1e9;
		for (int p = 1; p >= -1; p -= 2)
			for (int q = 1; q >= -1; q -= 2) {
				int mx = sx + v[i].fi * p, my = sy + v[i].se * q;
				if ((ll)mx * mx + (ll)my * my < (ll)nx * nx + (ll)ny * ny) {
					w[i].fi = v[i].fi * p;
					w[i].se = v[i].se * q;
					nx = mx;
					ny = my;
				}
				mx = sx + v[i].se * p;
				my = sy + v[i].fi * q;
				if ((ll)mx * mx + (ll)my * my < (ll)nx * nx + (ll)ny * ny) {
					w[i].fi = v[i].se * p;
					w[i].se = v[i].fi * q;
					nx = mx;
					ny = my;
				}
			}
		sx += w[i].fi;
		sy += w[i].se;
	}
	sort (w, w + n, l2);
	printf ("YES\n");
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		printf ("%d %d\n", x, y);
		x += w[i].fi;
		y += w[i].se;
	}
	return 0;
}