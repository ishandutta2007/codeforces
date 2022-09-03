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

const int N = 500100;

int n;
int m;

int x[N];
ll sl[N];
ll sr[N];
int q[N];

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", &x[i]);
	x[0] = x[n + 1] = 0;
	{
		int r = 1;
		q[0] = 0;
		for (int i = 1; i <= n; i++) {
			while (x[q[r - 1]] >= x[i]) r--;
			sl[i] = sl[q[r - 1]] + (ll)(i - q[r - 1]) * x[i];
			q[r++] = i;
		}
	}	
	{
		int r = 1;
		q[0] = n + 1;
		for (int i = n; i >= 1; i--) {
			while (x[q[r - 1]] >= x[i]) r--;
			sr[i] = sr[q[r - 1]] + (ll)(q[r - 1] - i) * x[i];
			q[r++] = i;
		}
	}
	pair<ll, int> best (-1, 1);
	for (int i = 1; i <= n; i++)
		best = max (best, mp (sl[i] + sr[i] - x[i], i));
	for (int i = best.se - 1; i >= 1; i--) x[i] = min (x[i], x[i + 1]);
	for (int i = best.se + 1; i <= n; i++) x[i] = min (x[i], x[i - 1]);
	for (int i = 1; i <= n; i++) printf ("%d ", x[i]);
	printf ("\n");
	re 0;
}