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
int g[100][100];
int p[1000000];
int res[1000000];
int prev[1000000];
int last[100];

int out (int i) {
	printf ("%d ", p[i] + 1);
	if (i + 1 < m) out (prev[i]);
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		char h[110];
		scanf (" %s", h);
		for (int j = 0; j < n; j++)
			g[i][j] = h[j] - '0';
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && !g[i][j])
				g[i][j] = 1e9;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++) last[i] = -1;
	for (int i = m - 1; i >= 0; i--) {
		if (i == m - 1) {
			res[i] = 1;
		} else {
			res[i] = m + 1;
			for (int j = 0; j < n; j++)
				if (last[j] != -1 && g[p[i]][j] == last[j] - i && res[last[j]] + 1 < res[i]) {
					res[i] = res[last[j]] + 1;
					prev[i] = last[j];
				}
		}
		last[p[i]] = i;
	}
	printf ("%d\n", res[0]);
	out (0);
	printf ("\n");
	re 0;
}