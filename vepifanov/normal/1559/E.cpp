#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
const int N = 100000;
const int M = 100000;
 
int n;
int m;
int f[M + 1];
int meb[M + 1];
int res[N + 1];
int pref[N + 1];
int l[50];
int r[50];
int cl[50];
int cr[50];

int main () {
	meb[1] = 1;
	for (int i = 2; i <= M; i++) {
		if (!f[i])
			for (int j = i; j <= M; j += i)
				f[j] = i;
		if (i / f[i] % f[i] == 0) meb[i] = 0; else meb[i] = (mod - meb[i / f[i]]) % mod;
	}
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d%d", &l[i], &r[i]);
	int ans = 0;
	for (int d = 1; d * n <= M && d <= m; d++) {
		if (!meb[d]) continue;
		int ok = 1;
		for (int i = 0; i < n; i++) {
			cl[i] = (l[i] + d - 1) / d;
			cr[i] = r[i] / d;
			if (cl[i] > cr[i]) {
				ok = 0;
				break;
			}
		}
		if (!ok) continue;
		int cm = m / d;
		int sum = 0;
		res[0] = 1;
		pref[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= sum + cr[i] && j <= cm; j++) {
				res[j] = 0;
				if (j - cl[i] >= 0) res[j] = pref[min (sum, j - cl[i])];
				if (j - cr[i] > 0) res[j] = (res[j] + mod - pref[j - cr[i] - 1]) % mod;
			}
			sum += cr[i];
			for (int j = 0; j <= sum && j <= cm; j++) {
				pref[j] = res[j];
				if (j > 0) pref[j] = (pref[j] + pref[j - 1]) % mod;
			}
		}
//		printf ("%d = %d %d\n", d, meb[d], pref[min (sum, cm)]);
		ans = (ans + (ll)meb[d] * pref[min (sum, cm)]) % mod;
	}
	printf ("%d\n", ans);
    re 0;
}