// TLE
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
const int MAX = 100009;
struct ed {
	int from, to;
	int l;
	bool uniq;
	bool onp;
	ed() {}
	ed(int f, int t, int ls) : from(f), to(t), l(ls), uniq(true), onp(false) {}
} es[MAX];
vector<int> adj[MAX];
vector<int> adj2[MAX];
int n, m, s, t;
struct no {
	int u, pai;
	ll dist;
	no() {}
	no(int v, int p, ll d) : u(v), pai(p), dist(d) {}
	bool operator < (const no &o) const {
		if(dist == o.dist) return u < o.u;
		return dist > o.dist;
	}
};
vector<int> pai[MAX];
int seen[MAX];
ll dist[MAX];

void solve2() {
	priority_queue<no> pq;
	pq.push(no(t, 0, 0));
	while(!pq.empty()) {
		no x = pq.top();
		while(!pq.empty() && pq.top().u == x.u) pq.pop();
		if(x.u == s) return;
		bool mult = (pq.size() > 0) || pai[x.u].size() > 1;
		for(int en : pai[x.u]) {
			ed &e = es[en];
			e.onp = true;
			if(mult) e.uniq = false;
			pq.push(no(e.from, 0, x.dist + e.l));
		}
	}
}

ll dist2[MAX];
void solve3() {
	priority_queue<no> pq;
	pq.push(no(t, 0, 0));
	while(!pq.empty()) {
		no e = pq.top();
		pq.pop();
		if(seen[e.u] == 2) {
			continue;
		}
		seen[e.u] = 2;
		dist2[e.u] = e.dist + 1;
		for(int en : adj2[e.u]) {
			ed &f = es[en];
			if(seen[f.from] == 2) continue;
			pq.push(no(f.from, en, e.dist + f.l));
		}
	}
}

void solve() {
	priority_queue<no> pq;
	pq.push(no(s, 0, 0));
	while(!pq.empty()) {
		no e = pq.top();
		pq.pop();
		if(seen[e.u]) {
			if(dist[e.u] == e.dist + 1) {
				pai[e.u].pb(e.pai);
			}
			continue;
		}
		seen[e.u] = 1;
		dist[e.u] = e.dist + 1;
		pai[e.u].pb(e.pai);
		for(int en : adj[e.u]) {
			ed &f = es[en];
			if(seen[f.to]) continue;
			pq.push(no(f.to, en, e.dist + f.l));
		}
	}
	solve2();
	solve3();
}

int main() {
	int i, a, b, l;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &l);
		es[i] = ed(a, b, l);
		adj[a].pb(i);
		adj2[b].pb(i);
	}
	solve();
	for(i = 0; i < m; i++) {
		ed &e = es[i];
		if(e.onp && e.uniq) puts("YES");
		if(e.onp && !e.uniq) {
			if(e.l > 1) puts("CAN 1");
			else puts("NO");
		}
		if(!e.onp) {
			if(dist[e.from] == 0 || dist2[e.to] == 0) { puts("NO"); continue; }
			int need = (dist[t] - 1) - (dist[e.from] - 1) - (dist2[e.to] - 1) - 1;
			if(need >= 1) printf("CAN %d\n", e.l - need);
			else puts("NO");
		}
	}
	return 0;
}