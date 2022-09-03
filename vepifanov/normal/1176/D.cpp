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
 
const int N = 2750131;
 
int n;
int m;
int f[N + 1];
int p[N + 1];
multiset<int> all;
int x[400000];
 
int main () {
	int r = 0;
	f[0] = 1;
	for (int i = 2; i <= N; i++)
		if (!f[i]) {
			r++;
			p[i] = r;
			if ((ll)i * i <= N)
				for (int j = i * i; j <= N; j += i)
					if (!f[j])
						f[j] = i;
		}
	scanf ("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		scanf ("%d", &x[i]);
		all.insert (x[i]);
	}
	sort (x, x + 2 * n);
	vi res;
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (all.find (x[i]) == all.end ()) continue;
		if (!f[x[i]] && !f[p[x[i]]]) {
			res.pb (p[x[i]]);
			all.erase (all.find (x[i]));
			all.erase (all.find (p[x[i]]));
			continue;
		}
		assert (f[x[i]] != 0);
		res.pb (x[i]);
		all.erase (all.find (x[i]));
		all.erase (all.find (x[i] / f[x[i]]));
	}
	for (int i = 0; i < n; i++) printf ("%d ", res[i]);
	printf ("\n");
	re 0;
}