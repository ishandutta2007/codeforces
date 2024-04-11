#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
ll mx = modn;
#define szs askdjals

const int N = 5009;
vector<int> adj[N], szs[N];
int sz[N];
ll c[N], d[N];

void dfs(int u) {
	sz[u] = 1;
	for(int v : adj[u]) {
		dfs(v);
		sz[u] += sz[v];
		szs[u].pb(sz[v]);
	}
	for(int i = int(szs[u].size()) - 2; i >= 0; i--)
		szs[u][i] += szs[u][i + 1];
}

ll solve(int, int, bool);
int memo[5009][5009][2];
ll ch(int i, int m, int k, bool cp) {
	if(k == 0) return 0;
	if(m == int(szs[i].size())) return mx;
	assert(m < adj[i].size());
	int v = adj[i][m];

	if(memo[v][k][cp]) return memo[v][k][cp] - 1;

	int Szs = (m + 1 == int(szs[i].size())? 0 : szs[i][m + 1]);
	ll r = LLONG_MAX;
	for(int g = max(0, k - Szs); g <= k && g <= sz[v]; g++)
		r = min(r, solve(v, g, cp) + ch(i, m + 1, k - g, cp));

	r = min(r, mx);
	memo[v][k][cp] = r + 1;
	return r;
}

ll solve(int i, int k, bool cp) {
	assert(k <= sz[i]);
	if(k == 0) return 0;
	if(adj[i].empty()) return c[i] - d[i] * cp;
	ll r = LLONG_MAX;

	if(k < sz[i]) r = min(r, ch(i, 0, k, false));
	r = min(r, c[i] - d[i] * cp + ch(i, 0, k - 1, cp));

	//printf("solve(%d, %d, %d) = %lld\n", i, k, cp, r);

	return min(r, mx);
}

int p[N];

int main() {
	ll b;
	int i;
	scanf("%d %lld", &n, &b);
	scanf("%lld %lld", &c[0], &d[0]);
	for(i = 1; i < n; i++) {
		scanf("%lld %lld %d", &c[i], &d[i], &p[i]); p[i]--;
		adj[p[i]].pb(i);
	}
	dfs(0);
	//for(i = 0; i < n; i++) printf("%lld %lld %d %d\n", c[i], d[i], p[i], sz[i]);
	for(i = 1; i <= n && solve(0, i, true) <= b; i++);
	printf("%d\n", i - 1);
}