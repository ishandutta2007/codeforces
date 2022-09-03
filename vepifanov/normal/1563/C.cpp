#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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
int p[2021];
vi res;

void rot (int r, int& x, int& y) {
	assert (r % 2 == 0);
	if (r == 0) re;
	res.pb (r + 1);
	for (int i = 0; i < r - i; i++) swap (p[i], p[r - i]);
	if (x <= r) x = r - x;
	if (y <= r) y = r - y;
}

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		int ok = 1;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &p[i]);
			p[i]--;
			ok &= int ((p[i] % 2) == (i % 2));
		}
		if (!ok) {
			printf ("-1\n");
			continue;
		}
		res.clear ();
		for (int i = n - 1; i > 0; i -= 2) {
			int x = 0, y = 0;
			for (int j = 0; j < n; j++)
				if (p[j] == i - 1)
					x = j;
				else
				if (p[j] == i)	
					y = j;
			rot (y, x, y);
			rot (x - 1, x, y);
			rot (x + 1, x, y);
			rot (x + 1, x, y);
			rot (i, x, y);
		}
		printf ("%d\n", sz (res));
		for (auto x : res) printf ("%d ", x);
		printf ("\n");
		for (int i = 0; i < n; i++) assert (p[i] == i);
	}
    re 0;
}