#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
 
#define LL long long
#define mp make_pair
#define pb push_back
 
#define K 201
 
int n, k;
vector<int> nxt[K];

int he[K], best[K];

void DFS(int u, int par) {
	he[u] = 1;
	best[u] = -1;
	
	for (auto x : nxt[u]) if (par != x) {
		DFS(x, u);
		he[u] = max(he[u], he[x] + 1);
	
		if (best[u] == -1 || he[best[u]] < he[x]) best[u] = x;
	}
}

vector<int> res;
int req;

void deep(int u, int par) {
	res.pb(u);
	req--;

	for (auto x : nxt[u]) if (req > 0 && x != par) {
		deep(x, u);
		res.pb(u);	
	}
}

void trace(int u, int par, int step) {
	res.pb(u);
	
	for (auto x : nxt[u]) if (req > 0 && x != par && x != best[u]) {
		deep(x, u);
		res.pb(u);	
	}
	
	if (step == 1) return;
	
	trace(best[u], u, step - 1);
}

void solve() {
	scanf("%d%d", &n, &k);
	
	FOE(i, 1, n) nxt[i].clear();
	res.clear();
	
	FOE(i, 2, n) {
		int p; scanf("%d", &p);
		nxt[p].pb(i); nxt[i].pb(p);	
	}
	
	DFS(1, -1);
	int step = min(k, he[1]);
	req = k - step;
	trace(1, -1, step);
	
	printf("%d\n", res.size() - 1);
	
	FOR(i, 0, res.size()) printf("%d%c", res[i], (i + 1 == res.size() ? '\n': ' '));
}
 
int main() {
	int t; scanf("%d", &t);
	while (t--) solve();
}