#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

int n;
int m;
int k;
int was[110][110][110];
ll res[110][110][110];
int x[110];
int g[110][110];

ll go (int i, int j, int k) {
	if (k < 0 || k > (n - i)) re 1e18;
	if (i == n) re 0;
	if (was[i][j][k]) re res[i][j][k];
	was[i][j][k] = 1;
	ll cur = 1e18;
	if (x[i] != -1)
		cur = go (i + 1, x[i], k - int (j != x[i]));
	else 
		for (int t = 0; t < m; t++)
			cur = min (cur, go (i + 1, t, k - int (j != t)) + g[i][t]);
	re res[i][j][k] = cur;
}

int main () {
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]);
		x[i]--;
	}	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &g[i][j]);
	ll ans = go (0, m, k);
	if (ans > 1e17) ans = -1;
	cout << ans << endl;
	return 0;
}