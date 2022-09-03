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

char h[1000010];
string s[100000];
vii w;
vi v[1000001][5];
vi u[1000001];

int get (char c) {
	re int (c == 'a') * 0 +
	   int (c == 'e') * 1 + 
	   int (c == 'o') * 2 +
	   int (c == 'i') * 3 +
	   int (c == 'u') * 4;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf (" %s", h);
		s[i] = string (h);
		int cnt = 0, last = 0;
		for (int j = 0; h[j]; j++)
			if (h[j] == 'a' || h[j] == 'e' || h[j] == 'o' || h[j] == 'i' || h[j] == 'u') {
				cnt++;
				last = get (h[j]);
			}
		v[cnt][last].pb (i);
	}
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 0; j < 5; j++) {
			while (sz (v[i][j]) >= 2) {
				w.pb (mp (v[i][j][sz (v[i][j]) - 1], v[i][j][sz (v[i][j]) - 2]));
				v[i][j].pop_back ();
				v[i][j].pop_back ();
			}
			if (!v[i][j].empty ()) u[i].pb (v[i][j][0]);
		}
	}
	int r = sz (w);
	for (int i = 1; i <= 1000000; i++)
		while (sz (u[i]) >= 2) {
			w.pb (mp (u[i][sz (u[i]) - 1], u[i][sz (u[i]) - 2]));
			u[i].pop_back ();
			u[i].pop_back ();
		}
	printf ("%d\n", min (sz (w) / 2, r));	
	for (int i = 0; i < r && i < sz (w) / 2; i++)
		printf ("%s %s\n%s %s\n", s[w[sz (w) - i - 1].fi].c_str (), s[w[i].fi].c_str (), s[w[sz (w) - i - 1].se].c_str (), s[w[i].se].c_str ());
	re 0;
}