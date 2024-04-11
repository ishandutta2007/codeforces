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
char h[3010];
vi w[3010];
int x[3010];

int main () {
	scanf ("%d%d", &n, &m);
	scanf (" %s", h);
	for (int i = 0; i < n; i++) x[i] = int (h[i] == 'R');
	int sum = 0, cnt = 0;
	while (true) {
		int ok = 1;
		for (int i = 0; i + 1 < n; i++)
			if (x[i] > x[i + 1]) {
				x[i] ^= 1;
				x[i + 1] ^= 1;
				sum++;
				w[cnt].pb (i);
				i++;
				ok = 0;
			}
		if (ok) break;
		cnt++;
	}
	if (cnt > m || sum < m) {
		printf ("-1\n");
		re 0;
	}
	for (int i = 0, j = 0, k = 0; i < m; i++) {
		if (i + cnt - j == m) {
			printf ("%d", sz (w[j]) - k);
			for (int t = k; t < sz (w[j]); t++) printf (" %d", w[j][t] + 1);
			printf ("\n");
			j++;
			k = 0;
		} else {
			printf ("1 %d\n", w[j][k] + 1);
			k++;
			if (k == sz (w[j])) {
				j++;
				k = 0;
			}
		}
	}
	re 0;
}