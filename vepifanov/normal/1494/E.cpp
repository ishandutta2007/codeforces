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
map<ii, char> all;
map<pair<char, char>, int> inc[200000];
int res[2];
ll odd = 0;
ll even = 0;

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		char s[5];
		scanf (" %s", s);
		if (s[0] == '+') {
			int a, b;
			scanf ("%d%d %s", &a, &b, s); a--; b--;
			all[mp (a, b)] = s[0];
			if (all.count (mp (b, a))) {
				char ab = s[0];
				char ba = all[mp (b, a)];
				if (ab == ba) {
					odd++;
					res[0] = res[1] = 1;
				} else {
					even++;
					res[1] = 1;
				}
			}
		} else
		if (s[0] == '-') {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			if (all.count (mp (b, a))) {
				char ab = all[mp (a, b)];
				char ba = all[mp (b, a)];
				if (ab == ba) {
					odd--;
					if (odd == 0) res[0] = 0;
					if (odd == 0 && even == 0) res[1] = 0;
				} else {
					even--;
					if (odd == 0 && even == 0) res[1] = 0;
				}
			}
			all.erase (mp (a, b));
		} else {
			int k;
			scanf ("%d", &k);
			printf ("%s\n", res[(k % 2)] ? "YES" : "NO");
		}
	}
	re 0;
}