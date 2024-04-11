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

const int N = 1000000;

int n;
int m;
pair<double, int> q[N];
int x[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	int r = 0;
	for (int i = n - 1; i >= 0; i--) {
		double sum = x[i];
		int cnt = 1;
		while (r > 0 && q[r - 1].fi <= sum / cnt) {
			sum += q[r - 1].fi * q[r - 1].se;
			cnt += q[r - 1].se;
			r--;
		}
		q[r++] = mp (sum / cnt, cnt);
	}
	for (int i = r - 1; i >= 0; i--)
		for (int j = 0; j < q[i].se; j++)
			printf ("%.10f\n", q[i].fi);
	re 0;
}