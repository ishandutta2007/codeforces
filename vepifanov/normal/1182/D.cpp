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

const int N = 100000;

int n;
int m;
vi v[N];
int o = 0;
map<ii, int> num;
int dh[N];

int get (int x, int y) {
	if (num.count (mp (x, y))) re num[mp (x, y)];
	num[mp (x, y)] = o;
	o++;
	re o - 1;
}

int go (int x, int p) {
	multiset<int> u;
	for (auto y : v[x])
		if (y != p)
			u.insert (go (y, x));
	if (u.empty ()) re dh[x] = get (0, 0);
	if (*u.begin () == -1 || *u.begin () != *u.rbegin ()) re dh[x] = -1;
	re dh[x] = get (sz (u), *u.begin ());
}

int go2 (int x, int p, int uh) {
	multiset<int> u;
	if (x != p) u.insert (uh);
	for (auto y : v[x])
		if (y != p)
			u.insert (dh[y]);
	if (u.empty () || (*u.begin () != -1 && *u.begin () == *u.rbegin ())) {
		printf ("%d\n", x + 1);
		exit(0);
	}
	for (auto y : v[x])
		if (y != p) {
			u.erase (u.find (dh[y]));
			int cur = 0;
			if (u.empty ()) cur = get (0, 0); else 
			if (*u.begin () == -1 || *u.begin () != *u.rbegin ()) cur = -1; else cur = get (sz (u), *u.begin ());
			go2 (y, x, cur);
			u.insert (dh[y]);
		}
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
	go (0, 0);
	go2 (0, 0, 0);
	printf ("-1\n");
	re 0;
}