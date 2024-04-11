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
int p[200000];
int q[200000];

int gp (int x) {
	if (p[x] != x) p[x] = gp (p[x]);
	re p[x];
}

void merge (int a, int b) {
	a = gp (a);
	b = gp (b);
	if (a == b) re;
	if (rand () & 1) swap (a, b);
	q[b] = max (q[b], q[a]);
	p[a] = b;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) p[i] = q[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		merge (a, b);
	}
	int ans = 0;
	for (int i = 0; i + 1 < n; i++) {
		int pi = gp (i);
		if (q[pi] == i) continue;
		if (gp (i + 1) != pi) {
			merge (i, i + 1);
			ans++;
		}	
	}
	printf ("%d\n", ans);
	re 0;
}