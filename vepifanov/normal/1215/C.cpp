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
string s;
string t;
vi v, w;
vii res;

int main () {
	cin >> n >> s >> t;
	int cnt = 0;
	for (int i = 0; i < n; i++) cnt += int (s[i] == 'b') + int (t[i] == 'b');
	if (cnt % 2 != 0) {
		printf ("-1\n");
		re 0;
	}	
	for (int i = 0; i < n; i++)
		if (s[i] == 'a' && t[i] == 'b')
			v.pb (i);
		else
		if (s[i] == 'b' && t[i] == 'a')
			w.pb (i);
	while (sz (v) >= 2) {
		res.pb (mp (v[sz (v) - 1], v[sz (v) - 2]));
		v.pop_back ();
		v.pop_back ();
	}
	while (sz (w) >= 2) {
		res.pb (mp (w[sz (w) - 1], w[sz (w) - 2]));
		w.pop_back ();
		w.pop_back ();
	}
	if (!v.empty ()) {
		assert (!w.empty ());
		res.pb (mp (v[0], v[0]));
		res.pb (mp (v[0], w[0]));
	}
	printf ("%d\n", sz (res));
	for (auto& x : res) printf ("%d %d\n", x.fi + 1, x.se + 1);
	re 0;
}