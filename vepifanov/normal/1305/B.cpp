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
vi x, y;

int main () {
	cin >> s;
	n = sz (s);
	for (int i = 0; i < n; i++)
		if (s[i] == '(')
			x.pb (i);
		else
			y.pb (i);	
	reverse (all (y));
	int t = 0;
	while (t < sz (x) && t < sz (y) && x[t] < y[t]) t++;
	if (t == 0) printf ("0\n"); else {
		printf ("1\n%d\n", 2 * t);
		for (int i = 0; i < t; i++) printf ("%d ", x[i] + 1);
		for (int i = t - 1; i >= 0; i--) printf ("%d ", y[i] + 1);
		printf ("\n");
	}
	re 0;   
}