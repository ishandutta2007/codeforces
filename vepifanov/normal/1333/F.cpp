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

const int N = 500000;

int n;
int m;

int f[N + 1];
vi pr;
vi v;
int was[N + 1];

int gen (const vii& w, int i, int x, int b) {
//	printf ("%d %d %d | %d %d\n", i, x, b, w[i].fi, w[i].se);
	if (x <= b) re 0;
	if (was[x]) {
//		printf ("found %d %d\n", b, x);
		re 1;
	}
	if (i == sz (w)) re 0;
	if (gen (w, i + 1, x, b)) re 1;
	for (int j = 0; j < w[i].se; j++) {
		x /= w[i].fi;
		if (x <= b) break;
		if (gen (w, i + 1, x, b)) re 1;
	}
	re 0;
}

vii w;

void build (int x) {
	w.clear ();
	int xx = x;
	while (xx > 1) {
		int k = f[xx], t = 0;
		while (xx % k == 0) {
			xx /= k;
			t++;
		}
		w.pb (mp (k, t));
	}
}

int check (int x, int b) {
	if (gen (w, 0, x, b)) re 1;
	re 0;
}

int main () {
	scanf ("%d", &n);
	v.pb (1);
	was[1] = 1;
	for (int i = 2; i <= n; i++)
		if (!f[i]) {
			pr.pb (i);
			v.pb (i);
			f[i] = i;
			was[i] = 1;
			if ((ll)i * i <= n)
				for (int j = i * i; j <= n; j += i)
					f[j] = i;
		}
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		while (sz (v) < i) {	
			ans++;
//			printf ("%d\n", ans); fflush (stdout);
			build (ans);
			for (int j = 0; j < sz (pr) && pr[j] * ans <= n; j++) {
				w.pb (mp (pr[j], 1));
				int ok = 1;
				if (check (pr[j] * ans, ans)) break;
//				printf ("add %d %d\n", ans, pr[j] * ans);
				was[pr[j] * ans] = 1;
				v.pb (pr[j] * ans);
				w.pop_back ();
			}
		}
		printf ("%d ", ans);
	}
	printf ("\n");
	re 0;
}