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
vi v[200000];
int cnt[200000];
int dep[200000];
vi q;

int ask (char c, int x) {
	printf ("%c %d\n", c, x + 1);
	fflush (stdout);
	int y;
	scanf ("%d", &y);
	re y;
}

int go (int x, int p, int d) {
	cnt[x] = 1;
	dep[x] = 0;
	if (d == 0) re cnt[x];
	for (auto y : v[x])
		if (y != p) {
			go (y, x, d - 1);
			if (dep[y] < d - 1) continue;
			cnt[x] += cnt[y];
			dep[x] = max (dep[x], dep[y] + 1);
		}
	re cnt[x];
}

int go2 (int x, int p, int d) {
	q.pb (x);
	if (d == 0) re 0;
	ii best (-1, -1);
	for (auto y : v[x])
		if (y != p && dep[y] == d - 1)
			best = max (best, mp (cnt[y], y));
	go2 (best.se, x, d - 1);
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	int cur = 0;
	int dist = ask ('d', 0);
	go (0, 0, dist);
	while (dist > 0) {
		if (dist == 1) {
			cur = ask ('s', cur) - 1;
			dist--;
			continue;
		}

		q.clear ();
		go2 (cur, cur, dist);
//		for (auto x : q) printf ("%d ", x + 1);
//		printf ("\n");

		int mid = (dist + 1) / 2;
		int k = ask ('d', q[mid]);
		cur = ask ('s', q[mid - (k + mid - dist) / 2]) - 1;
		dist = dist - (mid - (k + mid - dist) / 2) - 1;
	}
	printf ("! %d\n", cur + 1);
	fflush (stdout);
	re 0;
}