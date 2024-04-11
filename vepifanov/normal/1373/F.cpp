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

const int N = 1000*1000; 

int n;
int m;
int a[N];
int b[N];
int x[4 * N];
pair<ll, int> q[4 * N];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &a[i]);
			sum -= a[i];
		}	
		for (int i = 0; i < n; i++) {
			scanf ("%d", &b[i]);
			sum += b[i];
		}	
		for (int i = 0; i < n; i++) {
			x[2 * i] = -a[i];
			x[2 * i + 1] = b[i];
			x[2 * i + 2 * n] = -a[i];
			x[2 * i + 1 + 2 * n] = b[i];
		}
		int l = 0, r = 0;
		ll cur = 0;
		int ok = int (sum >= 0);
		for (int i = 0; i < 4 * n; i++) {
			if (i & 1) {
//				printf ("add %lld\n", cur);
				while (r > l && q[r - 1].fi <= cur) r--;
				q[r++] = mp (cur, i);
			}
//			printf ("%d\n", x[i]);
			cur += x[i];
			if (i & 1) {
//				printf ("check %lld\n", cur);
				while (l < r && i - q[l].se > 2 * n) l++;
				ok &= int (cur - q[l].fi >= 0);
			}
		}
		printf ("%s\n", ok ? "YES" : "NO");
	}
	re 0;
}