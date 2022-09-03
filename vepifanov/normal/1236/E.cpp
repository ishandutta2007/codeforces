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

set<int> v1[400000];
set<int> v2[400000];
map<int, int> rl[100001];
map<int, int> rr[100001];

int gol (int cur, int ct) {
	if (cur < 1) re 1;
	if (ct > m) re cur;
	if (rl[cur].count (ct)) re rl[cur][ct];
	auto it = v1[cur + ct].lower_bound (ct);
	if (it == v1[cur + ct].end ()) re rl[cur][ct] = max (1, cur - (m + 1 - ct));
	int tmp = *it - ct;
	re rl[cur][ct] = gol (cur - tmp, ct + tmp + 1);
}

int gor (int cur, int ct) {
	if (cur > n) re n;
	if (ct > m) re cur;
	if (rr[cur].count (ct)) re rr[cur][ct];
	auto it = v2[cur - ct + m].lower_bound (ct);
	if (it == v2[cur - ct + m].end ()) re rr[cur][ct] = min (n, cur + (m + 1 - ct));
	int tmp = *it - ct;
	re rr[cur][ct] = gor (cur + tmp, ct + tmp + 1);
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a;
		scanf ("%d", &a);
		v1[a + i].insert (i);
		v2[a - i + m].insert (i);
	}
	if (n == 1) {
		if (m == 0) printf ("1\n"); else printf ("0\n");
		re 0;
	}
	ll ans = 0;
	for (int st = 1; st <= n; st++) {
		ans += st - gol (st, 0);
		ans += gor (st, 0) - st;
		ans++;
	}
	cout << ans << endl;
	re 0;
}