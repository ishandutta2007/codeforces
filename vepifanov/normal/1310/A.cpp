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

const int N = 200000;

int n;
int m;
ii v[N + 1];
multiset<int> now;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &v[i].fi);
	for (int i = 0; i < n; i++) scanf ("%d", &v[i].se);
	sort (v, v + n);
	int cur = 0;
	ll sum = 0;
	ll ans = 0;
	v[n] = mp (2e9, 0);
	for (int i = 0; i <= n; ) {
		while (cur < v[i].fi && !now.empty ()) {
//			printf ("%d %d %d %d\n", cur, sz (now), (int)sum, (int)ans);
			if (sz (now) > 1) {
				sum += *now.begin ();
				now.erase (now.begin ());
				ans += sum;
				cur++;
			} else {
				sum += *now.begin ();
				now.erase (now.begin ());
				cur++;
			}
		}
		if (i == n) break;
		cur = v[i].fi;
		while (i < n && v[i].fi == cur) {
			sum += v[i].se;
			now.insert (-v[i].se);
			i++;
		}
	}
	cout << ans << endl;
	re 0;
}