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
int cnt[200000][26];
int sum[200000];
char h[200010];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			memset (cnt[i], 0, sizeof (cnt[i]));
			sum[i] = 0;
		}
		scanf (" %s", h);
		for (int i = 0; i < n; i++) {
			int j = min (i % m, m - i % m - 1);
			sum[j]++;
			cnt[j][h[i] - 'a']++;
		}
		int ans = 0;
		for (int i = 0; i < m; i++)
			if (sum[i] > 0) {
				ans += sum[i];
				int best = 0;
				for (int j = 0; j < 26; j++) best = max (best, cnt[i][j]);
				ans -= best;
			}
		printf ("%d\n", ans);
	}
	re 0;
}