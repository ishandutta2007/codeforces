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
int h[100];
int k;

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; i++) scanf ("%d", &h[i]);
		for (int i = 0; i + 1 < n; i++) {
			if (h[i] + k < h[i + 1]) m -= h[i + 1] - h[i] - k; else m += h[i] - max (0, h[i + 1] - k);
			if (m < 0) break;
		}
		printf ("%s\n", m < 0 ? "NO" : "YES");
	}
	re 0;
}