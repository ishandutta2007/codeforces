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
vii v[100000];
int res[100000];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) res[i] = -1;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (mp (b, i));
		v[b].pb (mp (a, i));
	}
	int r = 0;
	for (int i = 0; i < n; i++)
		if (sz (v[i]) >= 3) {
			res[v[i][0].se] = 0;
			res[v[i][1].se] = 1;
			res[v[i][2].se] = 2;
			r = 3;
			break;
		}
	for (int i = 0; i < n - 1; i++)
		if (res[i] == -1)
			res[i] = r++;
	for (int i = 0; i < n - 1; i++) printf ("%d\n", res[i]);
	re 0;
}