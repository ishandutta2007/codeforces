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

int next[100000 * 31][2];
int o;

int go (int x, int i) {
	if (i == -1) re 0;
	if (next[x][0] == 0) re go (next[x][1], i - 1);
	if (next[x][1] == 0) re go (next[x][0], i - 1);
	re min (go (next[x][0], i - 1), go (next[x][1], i - 1)) | (1 << i);
}

int main () {
	scanf ("%d", &n);
	o = 1;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		int pos = 0;
		for (int j = 29; j >= 0; j--) {
			int c = (x >> j) & 1;
			if (next[pos][c] == 0)
				next[pos][c] = o++;
			pos = next[pos][c];
		}
	}
	printf ("%d\n", go (0, 29));
	re 0;
}