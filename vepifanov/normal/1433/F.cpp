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
int k;
int g[70][70];
int res[71][70];
int now[71][37][70];

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &g[i][j]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < k; j++) res[i][j] = -1e9;
	res[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++)
			for (int t = 0; t <= m / 2; t++)
				for (int c = 0; c < k; c++)
					now[j][t][c] = -1e9;
		now[0][0][0] = 0;
		for (int j = 0; j < m; j++)
			for (int t = 0; t <= j && t <= m / 2; t++)
				for (int c = 0; c < k; c++)
					if (now[j][t][c] >= 0) {
						now[j + 1][t][c] = max (now[j + 1][t][c], now[j][t][c]);
						now[j + 1][t + 1][(c + g[i][j]) % k] = max (now[j + 1][t + 1][(c + g[i][j]) % k], now[j][t][c] + g[i][j]);
					}
		for (int j = 0; j < k; j++)
			if (res[i][j] >= 0)
				for (int t = 0; t <= m / 2; t++)
					for (int c = 0; c < k; c++)
						if (now[m][t][c] >= 0)
							res[i + 1][(j + c) % k] = max (res[i + 1][(j + c) % k], res[i][j] + now[m][t][c]);
	}
	printf ("%d\n", res[n][0]);
	re 0;
}