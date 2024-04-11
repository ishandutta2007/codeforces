#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
void setmin(int& a, int val) {if (a > val) a = val;}
void setmax(int& a, int val) {if (a < val) a = val;}

const int maxn = 3010;
int n, m;
char s[maxn];
int a[maxn][maxn];
int l[maxn][maxn];
int r[maxn][maxn];
ll ans;

const int MAXX = 6010;
const int MAXY = 6010;
int fen[MAXX][MAXY];
void update(int x, int y, int val) {
	while (x < MAXX) {
		int y1 = y;
		while (y1 < MAXY) {
			fen[x][y1] += val;
			y1 += y1 & -y1;
		}
		x += x & -x;
	}
}
int query(int x, int y) {
	int res = 0;
	while (x) {
		int y1 = y;
		while (y1) {
			res += fen[x][y1];
			y1 -= y1 & -y1;
		}
		x -= x & -x;
	}
	return res;
}

void go1() {
	FOR(i, 0, n) {
		int cur = -1;
		FOR(j, 0, i + 2) {
			if (j == i + 1 || !a[j][i - j]) {
				if (~cur) {
					vii his;
					FOR(k, cur, j) {
						ans += query(MAXX - k - 1, MAXY + r[k][i - k] - k - 1 - 3000);
						update(MAXX - l[k][i - k] - k, MAXY - k - 3000, 1);
						his.pb(mp(MAXX - l[k][i - k] - k, MAXY - k - 3000));
					}
					FOR(k, 0, sz(his)) {
						int u = his[k].fi;
						int v = his[k].se;
						update(u, v, -1);
					}
					cur = -1;
				}
			}
			else {
				if (!~cur) {
					cur = j;
				}
			}
		}
	}
}

void go2() {
	FOR(i, 1, n) {
		int cur = -1;
		FOR(j, 0, n - i + 1) {
			if (j == n - i || !a[i + j][n - 1 - j]) {
				if (~cur) {
					vii his;
					FOR(k, cur, j) {
						ans += query(MAXX - (i + k) - 1, MAXY + r[i + k][n - 1 - k] - k - 1 - 3000);
						update(MAXX - l[i + k][n - 1 - k] - (i + k), MAXY - k - 3000, 1);
						his.pb(mp(MAXX - l[i + k][n - 1 - k] - (i + k), MAXY - k - 3000));
					}
					FOR(k, 0, sz(his)) {
						int u = his[k].fi;
						int v = his[k].se;
						update(u, v, -1);
					}
					cur = -1;
				}
			}
			else {
				if (!~cur) {
					cur = j;
				}
			}
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%s", s);
		FOR(j, 0, m) {
			a[i][j] = s[j] == 'z';
			ans += a[i][j];
		}
	}
	n = max(n, m);
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			if (a[i][j]) {
				if (j) l[i][j] = l[i][j - 1] + 1;
				else l[i][j] = 1;
			}
		}
		FORd(j, n, 0) {
			if (a[i][j]) {
				r[i][j] = r[i][j + 1] + 1;
			}
		}
	}
	go1();
	go2();
	cout<<ans;
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}