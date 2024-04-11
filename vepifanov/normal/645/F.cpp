#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

const int N = 200000;
const int M = 1000000;
const int mod = 1000*1000*1000+7;

int n;
int m;
int k;

int f[N + 1];
int rf[N + 1];
int cnt[M + 1];
int res[M + 1];
int was[M + 1];
int p[1000];
int q[1000];

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int cnk (int n, int k) {
	if (n < 0 || k < 0 || n < k) re 0;
	re (((ll)f[n] * rf[k]) % mod * rf[n - k]) % mod;
}

int main () {
	f[0] = rf[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		f[i] = ((ll)f[i - 1] * i) % mod;
		rf[i] = power (f[i], mod - 2);
	}
	scanf ("%d%d%d", &n, &k, &m);
	int ans = 0;
	for (int ct = 0; ct < n + m; ct++) {
		int x;
		scanf ("%d", &x);
		int y = x;
		int pn = 0;
		for (int j = 2; j * j <= y; j++)
			if (y % j == 0) {
				p[pn++] = j;
				while (y % j == 0) y /= j;
			}
		if (y > 1) p[pn++] = y;
		int qn = 0;
		for (int j = 1; j * j <= x; j++)
			if (x % j == 0) {
				q[qn++] = j;
				if (j * j != x) q[qn++] = x / j;
			}
		sort (q, q + qn);
		for (int i = 0; i < qn; i++) {
			was[q[i]] = ct + 1;
			res[q[i]] = cnk (cnt[q[i]], k - 1);
		}
		for (int i = 0; i < pn; i++)
			for (int j = 0; j < qn; j++)
				if ((ll)q[j] * p[i] <= x && was[q[j] * p[i]] == ct + 1)
					res[q[j]] = (res[q[j]] - res[q[j] * p[i]] + mod) % mod;
		for (int i = 0; i < qn; i++) ans = (ans + (ll)q[i] * res[q[i]]) % mod;
		for (int i = 0; i < qn; i++) cnt[q[i]]++;
		if (ct >= n) printf ("%d\n", ans);
	}	
	cerr << clock () << endl;
	return 0;
}