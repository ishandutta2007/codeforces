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
set<int> v[100000];
int was[100000];
int col[100000];
int q[100000];
int qq[100000];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].insert (b);
		v[b].insert (a);
	}
	int qql = 0, qqr = 0;
	for (int i = 0; i < n; i++) {
		qq[qqr] = i;
		qqr = (qqr + 1) % (n + 1);
	}	
	int r = 0;
	while (qql != qqr) {
		r++;
		if (r > 3) {
			printf ("-1\n");
			re 0;
		}
		int x = qq[qql];
		qql = (qql + 1) % (n + 1);
		int ql = 0, qr = 1;
		q[0] = x;
		while (ql < qr) {
			x = q[ql++];
			col[x] = r;
			int vis = qqr - qql;
			if (vis < 0) vis += n + 1;
			for (int i = 0; i < vis; i++) {
				int y = qq[qql];
				qql = (qql + 1) % (n + 1);
				if (v[x].count (y)) {
					qq[qqr] = y;
					qqr = (qqr + 1) % (n + 1);
				} else q[qr++] = y;
			}
		}
	}	
	if (r < 3) {
		printf ("-1\n");
		re 0;
	}
	for (int i = 0; i < n; i++)
		for (auto j : v[i])
			if (col[i] == col[j]) {
				printf ("-1\n");
				re 0;
			}
	for (int i = 0; i < n; i++) printf ("%d ", col[i]);
	printf ("\n");
	re 0;
}