//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
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
int res[100000];
vi v[100000];

int go (int x, int p, int c) {
	res[x] = c * sz (v[x]); 
	for (auto y : v[x])
		if (y != p)
			go (y, x, -c);
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) v[i].clear ();
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			scanf ("%d%d", &a, &b); a--; b--;
			v[a].pb (b);
			v[b].pb (a);
		}
		go (0, 0, 1);
		for (int i = 0; i < n; i++) printf ("%d ", res[i]);
		printf ("\n");
	}
    re 0;
}