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
int g[50][10000];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int k;
		scanf ("%d", &k);
		for (int j = 0; j < k; j++) {
			int x;
			scanf ("%d", &x); x--;
			g[i][x] = 1;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int ok = 1;
			for (int k = 0; k < m; k++)
				ok &= int (!g[i][k] || (g[i][k] && !g[j][k]));
			if (ok) {
				printf ("impossible\n");
				re 0;
			}
		}	
	printf ("possible\n");
	re 0;
}