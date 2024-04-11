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
int l, r;
int cnt[200000][2];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d%d", &n, &l, &r);
		for (int i = 0; i < n; i++) cnt[i][0] = cnt[i][1] = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			cnt[x - 1][int (i < l)]++;
		}
		int ans = n;
		for (int i = 0; i < n; i++) {
			int tmp = min (cnt[i][0], cnt[i][1]);
			ans -= 2 * tmp;
			cnt[i][0] -= tmp;
			cnt[i][1] -= tmp;
		}
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			a += cnt[i][0];
			b += cnt[i][1];
		}
		ans -= min (a, b);
		int t = a < b ? 1 : 0, rem = min (a, b);
		for (int i = 0; i < n && rem; i++)
			if (cnt[i][t] % 2) {
				cnt[i][t]--;
				rem--;
			}
		for (int i = 0; i < n && rem; i++) {
			int tmp = min (rem, cnt[i][t]);
			cnt[i][t] -= tmp;
			rem -= tmp;
		}
		for (int i = 0; i < n; i++) ans -= cnt[i][t] / 2;
		printf ("%d\n", ans);
	}
	re 0;
}