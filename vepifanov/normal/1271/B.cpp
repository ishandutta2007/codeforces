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
int x[210];

int main () {
	cin >> n >> s;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		x[i] = int (s[i] == 'B');
		cur ^= x[i];
	}
	vi res;
	for (int i = 0; i + 1 < n; i++)
		if (x[i] != cur) {
			res.pb (i + 1);
			x[i] ^= 1;
			x[i + 1] ^= 1;
		}
	if (x[n - 1] != cur) printf ("-1\n"); else {
		printf ("%d\n", sz (res));
		for (auto x : res) printf ("%d ", x);
		printf ("\n");
	}
	re 0;
}