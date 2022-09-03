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

const int N = 200010;

int n;
int m;
char h[N];
ii q[N];
int col[N];

int main () {
	scanf ("%d%d", &n, &m);
	scanf (" %s", h);
	int st = 0;
	while (st < n && !(h[(st + n - 1) % n] == 'B' && h[st % n] == 'W')) st++;
	if (st == n) {
		printf ("%s\n", h);
		re 0;
	}
	int r = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && (h[(st + i) % n] == h[(st + j) % n])) j++;
		q[r] = mp ((i + st) % n, j - i);
		col[r] = r & 1;
		r++;
		i = j;
	}
//	for (int i = 0; i < r; i++) printf ("%d %d %d\n", q[i].fi, q[i].se, col[i]);
	st = 0;
	while (st < r && q[st].se == 1) st++;
	if (st == r) {
		if (m % 2 == 1)
			for (int i = 0; i < n; i++)
				if (h[i] == 'B')
					h[i] = 'W';
				else
					h[i] = 'B';	
		printf ("%s\n", h);
		re 0;
	}
	for (int i = 0; i < r; ) {
		if (q[(st + i) % r].se > 1) {
			i++;
			continue;
		}
		int j = i;
		while (j < r && q[(st + j) % r].se == 1) j++;
		if (2 * m < j - i) {
			q[(st + i - 1 + r) % r].se += m;
			q[(st + j) % r].se += m;
			q[(st + j) % r].fi -= m;
			for (int k = 0; k < m; k++) {
				q[(st + i + k) % r].se = 0;
				q[(st + j - k - 1 + r) % r].se = 0;
			}
			if (m & 1)
				for (int k = i + m; k < j - m; k++) col[(st + k) % r] ^= 1;
		} else {
			if ((j - i) % 2 == 0) {
				int k = (j - i) / 2;
				q[(st + i - 1 + r) % r].se += k;
				q[(st + j) % r].se += k;
				q[(st + j) % r].fi -= k;
				for (int k = i; k < j; k++) q[(st + k) % r].se = 0;
			} else {
				q[(st + i - 1 + r) % r].se += j - i;
				for (int k = i; k < j; k++) q[(st + k) % r].se = 0;
			}
		}
		i = j;
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < q[i].se; j++)
			if (col[i])
				h[(q[i].fi + j + n) % n] = 'B';
			else	
				h[(q[i].fi + j + n) % n] = 'W';
	printf ("%s\n", h);
	re 0;
}