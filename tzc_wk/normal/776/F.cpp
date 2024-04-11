// Created time: 2022/5/1 9:39:59
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 1e5;
const int INF = 0x3f3f3f3f;
const unsigned long long BS = 131;
unsigned long long pw[MAXN + 5];
int n, m, M = 0, k; pii pE[MAXN * 2 + 5];
vector<pii> G[MAXN + 5];
int get1(int u, int v, int id) {return (u < v) ? id : (id + M);}
int get2(int u, int v, int id) {return (u > v) ? id : (id + M);}
int f[MAXN * 4 + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
void merge(int x, int y) {x = find(x); y = find(y); if (x ^ y) f[x] = y;}
int pos[MAXN * 4 + 5], rnk[MAXN + 5], ord[MAXN + 5];
set<int> st[MAXN * 4 + 5];
vector<int> vec[MAXN + 5];
vector<unsigned long long> hs[MAXN + 5];
bool cmp(int x, int y) {
	int l = 0, r = min(vec[x].size(), vec[y].size()) - 1, p = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (hs[x][mid] == hs[y][mid]) p = mid, l = mid + 1;
		else r = mid - 1;
	}
	return vec[x][p + 1] < vec[y][p + 1];
}
int hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int siz[MAXN + 5], mx[MAXN + 5], cent; bool vis[MAXN + 5];
void findcent(int x, int f, int tot) {
	siz[x] = 1; mx[x] = 0;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f || vis[y]) continue;
		findcent(y, x, tot); siz[x] += siz[y];
		mx[x] = max(mx[x], siz[y]);
	}
	mx[x] = max(mx[x], tot - siz[x]);
	if (mx[x] < mx[cent]) cent = x;
}
int res[MAXN + 5];
int findsiz(int x, int f) {
	int ret = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f || vis[y]) continue;
		ret += findsiz(y, x);
	}
	return ret;
}
void divcent(int x, int DEP) {
	res[x] = DEP; vis[x] = 1;
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (vis[y]) continue;
		cent = 0; findcent(y, x, findsiz(y, x));
		divcent(cent, DEP + 1);
	}
}
int main() {
	for (int i = (pw[0] = 1); i <= MAXN; i++) pw[i] = pw[i - 1] * BS;
	scanf("%d%d", &n, &m);
	if (!m) return puts("1"), 0;
	for (int i = 1; i <= n; i++) pE[++M] = make_pair(i, i % n + 1);
	for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), pE[++M] = make_pair(u, v);
	for (int i = 1; i <= M; i++) {
		G[pE[i].first].emplace_back(pE[i].second, i);
		G[pE[i].second].emplace_back(pE[i].first, i);
	}
	for (int i = 1; i <= n; i++) {
		sort(G[i].begin(), G[i].end());
		for (int j = 0; j < G[i].size(); j++)
			merge(get1(i, G[i][j].first, G[i][j].second),
				  get2(i, G[i][(j + 1) % G[i].size()].first, G[i][(j + 1) % G[i].size()].second));
	}
	for (int i = 1; i <= M * 2; i++) {
		st[find(i)].insert(pE[(i - 1) % M + 1].first);
		st[find(i)].insert(pE[(i - 1) % M + 1].second);
	}
	for (int i = 1; i <= M * 2; i++) if (!st[i].empty()) {
		pos[i] = ++k;
		for (int p : st[i]) vec[k].emplace_back(p);
	}
	for (int i = 1; i <= k; i++) {
		sort(vec[i].begin(), vec[i].end(), greater<int>());
		vec[i].emplace_back(0); hs[i].resize(vec[i].size());
		for (int j = 0; j < vec[i].size(); j++) hs[i][j] = ((!j) ? 0 : hs[i][j - 1]) + pw[vec[i][j]];
		ord[i] = i;
	}
	sort(ord + 1, ord + k + 1, cmp);
	for (int i = 1; i <= k; i++) rnk[ord[i]] = i;
	for (int i = n + 1; i <= M; i++) {
		adde(rnk[pos[find(i)]], rnk[pos[find(i + M)]]);
		adde(rnk[pos[find(i + M)]], rnk[pos[find(i)]]);
	}
	mx[0] = INF; findcent(1, 0, m + 1); divcent(cent, 1);
	for (int i = 1; i <= m + 1; i++) printf("%d%c", res[i], " \n"[i == m + 1]);
	return 0;
}