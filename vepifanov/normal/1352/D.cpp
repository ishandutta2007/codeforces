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
int x[1000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		int last = 0;
		int a = 0, b = 0, c = 0;
		for (int i = 0, j = n - 1; i <= j; ) {
			int cur = 0;
			while (i <= j && cur <= last) {
				cur += x[i];
				i++;
			}
			a += cur;
			last = cur;
			c++;
			if (i > j) break;
			cur = 0;
			while (i <= j && cur <= last) {
				cur += x[j];
				j--;
			}
			b += cur;
			last = cur;
			c++;
		}
		printf ("%d %d %d\n", c, a, b);
	}
	re 0;
}