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
char h[200010];
int x[200010];
int cnt[200010][3];

int calc (int l, int r, int x) {
	if (l >= r) re 0;
	int cur = 0;
	if (l < n) cur += cnt[l][x];
	if (r < n) cur -= cnt[r][x];
	re cur;
}

int main () {
	scanf ("%d%d", &n, &m);
	scanf (" %s", h);
	for (int i = 0; i < n; i++) x[i] = h[i] - 'a';
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < 3; j++)
			cnt[i][j] = (i + 3 < n ? cnt[i + 3][j] : 0) + int (x[i] == j);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf ("%d%d", &l, &r); l--;
		int ai = r, bi = r, ci = r;
		while ((ai - l) % 3 != 0) ai++;
		while ((bi - (l + 1)) % 3 != 0) bi++;
		while ((ci - (l + 2)) % 3 != 0) ci++;
		int ans = 0;
//		printf ("%d - %d | %d - %d | %d - %d\n", l, ai, l + 1, bi, l + 2, ci);
		for (int a = 0; a < 3; a++)
			for (int b = 0; b < 3; b++)
				if (a != b) {
					int c = 3 - a - b;
					int cur = calc (l, ai, a) + calc (l + 1, bi, b) + calc (l + 2, ci, c);
//					printf ("%d %d %d = %d\n", a, b, c, cur);
					ans = max (ans, cur);
				}
		printf ("%d\n", (r - l) - ans);
	}
    re 0;
}