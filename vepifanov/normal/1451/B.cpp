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
char s[110];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		scanf (" %s", s);
		for (int i = 0; i < m; i++) {
			int l, r;
			scanf ("%d%d", &l, &r); l--; r--;
			int ok = 0;
			{
				int now = 0, last = -1, pos = l;
				for (int i = 0; i < n && pos <= r; i++)
					if (s[i] == s[pos])
						if (now || (last != -1 && i - last > 1) || (!now && pos < r)) {
							pos++;
							now |= int ((last != -1 && i - last > 1));
							last = i;
						}
				if (pos > r && now) ok = 1;
			}
			{
				int now = 0, last = n, pos = r;
				for (int i = n - 1; i >= 0 && pos >= l; i--)
					if (s[i] == s[pos])
						if (now || (last != n && last - i > 1) || (!now && pos > l)) {
							pos--;
							now |= int ((last != n && last - i > 1));
							last = i;
						}
				if (pos < l && now) ok = 1;
			}
			printf ("%s\n", ok ? "YES" : "NO");
		}
	}
	re 0;
}