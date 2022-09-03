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

const int N = 1000000;
const int M = 2;

int n;
int m;
ll x[200000];
int f[N + 1];
int pr[N];
int o;
int ans;
int was[200000];
int was2[N + 1];

void solve2 (ll g) {
	if (g <= N) {
		if (was2[g]) re;
		was2[g] = 1;
	}
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] < g) {
			cur += g - x[i];
		} else {
			ll tmp = x[i] % g;
			if (tmp > g - tmp) tmp = g - tmp;
			cur += tmp;
		}
		if (cur >= ans) {
			re;
		}
	}
//	cout << g << " " << cur << endl;
	ans = cur;
}

void solve (ll h) {
	for (int i = 0; i < o && pr[i] <= h; i++)
		if (h % pr[i] == 0) {
			solve2 (pr[i]);
			while (h % pr[i] == 0) h /= pr[i];
		}
	if (h > 1) solve2 (h);
}

int main () {
	mt19937 rng(0);
	double start = clock ();
	for (int i = 2; i <= N; i++)
		if (!f[i]) {
			pr[o++] = i;
			if (i <= N / i)
				for (int j = i * i; j <= N; j += i)
					f[j] = 1;
		}
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%lld", &x[i]);
	ans = n;
	while (true) {
		if ((clock() - start) / CLOCKS_PER_SEC > 2) break;
		int t = rng() % n;
		if (was[t]) continue;
		was[t] = 1;
		ll a = max (x[t] - M, 1LL);
		for (ll j = a; j <= x[t] + M; j++)
			solve (j);
	}
	printf ("%d\n", ans);
	cerr << clock () << endl;
	re 0;   
}