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

int main () {
	int tt;
	cin >> tt;
	for (int it = 0; it < tt; it++) {
		ll x;
		cin >> x;
		int y = 0;
		while (x > 1) {
			if (x % 2 == 0) x /= 2; else
			if (x % 3 == 0) x = 2 * x / 3; else
			if (x % 5 == 0) x = 4 * x / 5; else break;
			y++;
		}
		if (x > 1) y = -1;
		cout << y << endl;
	}
	re 0;
}