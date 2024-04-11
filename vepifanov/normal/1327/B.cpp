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
int was[100000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) was[i] = 0;
		int ans = 0, last = -1;
		for (int i = 0; i < n; i++) {
			int k;
			scanf ("%d", &k);
			int ok = 1;
			for (int j = 0; j < k; j++) {
				int x;
				scanf ("%d", &x); x--;
				if (ok && !was[x]) {
					was[x] = 1;
					ok = 0;
					ans++;
				}
			}
			if (ok) last = i;
		}
		if (last == -1) printf ("OPTIMAL\n"); else {
			printf ("IMPROVE\n");
			for (int i = 0; i < n; i++)
				if (!was[i]) {
					printf ("%d %d\n", last + 1, i + 1);
					break;
				}	
		}
	}
	re 0;
}