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

int n, ct;
int m, k, kx[2000], ky[2000], r[2000], x[2000], y[2000], p[2000], q[2000], d[2000], was[2000];

int main() {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) scanf ("%d%d", &kx[i], &ky[i]);
	for (int i = 0; i < m; i++) scanf ("%d%d%d", &r[i], &x[i], &y[i]);
	for (int i = 0; i < m; i++) {
		p[i] = -1;
		for (int j = 0; j < m; j++)
			if (r[j] > r[i] && (p[i] == -1 || r[j] < r[p[i]])) {
				ll d = (ll)(x[i] - x[j]) * (x[i] - x[j]) + (ll)(y[i] - y[j]) * (y[i] - y[j]);
				if (d < (ll)(r[j] - r[i]) * (r[j] - r[i]))
					p[i] = j;
			}
	}
	for (int i = 0; i < n; i++) {
		q[i] = -1;
		for (int j = 0; j < m; j++)
			if (q[i] == -1 || r[j] < r[q[i]]) {
				ll d = (ll)(kx[i] - x[j]) * (kx[i] - x[j]) + (ll)(ky[i] - y[j]) * (ky[i] - y[j]);
				if (d < (ll)r[j] * r[j])
					q[i] = j;
			}
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		ct++;
		int sa = 0, sb = 0, s = 3 * m;
		a = q[a];
		b = q[b];
		while (a != -1) {
			was[a] = ct;
			d[a] = sa;
			sa++;
			a = p[a];
		}
		while (b != -1) {
			if (was[b] == ct) {
				s = sb + d[b];
				break;
			}
			sb++;
			b = p[b];
		}
		s = min (s, sa + sb);
		printf ("%d\n", s);
	}
	return 0;
}