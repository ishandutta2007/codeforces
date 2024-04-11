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

const int N = 1700;
const int mod = 998244353;

int n;
int m;
int r;
int g[N][N];
int was[60][60];
int num[60][60];
ii w[N];
string s[8];
int e[N][N];
int h[N][N];
map<string, int> cnt;
map<string, int> nump;
vs p;
int o;

int go (int i, int j) {
	if (i > j) {
		swap (i, j);
	}
	if (was[i][j]) re num[i][j];
	was[i][j] = 1;
	num[i][j] = r;
	int x = r;
	w[r] = mp (i, j);
	r++;
//	cout << "|" << p[i] << "| |" << p[j] << "|" << endl;
	for (int c = 0; c < 26; c++)
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++) {
				string s = p[i] + char (c + 'a');
				string t = p[j] + char (c + 'a');
				int mul = 1;
				if (a == 1) { mul *= cnt[s]; s = ""; }
				if (b == 1) { mul *= cnt[t]; t = ""; }
				if (nump.count (s) && nump.count (t) && mul) {
//					printf ("%d %d -> |%s| |%s|\n", i, j, s.c_str (), t.c_str ());
					int y = go (nump[s], nump[t]);
					g[x][y] += mul;
				}
			}
	re x;
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j <= sz (s[i]); j++) p.pb (s[i].substr (0, j));
		cnt[s[i]]++;
	}
	sort (all (p));
	p.resize (unique (all (p)) - p.begin ());
	o = sz (p);
	for (int i = 0; i < o; i++) nump[p[i]] = i;
	go (0, 0);
/*	for (int i = 0; i < r; i++) {
		printf ("%d %d: ", w[i].fi, w[i].se);
		for (int j = 0; j < r; j++) printf ("%d ", g[i][j]);
		printf ("\n");
	}*/
//	cerr << r << endl;
//	cerr << clock () << endl;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < r; j++)
			e[i][j] = int (i == j);
	while (m) {
		if (m & 1) {
			for (int i = 0; i < r; i++)
				for (int j = 0; j < r; j++) {
					h[i][j] = 0;
					for (int k = 0; k < r; k++)
						h[i][j] = (h[i][j] + (ll)e[i][k] * g[k][j]) % mod;
				}
			for (int i = 0; i < r; i++)
				for (int j = 0; j < r; j++)
					e[i][j] = h[i][j];
		}
		m /= 2;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < r; j++) {
				h[i][j] = 0;
				for (int k = 0; k < r; k++)
					h[i][j] = (h[i][j] + (ll)g[i][k] * g[k][j]) % mod;
			}
		for (int i = 0; i < r; i++)
			for (int j = 0; j < r; j++)
				g[i][j] = h[i][j];
	}
	printf ("%d\n", e[0][0]);
//	cerr << r << endl;
//	cerr << clock () << endl;
	re 0;
}