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

const int mod = 998244353;

int n;
int m;
ll res[300000][2][2];
vi v[300000];

void go (int x, int p) {
	ll now[2][2][2];
	memset (now, 0, sizeof (now));
	now[0][0][0] = now[0][1][0] = 1;
	int ci = 0;
	int ni = 1;
	for (auto y : v[x])
		if (y != p) {
			go (y, x);
			memset (now[ni], 0, sizeof (now[ni]));
			now[ni][0][0] = (now[ni][0][0] + now[ci][0][0] * (res[y][0][0] + res[y][0][1] + res[y][1][1])) % mod;

			now[ni][0][1] = (now[ni][0][1] + now[ci][0][0] * (res[y][0][0] + res[y][0][1] + res[y][1][0] + res[y][1][1])) % mod;
			now[ni][0][1] = (now[ni][0][1] + now[ci][0][1] * (2 * res[y][0][0] + 2 * res[y][0][1] + res[y][1][0] + 2 * res[y][1][1])) % mod;

			now[ni][1][0] = (now[ni][1][0] + now[ci][1][0] * (res[y][0][0] + res[y][0][1] + res[y][1][1])) % mod;

			now[ni][1][1] = (now[ni][1][1] + now[ci][1][0] * (res[y][0][0] + res[y][0][1])) % mod;
			now[ni][1][1] = (now[ni][1][1] + now[ci][1][1] * (2 * res[y][0][0] + 2 * res[y][0][1] + res[y][1][1])) % mod;

			swap (ci, ni);
		}
	for (int a = 0; a < 2; a++)
		for (int b = 0; b < 2; b++) {
			res[x][a][b] = now[ci][a][b];
//			printf ("%d %d %d = %lld\n", x + 1, a, b, res[x][a][b]);
		}	
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		v[b].pb (a);
	}
	memset (res, 0, sizeof (res));
	go (0, 0);
	int ans = (res[0][0][0] + res[0][0][1] + res[0][1][1] + mod - 1) % mod;
	printf ("%d\n", ans);
	re 0;
}