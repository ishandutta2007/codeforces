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
char s[101];
int x[100];
int was[101][3];
int res[101][3];

int go (int i, int j) {
	if (i == n) re 0;
	if (was[i][j]) re res[i][j];
	was[i][j] = 1;
	int cur = 1e9;
	for (int k = 0; k < 2; k++)
		if (x[i] == 2 || x[i] == k)
			cur = min (cur, go (i + 1, k) + int (j == k));
	re res[i][j] = cur;
}

void out (int i, int j) {
	if (i == n) re;
	int cur = res[i][j];
	for (int k = 0; k < 2; k++)
		if (x[i] == 2 || x[i] == k)
			if (cur == go (i + 1, k) + int (j == k)) {
				printf ("%c", "RB"[k]);
				out (i + 1, k);
				break;
			}
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d %s", &n, s);
		for (int i = 0; i < n; i++) x[i] = int (s[i] == 'B') + 2 * int (s[i] == '?');
		memset (was, 0, sizeof (was));
		go (0, 2);
		out (0, 2);
		printf ("\n");
	}
    re 0;
}