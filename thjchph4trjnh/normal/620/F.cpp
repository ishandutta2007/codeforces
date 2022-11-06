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

const int maxn = 50010;
const int K = 300;
const int maxm = 5010;
const int maxe = 20;
const int maxx = 1000010;

struct Query {
	int l, r, id;
	Query(int l, int r, int id) : l(l), r(r), id(id) {}
	int operator < (const Query& oth) const {
		return r < oth.r;
	}
};

int n, m;
int a[maxn];
vector<Query> que[K];
int x[maxx];
int ans[maxm];

struct Tries {
	int ntries;
	int child[maxn * maxe][2];
	int val[maxn * maxe * 2];
	
	Tries() {
		ntries = child[0][0] = child[0][1] = val[0] = 0;
	}
	void clear() {
		ntries = child[0][0] = child[0][1] = val[0] = 0;
	}
	void add(int u, int v) {
		int k = 0;
		FORd(i, maxe, 0) {
			int d = bit(u, i);
			if (!child[k][d]) {
				child[k][d] = ++ntries;
				k = child[k][d];
				child[k][0] = child[k][1] = val[k] = 0;
			}
			else k = child[k][d];
			val[k] = max(val[k], v);
		}
	}
	int getmax(int u, int v) {
		int res = 0, k = 0;
		FORd(i, maxe, 0) {
			int d = bit(u, i) ^ 1;
			if (child[k][d] && v <= val[child[k][d]]) {
				res |= 1 << i;
				k = child[k][d];
			}
			else if (child[k][d ^ 1]) {
				k = child[k][d ^ 1];
			}
			else return 0;
		}
		return res;
	}
} m_tries[2];

int brutecalc(int l, int r) {
	m_tries[0].clear(); m_tries[1].clear();
	int res = 0;
	FOR(i, l, r + 1) {
		m_tries[0].add(x[a[i]], a[i]);
		m_tries[1].add(x[a[i] - 1], maxx - a[i]);
		res = max(res, m_tries[0].getmax(x[a[i] - 1], a[i]));
		res = max(res, m_tries[1].getmax(x[a[i]], maxx - a[i]));
	}
	return res;
}

void solve() {
	FOR(i, 1, maxx) x[i] = x[i - 1] ^ i;
	cin>>n>>m;
	FOR(i, 0, n) cin>>a[i];
	FOR(i, 0, m) {
		int l, r; cin>>l>>r; l--; r--;
		ans[i] = brutecalc(l, min(l + K, r));
		if (r > l + K) que[l / K].pb(Query(l, r, i));
	}
	FOR(i, 0, K) {
		m_tries[0].clear(); m_tries[1].clear();
		sort(all(que[i]));
		int cur = 0, dmax = 0;
		FOR(j, (i + 1) * K, n) {
			m_tries[0].add(x[a[j]], a[j]);
			m_tries[1].add(x[a[j] - 1], maxx - a[j]);
			dmax = max(dmax, m_tries[0].getmax(x[a[j] - 1], a[j]));
			dmax = max(dmax, m_tries[1].getmax(x[a[j]], maxx - a[j]));
			while (cur < sz(que[i]) && que[i][cur].r == j) {
				ans[que[i][cur].id] = max(ans[que[i][cur].id], dmax);
				FOR(k, que[i][cur].l, (i + 1) * K) {
					ans[que[i][cur].id] = max(ans[que[i][cur].id], m_tries[0].getmax(x[a[k] - 1], a[k]));
					ans[que[i][cur].id] = max(ans[que[i][cur].id], m_tries[1].getmax(x[a[k]], maxx - a[k]));
				}
				cur++;
			}
		}
	}
	FOR(i, 0, m) cout<<ans[i]<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}