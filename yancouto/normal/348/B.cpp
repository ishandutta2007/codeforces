#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ll tot;
void check(ll a, ll b) {
	if(126 - __builtin_clzll(a) - __builtin_clzll(b) > 60) {
		printf("%I64d\n", tot);
		exit(0);
	}
}

ll mdc(ll a, ll b) {
	if(b == 0) return a;
	return mdc(b, a % b);
}

ll mmc(ll a, ll b) {
	a /= mdc(a, b);
	check(a, b);
	return a * b;
}
const int N = 100009;
vector<int> adj[N];
ll val[N], sv[N];
int dfs(int u, int p) {
	int sons = 0; ll s = 1;
	for(int v : adj[u])
		if(v != p)
			s = mmc(s, dfs(v, u)), sons++;
	if(sons) check(sons, s), sv[u] = s;
	else sv[u] = 1;
	if(sons) return val[u] = (ll(sons) * s);
	else return val[u] = 1;
}

ll best = LLONG_MAX;

int a[N];
void dfs2(int u, int p, ll x) {
	val[u] = x;
	int sons = 0;
	for(int v : adj[u])
		if(v != p) {
			check(x, sv[u] / val[v]);
			dfs2(v, u, x * (sv[u] / val[v])), sons++;
		}
	if(sons == 0) best = min(best, a[u] / x);
}

int main() {
	int i, n, s, t;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	tot = accumulate(a, a + n, 0ll);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &s, &t); s--; t--;
		adj[s].pb(t);
		adj[t].pb(s);
	}
	dfs(0, -1);
	dfs2(0, -1, 1);
	ll r = 0;
	for(i = 0; i < n; i++)
		if(a[i])
			r += a[i] - val[i] * best;
	printf("%I64d\n", r);
}