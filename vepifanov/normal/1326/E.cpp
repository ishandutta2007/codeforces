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

const int inf = 1e8;
const int N = 1 << 19;

int n;
int m;
int tree[2 * N + 10];
int same[2 * N + 10];
int p[N];
int q[N];
int x[N];
int y[N];
int res[N];

void build (int x, int l, int r) {
	tree[x] = -inf;
	same[x] = 0;
	if (l == r) re;
	int s = (l + r) / 2;
	build (x * 2 + 1, l, s);
	build (x * 2 + 2, s + 1, r);
}

int add (int x, int l, int r, int lc, int rc, int y) {
	if (r < lc || l > rc) re tree[x] + same[x];
	if (l >= lc && r <= rc) {
		same[x] += y;
		re tree[x] + same[x];		
	}
	int s = (l + r) / 2;
	tree[x] = max (add (x * 2 + 1, l, s, lc, rc, y), add (x * 2 + 2, s + 1, r, lc, rc, y));
//	printf ("add %d %d %d %d %d %d = %d %d\n", x, l, r, lc, rc, y, tree[x], same[x]);
	re tree[x] + same[x];
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &p[i]); p[i]--;
		q[p[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]); x[i]--;
		y[x[i]] = i;
	}
	build (0, 0, n - 1);
	for (int i = n, j = 0; j < n; j++) {
		while (i > 0 && tree[0] + same[0] <= 0) {
			i--;
			add (0, 0, n - 1, 0, q[i], 1);
			add (0, 0, n - 1, q[i], q[i], inf);
		}
		res[j] = i;
		add (0, 0, n - 1, 0, x[j], -1);
	}
	for (int i = 0; i < n; i++) printf ("%d ", res[i] + 1);
	printf ("\n");
	re 0;
}