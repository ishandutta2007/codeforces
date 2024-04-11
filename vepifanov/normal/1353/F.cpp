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
ll g[110][110];
ll res[110][110];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		vector<ll> v;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> g[i][j];
				g[i][j] -= i + j;
		    	v.pb (g[i][j]);
			}
		ll ans = 2e18;
		for (int i = 0; i < sz (v); i++) {
			ll h = v[i];
			for (int j = 0; j < n; j++)
				for (int k = 0; k < m; k++)
					if (g[j][k] < h)
						res[j][k] = 2e18;
					else
					if (j + k == 0)
						res[j][k] = g[j][k] - h;
					else {	
						res[j][k] = 2e18;
						if (j > 0 && g[j - 1][k] >= h) res[j][k] = min (res[j][k], res[j - 1][k]);
						if (k > 0 && g[j][k - 1] >= h) res[j][k] = min (res[j][k], res[j][k - 1]);
						res[j][k] += g[j][k] - h;
					}
			ans = min (ans, res[n - 1][m - 1]);
		}
		cout << ans << endl;
	}
	re 0;
}