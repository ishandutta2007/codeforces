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

const int N = 1 << 19;

int n;
int k;
int m;
int tree[2 * N + 1];
int same[2 * N + 1];
multiset<int> top;
set<ii> all;

int build (int x, int l, int r) {
	same[x] = 0;
	if (l == r) re tree[x] = 2 * n - l;
	int s = (l + r) / 2;
	re tree[x] = min (build (x * 2 + 1, l, s), build (x * 2 + 2, s + 1, r));
}

int add (int x, int l, int r, int lc, int rc, int z) {
//	printf ("add %d %d %d %d %d %d\n", x, l, r, lc, rc, z);
	if (r < lc || l > rc) re tree[x] + same[x];
	if (l >= lc && r <= rc) {
		same[x] += z;
		re tree[x] + same[x];;
	}
	int s = (l + r) / 2;
	tree[x] = min (add (x * 2 + 1, l, s, lc, rc, z), add (x * 2 + 2, s + 1, r, lc, rc, z));
	re tree[x] + same[x];
}

int get (int x, int l, int r, int lc, int rc) {
	if (r < lc || l > rc) re 1e9;
	if (l >= lc && r <= rc) re tree[x] + same[x];
	int s = (l + r) / 2;
	re min (get (x * 2 + 1, l, s, lc, rc), get (x * 2 + 2, s + 1, r, lc, rc)) + same[x];
}

int main () {
	scanf ("%d%d%d", &n, &k, &m); k--;
	build (0, 0, 2 * n - 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf ("%d%d", &x, &y); x--; y--;
		if (all.count (mp (x, y))) {
			all.erase (mp (x, y));
			y += abs (x - k);
			top.erase (top.find (y));
			add (0, 0, 2 * n - 1, 0, y, 1);
		} else {
			all.insert (mp (x, y));
//			printf ("%d %d = %d\n", x, y, y + abs (x - k));
			y += abs (x - k);
			top.insert (y);
			add (0, 0, 2 * n - 1, 0, y, -1);
		}
		if (top.empty ()) printf ("0\n"); else {
			int tmp = *top.rbegin ();
//			printf ("%d = %d\n", tmp, get (0, 0, 2 * n - 1, 0, tmp));
			int cur = get (0, 0, 2 * n - 1, 0, tmp) - (2 * n - tmp) + 1;
//			printf ("%d %d\n", tmp, cur);
			if (cur < 0) tmp -= cur;
			if (tmp < n) printf ("0\n"); else printf ("%d\n", tmp - n + 1);
		}
	}
	re 0;
}