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
ll sum[200001];
ll top[200001];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		sum[0] = top[0] = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			sum[i + 1] = sum[i] + x;
			top[i + 1] = max (top[i], sum[i + 1]);
		}
		for (int i = 0; i < m; i++) {
			int x;
			scanf ("%d", &x);
			int full = 0;
			if (top[n] < x && sum[n] <= 0) {
				printf ("-1 ");
				continue;
			}
			if (top[n] < x) full = (x - top[n] + sum[n] - 1) / sum[n];
			x -= sum[n] * full;
			int l = 0, r = n;
			while (r - l > 1) {
				int s = (l + r) / 2;
				if (top[s] >= x) r = s; else l = s;
			}
			if (x <= 0) r = l;
			printf ("%lld ", (ll)full * n + r - 1);
		}
		printf ("\n");
	}
	re 0;
}