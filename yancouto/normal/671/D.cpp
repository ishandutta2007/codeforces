#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINEJUDGE
#	define LLD "%I64d"
#	define debug(...) fprintf(stderr, ...)
#else
#	define LLD "%lld"
#	define debug(...) {}
#endif
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int N = 312345;

vector<int> adj[N];
vector<pii> w[N];
multimap<int, ll> mp[N];
multiset<pli> oc[N];
ll d[N];

void add(int u, int v, ll r) {
	r -= d[u];
	mp[u].insert(pil(v, r));
	oc[u].insert(pli(r, v));
}

void join(int u, int v) {
	if(mp[u].size() < mp[v].size()) {
		mp[u].swap(mp[v]);
		oc[u].swap(oc[v]);
		swap(d[u], d[v]);
	}
	for(pil e : mp[v])
		add(u, e.fst, e.snd + d[v]);
	oc[v].clear(); mp[v].clear();
}

ll dfs(int u, int p) {
	if(u) adj[u].erase(search_n(adj[u].begin(), adj[u].end(), 1, p));
	vector<int> best; best.reserve(adj[u].size());
	ll ans = 0;
	for(int v : adj[u]) {
		dfs(v, u);
		if(mp[v].empty()) { puts("-1"); exit(0); }
		ans += oc[v].begin()->fst + d[v];
		d[v] -= oc[v].begin()->fst + d[v];
	}
	if(!u) return ans;
	for(int v : adj[u]) {
		d[v] += ans;
		join(u, v);
	}
	for(pii e : w[u])
		add(u, e.fst, ll(e.snd) + ans);
	while(mp[u].find(u) != mp[u].end()) oc[u].erase(oc[u].find(pli(mp[u].find(u)->snd, u))), mp[u].erase(mp[u].find(u));
}

int main() {
	int i, j, n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b); adj[b].pb(a);
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c); a--; b--;
		w[a].pb(pii(b, c));
	}
	printf(LLD "\n", dfs(0, 0));
}