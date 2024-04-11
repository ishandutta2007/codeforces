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

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		int u, r, d, l;
		scanf ("%d%d%d%d%d", &n, &u, &r, &d, &l);
		int ans = 0;
		for (int ur = 0; ur < 2; ur++)
			for (int dr = 0; dr < 2; dr++)
				for (int ul = 0; ul < 2; ul++)
					for (int dl = 0; dl < 2; dl++) 
						if (u - ur - ul >= 0 && u - ur - ul <= n - 2 && 
   						    d - dr - dl >= 0 && d - dr - dl <= n - 2 &&
   						    l - ul - dl >= 0 && l - ul - dl <= n - 2 &&
   						    r - ur - dr >= 0 && r - ur - dr <= n - 2)
					    	ans = 1;
		printf ("%s\n", ans ? "YES" : "NO");
	}
	re 0;
}