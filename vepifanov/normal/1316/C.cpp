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
int p;
int a[1000001];
int b[1000001];

int main () {
	scanf ("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf ("%d", &b[i]);
	int ai = 0, bi = 0;
	while (a[ai] % p == 0) ai++;
	while (b[bi] % p == 0) bi++;
	printf ("%d\n", ai + bi);
	re 0;
}