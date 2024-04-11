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

const int N = 1 << 17;

int n;
int m;

int tree[2 * N + 10];
int was[N];
int x[N];
vi v[N];
vi w[N];

void build (int x, int l, int r) {
	tree[x] = n;
	if (l == r) re;
	int s = (l + r) / 2;
	build (x * 2 + 1, l, s);
	build (x * 2 + 2, s + 1, r);
}

int add (int x, int l, int r, int y, int z) {
	if (r < y || l > y) re tree[x];
	if (l == r) re tree[x] = z;
	int s = (l + r) / 2;
	re tree[x] = max (add (x * 2 + 1, l, s, y, z), add (x * 2 + 2, s + 1, r, y, z));
}

int get (int x, int l, int r, int z) {
	if (l == r) re l;
	int s = (l + r) / 2;
	if (tree[x * 2 + 1] > z) re get (x * 2 + 1, l, s, z);
	re get (x * 2 + 2, s + 1, r, z);
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i <= n; i++) v[i].pb (-1);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]); x[i]--;
		v[x[i]].pb (i);
	}
	for (int i = 0; i <= n; i++) v[i].pb (n);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j + 1 < sz (v[i]); j++)
			if (v[i][j] + 1 < v[i][j + 1])
				w[v[i][j] + 1].pb (v[i][j + 1] - 1);
	build (0, 0, n);
	for (int i = n - 1; i >= 0; i--) {
		add (0, 0, n, x[i], i);
		for (auto j : w[i])
			was[get (0, 0, n, j)] = 1;
	}
	int ans = 0;
	while (was[ans]) ans++;
	printf ("%d\n", ans + 1);
	re 0;
}