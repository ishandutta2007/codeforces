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
int y[100000];
int z[100000];

ll get (char* h) {
	int mul = 1;
	int pos = 0;
	if (h[0] == '-') {
		pos++;
		mul = -1;
	}
	ll x = 0;
	while (h[pos]) {
		if (h[pos] != '.') x = x * 10 + h[pos] - '0';
		pos++;
	}
	re x * mul;
}

int main () {
	scanf ("%d", &n);
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		char h[15];
		scanf (" %s", h);
		ll x = get (h);
		if (x % 100000 == 0) y[i] = x / 100000; else {
			if (x < 0) {
				y[i] = (x + abs (x) % 100000 - 100000) / 100000;
			} else {
				y[i] = (x - x % 100000) / 100000;
			}
			z[i] = 1;
		}
		sum += y[i];
	}
	for (int i = 0; i < n; i++) {
		if (sum < 0 && z[i]) {
			sum++;
			y[i]++;
		}
		printf ("%d\n", y[i]);
	}
	re 0;
}