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

int n;
int m;
int p[200000];
int q[200000];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &p[i]); p[i]--;
		q[p[i]] = i;
	}
	ll ans = (ll)(n + n - m + 1) * m / 2;
	int cnt = 1;
	vi v;
	for (int i = 0; i < m; i++) v.pb (q[n - i - 1]);
	sort (all (v));
	for (int i = 0; i + 1 < sz (v); i++) cnt = ((ll)cnt * (v[i + 1] - v[i])) % mod;
	cout << ans << " " << cnt << endl;
	re 0;
}