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
int cnt[1000];
int x[200000];
ll tot[1000];

int power (int a, ll b) {
	int c = 1;
	while (b) {
		if (b & 1) c = (c * a) % m;
		a = (a * a) % m;
		b /= 2;
	}
	re c;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	sort (x, x + n);
	int ans = 1 % m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (cnt[j]) {
				int cur = x[i] % m - j;
				if (cur < 0) cur += m;
				tot[cur] += cnt[j];
			}
		cnt[x[i] % m]++;
	}
	for (int i = 0; i < m; i++) ans = (ans * power (i, tot[i])) % m;
	printf ("%d\n", ans);
	re 0;   
}