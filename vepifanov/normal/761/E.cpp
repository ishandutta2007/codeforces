#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0,- 1};

int n;
int m;
int x[30];
int y[30];
vi v[30];

int go (int i, int cx, int cy, int p, int r, int step) {
	x[i] = cx;
	y[i] = cy;
	for (int j = 0; j < sz (v[i]); j++) {
		if (v[i][j] == p) continue;
		r = (r + 1) % 4;
		go (v[i][j], cx + dx[r] * step, cy + dy[r] * step, i, r ^ 2, step / 2);
	}
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i + 1 < n; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	for (int i = 0; i < n; i++)
		if (sz (v[i]) > 4) {
			printf ("NO\n");
			re 0;
		}
	printf ("YES\n");
	x[0] = y[0] = 0;
	for (int i = 0; i < sz (v[0]); i++) go (v[0][i], dx[i] << 29, dy[i] << 29, 0, i ^ 2, 1 << 28);
	for (int i = 0; i < n; i++) printf ("%d %d\n", x[i], y[i]);
	return 0;
}