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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 1010;
int n;
int a[maxn][maxn];
ld f[maxn];
ld p[maxn];
ld t[maxn][maxn];
ld tot[maxn];

int compare(int i, int j) {
	return f[i] > f[j];
}

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) FOR(j, 0, n) scanf("%d", &a[i][j]);
	FOR(i, 0, n - 1) {
		if (a[i][n - 1]) f[i] = 100.0 / a[i][n - 1];
		else f[i] = 1e9;
	}
	vi v, r; FOR(i, 0, n) r.pb(i);
	FOR(i, 0, n) p[i] = 1;
	while (sz(r)) {
		FOR(i, 0, sz(r)) {
			int u = r[i];
			if (sz(v)) {
				int k = v.back();
				t[u][k] = p[u] * a[u][k] / 100.0;
				tot[u] += t[u][k] * f[k];
				p[u] *= 1 - a[u][k] / 100.0;
				if (p[u] < 1) f[u] = (tot[u] + 1) / (1 - p[u]);
			}
		}
		sort(all(r), compare);
		v.pb(r.back()); r.pop_back();
	}
	cout<<prec(9)<<f[0];
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}