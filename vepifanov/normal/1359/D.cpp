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

const int inf = 1e9;
const int N = 1 << 17;

int n;
int m;

ii tree[2 * N + 10];
ii tree2[2 * N + 10];
int x[N];
int s[N];

ii build (int x, int l, int r) {
	if (l == r) re tree[x] = mp (::x[l], l);
	int s = (l + r) / 2;
	tree[x] = max (build (x * 2 + 1, l, s), build (x * 2 + 2, s + 1, r));
	re tree[x];
}

ii get (int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re mp (-inf, 0);
	if (l >= lc && r <= rc) re tree[x];
	int s = (l + r) / 2;
	re max (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc));
}

ii merge (const ii& a, const ii& b) {
	re mp (min (a.fi, b.fi), max (a.se, b.se));
}

ii build2 (int x, int l, int r) {
	if (l == r) re tree2[x] = mp (s[l], s[l]);
	int s = (l + r) / 2;
	re tree2[x] = merge (build2 (x * 2 + 1, l, s), build2 (x * 2 + 2, s + 1, r));
}

ii get2 (int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re mp (inf, -inf);
	if (l >= lc && r <= rc) re tree2[x];
	int s = (l + r) / 2;
	re merge (get2 (x * 2 + 1, l, s, lc, rc), get2 (x * 2 + 2, s + 1, r, lc, rc));
}

int go (int l, int r) {
	if (l >= r) re 0;
	ii s = get (0, 0, n - 1, l, r);
	ii a = get2 (0, 0, n, l, s.se);
	ii b = get2 (0, 0, n, s.se + 1, r + 1);
	int ans = a.se - b.fi - s.fi;
	ans = max (ans, go (l, s.se - 1));
	ans = max (ans, go (s.se + 1, r));
	re ans;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	s[n] = 0;
	for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + x[i];
	build (0, 0, n - 1);
	build2 (0, 0, n);
	printf ("%d\n", go (0, n - 1));
	re 0;
}