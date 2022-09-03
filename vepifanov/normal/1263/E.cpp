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

const int N = 1 << 20;

int n;
int m;
string s;
char cur[N];
int same[2 * N + 10];
ii tree[2 * N + 10];

void build (int x, int l, int r) {
	same[x] = 0;
	tree[x] = mp (0, 0);
	if (l == r) re;
	int s = (l + r) / 2;
	build (x * 2 + 1, l, s);
	build (x * 2 + 2, s + 1, r);
}

inline ii merge (const ii& a, const ii& b) {
	re mp (min (a.fi, b.fi), max (a.se, b.se));
}

inline void push (int x, int l, int r) {
	if (!same[x]) re;
	tree[x].fi += same[x];
	tree[x].se += same[x];
	if (l != r) {
		same[x * 2 + 1] += same[x];
		same[x * 2 + 2] += same[x];
	}
	same[x] = 0;
}

ii add (int x, int l, int r, int lc, int rc, int y) {
	push (x, l, r);
	if (r < lc || l > rc) re tree[x];
	if (l >= lc && r <= rc) {
		same[x] += y;
		push (x, l, r);
		re tree[x];
	}
	int s = (l + r) / 2;
	re tree[x] = merge (add (x * 2 + 1, l, s, lc, rc, y), add (x * 2 + 2, s + 1, r, lc, rc, y));
}

int main () {
	cin >> n >> s;
	build (0, 0, N - 1);
	int pos = 0;
	int bal = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L')
			pos = max (pos - 1, 0);
		else
		if (s[i] == 'R')
			pos++;
		else {
			int diff = int (s[i] == '(') - int (s[i] == ')') - int (cur[pos] == '(') + int (cur[pos] == ')');
			bal += diff;
			add (0, 0, N - 1, pos, N - 1, diff);
			cur[pos] = s[i];
		}
		if (bal == 0 && tree[0].fi >= 0) printf ("%d ", tree[0].se); else printf ("-1 ");
	}
	printf ("\n");
	re 0;
}