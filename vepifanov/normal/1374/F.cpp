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
vi res;
int x[500];
int y[500];

void shift (int i) {
	int t = x[i];
	x[i] = x[i + 2];
	x[i + 2] = x[i + 1];
	x[i + 1] = t;
//	printf ("shift %d: ", i + 1);
//	for (int i = 0; i < n; i++) printf ("%d ", x[i]);
//	printf ("\n");
	res.pb (i + 1);
}

int main () {
	int tt;
	scanf ("%d", &tt); 
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf ("%d", &y[i]);
		}
		int ok = 0;
		for (int g = 0; g < 1; g++) {
		for (int i = 0; i < n; i++)  {
			x[i] = y[i];
			if (g == 1) x[i] *= -1;
		}
		res.clear ();
		for (int i = 0; i + 3 < n; i++) {
			int k = i;
			for (int j = i; j < n; j++)
				if (x[j] < x[k])
					k = j;
			if (k == i) continue;
			while (k > i + 1) {
				shift (k - 2);
				k -= 2;
			}
			if (k == i + 1) {
				shift (i);
				shift (i);
			}
		}
//		for (int i = 0; i < n; i++) printf ("%d ", x[i]);
//		printf ("\n");
		ok = 0;
		for (int i = 0; i < 3; i++) {
			if (x[n - 3] <= x[n - 3 + 1] && x[n - 3 + 1] <= x[n - 3 + 2]) {
				ok = 1;
				break;
			}
			shift (n - 3);
		}
		if (!ok) {
			int p = -1;
			for (int j = 0; j < 3; j++) {
				for (int i = n - 3; i >= 0; i--)
					if (x[i] == x[i + 1]) {
						p = i;
						break;
					}
				if (p != -1) break;
				shift (n - 3);
			}	
			if (p != -1) {
				for (int i = 0; i < 3; i++) {
					if (x[n - 3] <= x[n - 3 + 1] && x[n - 3] <= x[n - 3 + 2])
						break;
					shift (n - 3);
				}
				assert (x[n - 2] > x[n - 1]);
				if (((n - 1) - p) % 2 == 0) {
					for (int j = n - 1; j > p; j -= 2) shift (j - 2);
					shift (p);
					for (int j = p + 1; j < n - 2; j += 2) {
						shift (j);
						shift (j);
					}
				} else {
					for (int j = n - 2; j > p; j -= 2) shift (j - 2);
					shift (p);
					for (int j = p + 1; j < n - 2; j += 2) {
						shift (j);
						shift (j);
					}
				}
				ok = 1;
			}
		}
			if (ok) break;
		}
/*		vi res2;
		for (int i = 0; i < sz (res); i++) {
			if (i + 2 < sz (res) && res[i] == res[i + 1] && res[i + 1] == res[i + 2]) i += 2; else res2.pb (res[i]);
		}
		res = res2;*/
		if (ok) {
//			printf ("0\n");
			assert (sz (res) <= n * n);
			printf ("%d\n", sz (res));
			for (auto x : res) printf ("%d ", x);
			printf ("\n");
			for (int i = 0; i + 1 < n; i++) assert (x[i] <= x[i + 1]);
		} else printf ("-1\n");
	}	
	re 0;
}