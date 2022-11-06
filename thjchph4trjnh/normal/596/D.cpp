#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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
const ld PI = 2 * acos(0);

const int maxn = 2010;
int n;
double h, p;
int x[maxn];
int l[maxn];
int r[maxn];
double f[maxn][maxn][2][2];

double calc(int u, int v, bool a, bool b) {
	if (u > v) return 0;
	if (f[u][v][a][b] >= 0) return f[u][v][a][b];
	double& res = f[u][v][a][b]; res = 0;
	double lm = x[u - 1], rm = x[v + 1];
	if (a) lm = x[u - 1] + h;
	if (!b) rm = x[v + 1] - h;
	res += 0.5 * p * (min(h, x[u] - lm) + calc(u + 1, v, 0, b));
	res += 0.5 * (1 - p) * (min(x[min(v, r[u])] + h, rm) - x[u] + calc(r[u] + 1, v, 1, b));
	res += 0.5 * (1 - p) * (min(h, rm - x[v]) + calc(u, v - 1, a, 1));
	res += 0.5 * p * (x[v] - max(x[max(u, l[v])] - h, lm) + calc(u, l[v] - 1, a, 0));
	return res;
}

void solve() {
	ms(f, -1);
	cin>>n>>h>>p;
	FOR(i, 1, n + 1) cin>>x[i];
	sort(x + 1, x + n + 1);
	x[0] = -INF; x[n + 1] = INF;
	FOR(i, 1, n + 1) l[i] = r[i] = i;
	FOR(i, 2, n + 1) {
		int cur = i;
		while (cur > 1 && x[cur] - h < x[cur - 1]) cur = l[cur - 1];
		l[i] = cur;
	}
	FORd(i, n, 1) {
		int cur = i;
		while (cur < n && x[cur] + h > x[cur + 1]) cur = r[cur + 1];
		r[i] = cur;
	}
	cout<<fixed<<setprecision(9)<<calc(1, n, 0, 0);
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