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

const int mod = 1000*1000*1000+7;

int n;
int m;
int x;
int pos;

int main () {
	scanf ("%d%d%d", &n, &x, &pos);
	int l = 0, r = n, lc = x - 1, rc = n - x, placed = 1;
	int ans = 1;
	while (l < r) {
		int s = (l + r) / 2;
		if (s == pos) {
			l = s + 1;
			continue;
		} else {
			if (s < pos) {
				if (lc == 0) {
					ans = 0;
					break;
				}
				ans = ((ll)ans * lc) % mod;
				placed++;
				lc--;
				l = s + 1;
			} else {
				if (rc == 0) {
					ans = 0;
					break;
				}
				ans = ((ll)ans * rc) % mod;
				placed++;
				rc--;
				r = s;
			}
		}
	}
	for (int i = 1; i <= n - placed; i++) ans = ((ll)ans * i) % mod;
	printf ("%d\n", ans);
	re 0;
}