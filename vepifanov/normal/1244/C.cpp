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

ll n, p, w, d;
int m;

int main () {
	cin >> p >> n >> w >> d;
	ll x, y, z;
	for (y = 0; y < w && (ll)d * y <= n; y++)
		if ((n - d * y) % w == 0) {
			x = (n - d * y) / w;
			z = p - x - y;
			break;
		}
	if (y < w && x + y <= p) cout << x << " " << y << " " << z << endl; else cout << -1 << endl;
	re 0;
}