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

const int MAXN = 20;
int tr[MAXN + 1][600010];
ll sm[MAXN + 1][600010];
void init() {
	ms(tr, 0); ms(sm, 0);
}
void insert(int x, int t) {
	for (int i = 0; i < MAXN; i++) {
		tr[i][x]++;
		sm[i][x] += t;
		x >>= 1;
	}
}
void erase(int x, int t) {
	for (int i = 0; i < MAXN; i++) {
		tr[i][x]--;
		sm[i][x] -= t;
		x >>= 1;
	}
}
int kthelm(int k) {
	int res = 0;
	int a = 0, b = MAXN;
	while (b--) {
		a <<= 1;
		k -= tr[b][a] < k ? tr[b][a++] : 0;
		res = sm[b][a] / tr[b][a];
	}
	return res;
}
ll kthsum(int k) {
	ll res = 0;
	int a = 0, b = MAXN;
	while (b--) {
		a <<= 1;
		if (tr[b][a] < k) {
			res += sm[b][a];
		}
		k -= tr[b][a] < k ? tr[b][a++] : 0;
		if (!b) res += sm[b][a] / tr[b][a] * k;
	}
	return res;
}

const int maxn = 300010;
int n, w;
int a[maxn];
int b[maxn];
int idx[maxn];
int c[maxn];
int d[maxn];
map<int, int> dc;
int res[maxn];

void solve() {
	cin>>n>>w;
	vector<pair<pi, int> > v;
	FOR(i, 0, n) {
		cin>>a[i]>>b[i];
		v.pb(mp(mp(b[i], a[i]), i));
		dc[a[i]]; dc[b[i] - a[i]];
	}
	sort(all(v));
	FOR(i, 0, n) {
		a[i] = v[i].fi.se;
		b[i] = v[i].fi.fi;
		idx[i] = v[i].se;
	}
	int cnt = 0; FORall(it, dc) it->se = cnt++;
	FOR(i, 0, n) {
		c[i] = dc[a[i]];
		d[i] = dc[b[i] - a[i]];
		insert(c[i], a[i]);
	}
	ll ans = LINF;
	if (n >= w) ans = kthsum(w);
	ll cur = 0;
	FOR(i, 0, n) {
		erase(c[i], a[i]);
		insert(d[i], b[i] - a[i]);
		cur += a[i];
		if (w - i - 1 > 0 && w - i - 1 <= n) {
			ans = min(ans, cur + kthsum(w - i - 1));
		}
	}
	init();
	cout<<ans<<"\n";
	FOR(i, 0, n) {
		insert(c[i], a[i]);
	}
	if (n >= w && kthsum(w) == ans) {
		int r = kthelm(w);
		int cnt = w;
		FOR(i, 0, n) {
			if (a[i] < r) {
				res[idx[i]] = 1;
				cnt--;
			}
		}
		FOR(i, 0, n) {
			if (!cnt) break;
			if (a[i] == r) {
				res[idx[i]] = 1;
				cnt--;
			}
		}
		FOR(i, 0, n) cout<<res[i];
		return;
	}
	cur = 0;
	FOR(i, 0, n) {
		erase(c[i], a[i]);
		insert(d[i], b[i] - a[i]);
		cur += a[i];
		if (w - i - 1 > 0 && w - i - 1 <= n) {
			if (cur + kthsum(w - i - 1) == ans) {
				int r = kthelm(w - i - 1);
				int cnt = w - i - 1;
				FOR(j, 0, i + 1) {
					if (b[j] - a[j] < r) {
						res[idx[j]] = 2;
						cnt--;
					}
				}
				FOR(j, i + 1, n) {
					if (a[j] < r) {
						res[idx[j]] = 1;
						cnt--;
					}
				}
				FOR(j, 0, i + 1) {
					if (!cnt) break;
					if (b[j] - a[j] == r) {
						res[idx[j]] = 2;
						cnt--;
					}
				}
				FOR(j, i + 1, n) {
					if (!cnt) break;
					if (a[j] == r) {
						res[idx[j]] = 1;
						cnt--;
					}
				}
				FOR(j, 0, i + 1) {
					if (!res[idx[j]]) {
						res[idx[j]] = 1;
					}
				}
				FOR(j, 0, n) cout<<res[j];
				return;
			}
		}
	}
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