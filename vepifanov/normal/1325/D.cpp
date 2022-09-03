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

const int TT = 10;
const int N = 60;


ll xs;
ll ss;

int was[N][TT / 2 + 1];
int ct = 0;
ll res[TT];

int go (int t, int i, int r) {
	if (i == N) re int (r == 0);
	if (was[i][r] == ct) re 0;
	int nx = (xs >> i) & 1;
	int ns = (ss >> i) & 1;
	was[i][r] = ct;
	for (int mask = 0; mask < (1 << t); mask++) {
		int cx = 0, cs = r;
		for (int j = 0; j < t; j++) {
			int cur = (mask >> j) & 1;
			cx ^= cur;
			cs += cur;
		}
		if (cx == nx && (cs & 1) == ns) {
//			printf ("%d %d %d -> %d %d = %d\n", t, i, r, i + 1, cs >> 1, mask);
			if (go (t, i + 1, cs >> 1)) {
				for (int j = 0; j < t; j++) {
					int cur = (mask >> j) & 1;
					res[j] |= (ll)cur << i;
				}
				re 1;
			}
		}
	}
	re 0;
}

int main () {
	cin >> xs >> ss;
	for (int t = 0; t < TT; t++) {
		ct++;
		if (go (t, 0, 0)) {
			cout << t << endl;
			for (int i = 0; i < t; i++) cout << res[i] << " ";
			cout << endl;
			re 0;
		}
	}
	printf ("-1\n");
	re 0;
}