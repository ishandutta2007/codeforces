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
int p[200000];
int q[200000];
int cnt[200000];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x); x--;
		p[x] = i;
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x); x--;
		q[x] = i;
	}
	for (int i = 0; i < n; i++) {
		int d = p[i] - q[i];
		if (d < 0) d += n;
		cnt[d]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans = max (ans, cnt[i]);
	printf ("%d\n", ans);
	re 0;
}