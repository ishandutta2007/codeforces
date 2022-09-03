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

int x[300000], y[300000], a[300000], b[300000], c[300000];
ll d[300000], w[300000];

ll vect (int x1, int y1, int x2, int y2) {
	re (ll)x1 * y2 - (ll)x2 * y1;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d%d", &x[i], &y[i]);
		x[2 * n + i] = x[n + i] = x[i];
		y[2 * n + i] = y[n + i] = y[i];
	}	
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		int cx, cy;
		scanf ("%d%d", &cx, &cy);
		int pc = 0, nc = 0;
		for (int j = 0; j < n; j++) {
			ll tmp = vect (x[j] - cx, y[j] - cy, x[j + 1] - cx, y[j + 1] - cy);
			pc += int (tmp > 0);
			nc += int (tmp < 0);
		}
		if (pc && nc) printf ("0\n"); else {
			a[0] = 0;
			while (vect (x[a[0] + 1] - x[0], y[a[0] + 1] - y[0], cx - x[0], cy - y[0]) < 0) a[0]++;
			b[0] = a[0];
			while (vect (x[b[0]] - x[0], y[b[0]] - y[0], cx - x[0], cy - y[0]) < 0) b[0]++;
			for (int i = 1; i < 2 * n; i++) {
				a[i] = a[i - 1]; b[i] = b[i - 1];
				while (vect (x[a[i] + 1] - x[i], y[a[i] + 1] - y[i], cx - x[i], cy - y[i]) < 0) a[i]++;
				while (vect (x[b[i]] - x[i], y[b[i]] - y[i], cx - x[i], cy - y[i]) < 0) b[i]++;
			}
			c[0] = b[0];
			while (a[0] + n >= b[c[0]]) c[0]++;
			for (int i = 1; i < n; i++) {
				c[i] = c[i - 1];
				while (a[i] + n >= b[c[i]]) c[i]++;
			}
			d[2 * n - 1] = 0;
			for (int i = 2 * n - 2; i >= 0; i--) {
				d[i] = d[i + 1] + (a[i + 1] - a[i]);
				w[i] = w[i + 1] + (ll)(a[i + 1] - a[i]) * (2 * n - i);
			}
			ll ans = 0;
			for (int i = 0; i < n; i++) {
				int j = b[i];
				int k = a[j];
				int s = a[i] + n - k;
				if (s <= 0) continue;
				ll tmp;
				if (b[i] + 1 == c[i]) tmp = 0; else tmp = w[b[i]] - w[c[i] - 1] - (d[b[i]] - d[c[i] - 1]) * (2 * n - c[i] + 1);
				ans += (ll)s * (c[i] - b[i]) - tmp;
			}
			cout << ans / 3 << endl;
		}
			
	}
	return 0;
}