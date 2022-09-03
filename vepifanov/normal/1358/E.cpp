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

const int N = 500010;

int n;
int m;

int x[N];
ll s[N];
int f[N];
int bad[N];
int ans;

bool ls (const ii& a, const ii& b) {
	re a.fi > b.fi || (a.fi == b.fi && a.se > b.se);
}

void mark (int x) {
	if (bad[x] == 2) re;
	bad[x] = 2;
	int y = x;
	while (y > 1) {
		int j = f[y];
		bad[x / j] = 1;
		while (y % j == 0) y /= j;
	}
}

int check (int i) {
	if (bad[i]) re 0;
	int ok = 1;
	int fin = min (n - i, m);
	for (int j = 0; j <= fin && ok; j++) ok &= int (s[j] > s[j + i]);
	re ok;
}

int main () {
	for (int i = 2; i < N; i++)
		if (!f[i])
			for (int j = i; j < N; j += i)
				f[j] = i;
	scanf ("%d", &n);
	for (int i = 0; i < (n + 1) / 2; i++) scanf ("%d", &x[i]);
	int y;
	scanf ("%d", &y);
	for (int i = (n + 1) / 2; i < n; i++) x[i] = y;
	s[n] = 0;
	for (int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + x[i];
	if (s[0] > 0) {
		printf ("%d\n", n);
		re 0;
	}
	if (y >= 0) {
		printf ("-1\n");
		re 0;
	}
	int ans = n;
	m = (n + 1) / 2;
	for (int i = 0; i < m; i++) {
		ll cur = s[i] - s[m];
		if (cur <= 0) {
			printf ("-1\n");
			re 0;
		}
		ans = min ((ll)ans, min ((ll)n - i, m - i + (cur - 1) / (-y)));
		if (i + ans == n) {
			printf ("%d\n", ans);
			re 0;
		}
	}
	printf ("-1\n");
	re 0;
}