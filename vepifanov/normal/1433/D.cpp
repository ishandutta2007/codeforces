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
int p[5000];
int x[5000];

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

int merge (int a, int b) {
	a = gp (a);
	b = gp (b);
	if (a != b) {
		if (rand () & 1) swap (a, b);
		p[a] = b;
		re 1;
	}
	re 0;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x[i]);
			p[i] = i;
		}
		int rem = n;
		vii res;
		for (int i = 0; i < n && rem > 1; i++)
			for (int j = i + 1; j < n && rem > 1; j++)
				if (x[i] != x[j] && merge (i, j)) {
					rem--;
					res.pb (mp (i, j));
				}	
		if (rem > 1) printf ("NO\n"); else {
			printf ("YES\n");
			for (int i = 0; i < n - 1; i++) printf ("%d %d\n", res[i].fi + 1, res[i].se + 1);
		}
	}
	re 0;
}