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
int x[200000];
int res[200000];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
		if (n == 1) {
			printf ("1\n1\n");
			continue;
		}
		int st = 0;
		while (st < n && x[(st + n - 1) % n] != x[st]) st++;
		if (st == n) {
			if (n % 2 == 0) {
				printf ("2\n");
				for (int i = 0; i < n; i++) printf ("%d ", i % 2 + 1);
				printf ("\n");
			} else {
				printf ("3\n3 ");
				for (int i = 1; i < n; i++) printf ("%d ", i % 2 + 1);
				printf ("\n");
			}	
			continue;
		}
		int ans = 1;
		for (int i = 0; i < n; ) {
			int j = i + 1;
			while (j < n && x[(st + j + n - 1) % n] != x[(st + j) % n]) j++;
			if (j - i == 1) {
				res[(st + i) % n] = 1;
				i = j;
				continue;
			}
			ans = 2;
			for (int k = i; k < j; k++) res[(st + k) % n] = k % 2 + 1;
			i = j;
		}
		printf ("%d\n", ans);
		for (int i = 0; i < n; i++) printf ("%d ", res[i]);
		printf ("\n");
	}
	re 0;
}