#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
int good[1024];
int was[1024];
int kkk = 0;

void ask (int x) {
	kkk++;
	printf ("? %d\n", x + 1); fflush (stdout);
	char h[5];
	scanf (" %s", h);
	if (h[0] == 'Y') good[x] = 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	int om = m;
	if (m > 1) m /= 2;
	for (int i = 0; i < n; i++) good[i] = 1;
	int nn = n / m;
	for (int d = 1; d < nn; d++) {
		memset (was, 0, sizeof (was));
		for (int i = 0; i + d < nn; i++)
			if (!was[i]) {
				for (int ci = i; ci < nn; ci += d) {
					was[ci] = 1;
					for (int j = 0; j < m; j++)
						ask (ci * m + j);
				}
				printf ("R\n"); fflush (stdout);
			}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans += good[i];
	printf ("! %d\n", ans);
	cerr << kkk << endl << 3 * n * n / (2 * om) << endl;
	re 0;
}