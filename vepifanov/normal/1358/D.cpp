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

const int N = 400010;

int n;
ll m;
int x[N];
ll s1[N];
ll s2[N];

int main () {
	scanf ("%d%lld", &n, &m);
	ll ans = -1;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		x[i + n] = x[i];
		if (m <= x[i]) ans = max (ans, (ll)(x[i] + x[i] - m + 1) * m / 2);
	}
	if (ans != -1) {
		printf ("%lld\n", ans);
		re 0;
	}
	s1[2 * n] = s2[2 * n] = 0;
	for (int i = 2 * n - 1; i >= 0; i--) {
		s1[i] = s1[i + 1] + x[i];
		s2[i] = s2[i + 1] + (ll)x[i] * (x[i] + 1) / 2;
	}	
	for (int i = 0, j = 0; i < 2 * n; i++) {
		while (j < i && s1[j] - s1[i + 1] > m) j++;
		ll rem = m - (s1[j] - s1[i + 1]);
		ll cur = s2[j] - s2[i + 1];
		if (j > 0 && rem > 0) {
			rem = min (rem, (ll)x[j - 1]);
			cur += (x[j - 1] + x[j - 1] - rem + 1) * rem / 2;
		}
		ans = max (ans, cur);
	}
	printf ("%lld\n", ans);
	re 0;
}