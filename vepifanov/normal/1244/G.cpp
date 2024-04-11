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
ll m;
int p[1000000];
int q[1000000];

ll calc () {
	ll cur = 0;
	for (int i = 0; i < n; i++) cur += max (p[i], q[i]);
	re cur;
}

int main () {
	scanf ("%d%lld", &n, &m);
	for (int i = 0; i < n; i++) p[i] = q[i] = i + 1;
	ll cur = calc ();
	if (cur > m) {
		printf ("-1\n");
		re 0;
	}
	for (int i = 0; i < n && n - 2 * i - 1 >= 0; i++) {
		if (cur + n - 2 * i - 1 >= m) {
			for (int j = 0; j < n; j++)
				if (j + i >= n)
					q[j] = n - j - 1;
				else
				if (j == i + (m - cur))
					q[j] = i;
				else
				if (j < i + (m - cur))
					q[j] = j + i + 1;
				else
					q[j] = j + i;
	        cur = m;
	        printf ("%lld\n", cur);
			for (int j = 0; j < n; j++) printf ("%d ", j + 1);
			printf ("\n");
			for (int j = 0; j < n; j++) printf ("%d ", q[j] + 1);
			printf ("\n");
			re 0;
		} else {
			cur += n - 2 * i - 1;
		}
	}
	printf ("%lld\n", cur);
	for (int j = 0; j < n; j++) printf ("%d ", j + 1);
	printf ("\n");
	for (int j = 0; j < n; j++) printf ("%d ", n - j);
	printf ("\n");
	re 0;
}