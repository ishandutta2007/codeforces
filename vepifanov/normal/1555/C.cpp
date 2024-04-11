#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
int g[2][100000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		int s1 = 0, s2 = 0;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++) {
				scanf ("%d", &g[i][j]);
				if (i == 0) s1 += g[i][j];
			}
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			s1 -= g[0][i];
			ans = min (ans, max (s1, s2));
			s2 += g[1][i];
		}
		printf ("%d\n", ans);
	}
    re 0;
}