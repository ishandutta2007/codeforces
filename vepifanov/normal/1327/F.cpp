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

const int mod = 998244353;
const int N = 500100;

int n;
int m;
int k;
vii q0[30];
vii q1[30];
int p[N + 1];
int w[N + 1];
int res[N + 1];
int sum[N + 1];

int main () {
	scanf ("%d%d%d", &n, &k, &m);
	for (int i = 0; i < m; i++) {
		int l, r, x;
		scanf ("%d%d%d", &l, &r, &x);
		for (int j = 0; j < k; j++)
			if ((x >> j) & 1)
				q1[j].pb (mp (l, r));
			else
				q0[j].pb (mp (l, r));
	}
	int ans = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= n + 1; j++) p[j] = 0;
		for (auto& j : q1[i]) {
			p[j.fi]++;
			p[j.se + 1]--;
		}
		int cur = 0;
		for (int j = 0; j <= n; j++) {
			cur += p[j];
			p[j] = int (cur > 0);
			w[j] = n + 1;
		}
//		for (int j = 0; j <= n + 1; j++) printf ("%d ", p[j]);
//		printf ("\n");
		for (auto& j : q0[i]) w[j.fi] = min (w[j.fi], j.se);
		sum[n + 2] = 0;
		sum[n + 1] = 1;
		res[n + 1] = 1;
		cur = n + 1;
		for (int j = n; j >= 0; j--) {
			if (p[j])
				res[j] = 0;
			else	
				res[j] = (sum[j + 1] - sum[cur + 1] + mod) % mod;
			sum[j] = (sum[j + 1] + res[j]) % mod;
			cur = min (cur, w[j]);
		}
		ans = ((ll)ans * res[0]) % mod;
	}
	printf ("%d\n", ans);
	re 0;
}