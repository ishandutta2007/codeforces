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
int g[1000][1000];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			g[i][j] = 2;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		for (int j = 0; j <= x && j < m; j++)
			if (g[i][j] == int (j == x)) {
				printf ("0\n");
				re 0;
			} else g[i][j] = int (j < x);
	}
	for (int j = 0; j < m; j++) {
		int x;
		scanf ("%d", &x);
		for (int i = 0; i <= x && i < n; i++)
			if (g[i][j] == int (i == x)) {
				printf ("0\n");
				re 0;
			} else g[i][j] = int (i < x);
	}
	int ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == 2)
				ans = (ans * 2) % 1000000007;
	printf ("%d\n", ans);
	re 0;
}