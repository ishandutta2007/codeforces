#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 200200;
const int B = 450;

struct Query {
	int l, r;
	int id;

	Query() : l(), r(), id() {}
	Query(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}

	bool operator < (const Query &Q) const {
		return r < Q.r;
	}
};

int n, m, k;
vector<int> g[N];
int a[N], b[N];
ll cnt[2][N];
ll ANS;
ll ans[N];
vector<Query> q[B];
int T;
int ord[N];
int t[N][2];

map<int, int> toId;
int getId(int x) {
	if (toId.count(x) == 0) {
		toId[x] = k;
		k++;
	}
	return toId[x];
}

void dfs(int v, int par) {
	t[v][0] = T;
	ord[T++] = v;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		ord[T++] = v;
	}
	t[v][1] = T;
}

bool isAncestor(int v, int u) {
	return t[v][0] <= t[u][0] && t[u][1] <= t[v][1];
}

void addOne(int v) {
	ANS += cnt[a[v] ^ 1][b[v]];
	cnt[a[v]][b[v]]++;
}
void delOne(int v) {
	ANS -= cnt[a[v] ^ 1][b[v]];
	cnt[a[v]][b[v]]--;
}

void addRight(int L, int R) {
	if (L == R) {
		int w = ord[R];
		addOne(w);
		return;
	}
	int v = ord[L], u = ord[R - 1], w = ord[R];
	if (v == u) {
		addOne(w);
		return;
	}
	if (isAncestor(v, u)) {
		if (isAncestor(w, u))
			delOne(u);
		else
			addOne(w);
		return;
	}
	if (isAncestor(u, v)) {
		if (isAncestor(w, u) || !isAncestor(w, v))
			addOne(w);
		else
			delOne(u);
		return;
	}
	if (isAncestor(w, u))
		delOne(u);
	else
		addOne(w);
}
void addLeft(int L, int R) {
	if (L == R) {
		int w = ord[L - 1];
		addOne(w);
		return;
	}
	int u = ord[L], v = ord[R - 1], w = ord[L - 1];
	if (v == u) {
		addOne(w);
		return;
	}
	if (isAncestor(v, u)) {
		if (isAncestor(w, u))
			delOne(u);
		else
			addOne(w);
		return;
	}
	if (isAncestor(u, v)) {
		if (isAncestor(w, u) || !isAncestor(w, v))
			addOne(w);
		else
			delOne(u);
		return;
	}
	if (isAncestor(w, u))
		delOne(u);
	else
		addOne(w);
}
void delLeft(int L, int R) {
	if (L + 1 == R) {
		int w = ord[L];
		delOne(w);
		return;
	}
	int u = ord[L + 1], v = ord[R - 1], w = ord[L];
	if (v == u) {
		delOne(w);
		return;
	}
	if (isAncestor(v, u)) {
		if (isAncestor(w, u))
			addOne(u);
		else
			delOne(w);
		return;
	}
	if (isAncestor(u, v)) {
		if (isAncestor(w, u) || !isAncestor(w, v))
			delOne(w);
		else
			addOne(u);
		return;
	}
	if (isAncestor(w, u))
		addOne(u);
	else
		delOne(w);
}

void solve(int id) {
	if (q[id].empty()) return;
	for (int i = 0; i < k; i++)
		cnt[0][i] = cnt[1][i] = 0;
	ANS = 0;
	sort(q[id].begin(), q[id].end());
	int L = id * B, R = id * B;
	for (Query Q : q[id]) {
		while(R < Q.r) {
			addRight(L, R);
			R++;
		}
		while(L < Q.l) {
			delLeft(L, R);
			L++;
		}
		while(L > Q.l) {
			addLeft(L, R);
			L--;
		}
		ans[Q.id] = ANS;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		b[i] = getId(b[i]);
	}
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	//cerr << "DFS" << endl;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		v = t[v][0];
		u = t[u][0];
		if (v > u) swap(v, u);
		q[v / B].push_back(Query(v, u + 1, i));
	}
	for (int i = 0; i < B; i++)
		solve(i);
	for (int i = 0; i < m; i++)
		printf("%lld\n", ans[i]);

	return 0;
}