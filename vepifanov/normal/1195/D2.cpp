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
int p10[21];
int cnt[11];
int x[100000];
int q[11];

int len (int x) {
	int y = 0;
	while (x) {
		y++;
		x /= 10;
	}
	re y;
}

int main () {
	p10[0] = 1;
	for (int i = 1; i <= 20; i++) p10[i] = ((ll)p10[i - 1] * 10) % mod;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		cnt[len (x[i])]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cur = len (x[i]);
		int xx = x[i];
		for (int j = 0; j < cur; j++) {
			q[j] = xx % 10;
			xx /= 10;
		}
		for (int j = 1; j <= 10; j++)
			if (cnt[j])
				for (int k = 0; k < cur; k++) {
//					printf ("%d %d: %d %d %d %d\n", j, k, p10[k + min (k, j)], p10[k + min (k, j - 1) + 1], q[k], cnt[j]);
					ans = (ans + (ll)(p10[k + min (k, j)] + p10[k + min (k, j - 1) + 1]) * q[k] % mod * cnt[j]) % mod;
				}
	}
	printf ("%d\n", ans);
	re 0;
}