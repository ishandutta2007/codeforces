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
int was[1000];
vi v[1000];
int ans;
int pos;

int ask (int a, int b) {
	if (a == b) re a;
	printf ("? %d %d\n", a + 1, b + 1); fflush (stdout);
	int c;
	scanf ("%d", &c); c--;
	re c;
}

int go (int x, int p, int d) {
	if (d > ans) {
		ans = d;
		pos = x;
	}
	for (auto y : v[x])
		if (y != p && !was[y])
			go (y, x, d + 1);
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf ("%d%d", &x, &y); x--; y--;
		v[x].pb (y);
		v[y].pb (x);
	}
	while (true) {
		pos = -1;
		ans = -1;
		for (int i = 0; i < n; i++)
			if (!was[i]) {
				go (i, i, 0);
				break;
			}
		ans = -1;
		int a = pos;
		go (pos, pos, 0);
		int b = pos;
		int c = ask (a, b);
		if (c == a || c == b) {
			printf ("! %d\n", c + 1);
			fflush (stdout);
			re 0;
		}
		was[a] = was[b] = 1;
	}
	re 0;   
}