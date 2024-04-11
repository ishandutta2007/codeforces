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
string s, t;
vi v;

int main () {
	cin >> n;
	cin >> s;
	cin >> t;
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (s[i] > t[i]) {
			v.pb (1);
			sum += 1;
		} else
		if (s[i] < t[i]) {
			v.pb (-1);
			sum -= 1;
		}
	if (sum != 0) {
		printf ("-1\n");
		re 0;
	}
	int a = 0, b = 0;
	for (int i = 0; i < sz (v); i++)
		if (v[i] > 0) {
			if (a > 0) { a--; b++; } else b++;
		} else {
			if (b > 0) { b--; a++; } else a++;
		}
	printf ("%d\n", a + b);
	re 0;
}