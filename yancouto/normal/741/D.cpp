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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;
const int N = 512345;
unordered_map<int, int> mp[N];
int best[N], sz[N], name[N];
vector<pii> adj[N];
vector<pii> all[1 << 22];
unordered_map<int, int> has[N];

void dfs(int u, int cur, int d) {
	all[cur].pb(pii(u, d));
	has[u][cur] = d;
	sz[u] = 1;
	name[u] = u;
	for(pii e : adj[u]) {
		int v = e.fst;
		dfs(v, cur ^ (1 << e.snd), d + 1);
		best[u] = max(best[u], best[v]);
		// se sz[u] > sz[v]
		if(has[u].size() >= has[v].size()) {
			for(pii k : has[v]) all[k.fst].pop_back();
			for(pii k : has[v]) {
				for(int g = 0; g < 22; g++) {
					int f = (1 << g) ^ k.fst;
					if(all[f].empty() || all[f].back().fst != name[u]) continue;
					best[u] = max(best[u], all[f].back().snd + k.snd - 2 * d);
				}
				int f = k.fst;
				if(all[f].empty() || all[f].back().fst != name[u]) continue;
				best[u] = max(best[u], all[f].back().snd + k.snd - 2 * d);
			}
			for(pii k : has[v]) {
				if(all[k.fst].empty() || all[k.fst].back().fst != name[u]) all[k.fst].pb(pii(name[u], k.snd));
				else all[k.fst].back().snd = max(all[k.fst].back().snd, k.snd);
				has[u][k.fst] = all[k.fst].back().snd;
			}
		} else {
			for(pii k : has[u]) {
				if(all[k.fst].back().fst != name[u]) {
					pii bk = all[k.fst].back();
					assert(bk.fst == name[v]);
					all[k.fst].pop_back();
					assert(all[k.fst].back().fst == name[u]);
					all[k.fst].pop_back();
					all[k.fst].pb(bk);
				}
				else all[k.fst].pop_back();
			}
			for(pii k : has[u]) {
				for(int g = 0; g < 22; g++) {
					int f = (1 << g) ^ k.fst;
					if(all[f].empty() || all[f].back().fst != name[v]) continue;
					best[u] = max(best[u], all[f].back().snd + k.snd - 2 * d);
				}
				int f = k.fst;
				if(all[f].empty() || all[f].back().fst != name[v]) continue;
				best[u] = max(best[u], all[f].back().snd + k.snd - 2 * d);
			}
			for(pii k : has[u]) {
				if(all[k.fst].empty() || all[k.fst].back().fst != name[v]) all[k.fst].pb(pii(name[v], k.snd));
				else all[k.fst].back().snd = max(all[k.fst].back().snd, k.snd);
				has[v][k.fst] = all[k.fst].back().snd;
			}
			has[u].swap(has[v]);
			name[u] = name[v];
		}
	}
}

int main() {
	int i, j;
	rd(n);
	for(i = 1; i < n; i++) {
		int p;
		rd(p); p--;
		char c = getchar();
		adj[p].pb(pii(i, c - 'a'));
	}
	dfs(0, 0, 0);
	for(i = 0; i < n; i++) printf("%d ", best[i]);
	putchar('\n');
}