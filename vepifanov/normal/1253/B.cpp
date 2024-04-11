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
int x[100000];
int res[100010];
int now[1000010];
int last[1000010];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	int r = 1, cur = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] > 0) {
			if (now[x[i]] || last[x[i]] == r) {
				printf ("-1\n");
				re 0;
			}
			last[x[i]] = r;
			now[x[i]] = 1;
			cur++;
		} else {
			if (!now[-x[i]]) {
				printf ("-1\n");
				re 0;
			}
			now[-x[i]] = 0;
			cur--;
		}
		res[r - 1]++;
		if (cur == 0) r++;
	}
	if (cur != 0) {
		printf ("-1\n");
		re 0;
	}
	printf ("%d\n", r - 1);
	for (int i = 0; i < r - 1; i++) printf ("%d ", res[i]);
	printf ("\n");
	re 0;
}