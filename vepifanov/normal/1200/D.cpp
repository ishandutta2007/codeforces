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
int g[2001][2001];
string s[2000];

void add (int i1, int j1, int i2, int j2) {
//	printf ("%d %d %d %d\n", i1, j1, i2, j2);
	g[i1][j1]++;
	g[i2 + 1][j1]--;
	g[i1][j2 + 1]--;
	g[i2 + 1][j2 + 1]++;
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	int tot = 0;
	for (int i = 0; i < n; i++) {
		vi v;
		for (int j = 0; j < n; j++)
			if (s[i][j] == 'B')
				v.pb (j);
		if (v.empty ()) tot++; else
		if (v.back () - v[0] < m) add (max (i - m + 1, 0), max (v.back () - m + 1, 0), i, v[0]);
	}
	for (int j = 0; j < n; j++) {
		vi v;
		for (int i = 0; i < n; i++)
			if (s[i][j] == 'B')
				v.pb (i);
		if (v.empty ()) tot++; else
		if (v.back () - v[0] < m) add (max (v.back () - m + 1, 0), max (j - m + 1, 0), v[0], j);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i > 0) g[i][j] += g[i - 1][j];
			if (j > 0) g[i][j] += g[i][j - 1];
			if (i > 0 && j > 0) g[i][j] -= g[i - 1][j - 1];
			ans = max (ans, g[i][j] + tot);	
		}
	printf ("%d\n", ans);
	re 0;
}