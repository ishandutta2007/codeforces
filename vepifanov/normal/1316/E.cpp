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
int k;
ii v[100000];
ll res[2][1 << 7];
int g[100000][7];

int main () {
	scanf ("%d%d%d", &n, &p, &k);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &v[i].fi);
		v[i].se = i;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < p; j++)
			scanf ("%d", &g[i][j]);
	sort (v, v + n);
	reverse (v, v + n);
	for (int i = 0; i < (1 << p); i++) res[0][i] = -1e18;
	res[0][0] = 0;
	for (int i = 0; i < n; i++) {
		int id = v[i].se;
		int ci = i & 1;
		int ni = 1 - ci;
		for (int j = 0; j < (1 << p); j++) res[ni][j] = -1e18;
		for (int j = 0; j < (1 << p); j++) {
			int cnt = i;
			for (int t = 0; t < p; t++)
				if (((j >> t) & 1) == 0)
					res[ni][j | (1 << t)] = max (res[ni][j | (1 << t)], res[ci][j] + g[id][t]);
				else
					cnt--;	
			res[ni][j] = max (res[ni][j], res[ci][j] + int (cnt < k) * v[i].fi);
		}
	}
	cout << res[n & 1][(1 << p) - 1] << endl;
	re 0;
}