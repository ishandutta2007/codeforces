// Created time: 2022/5/2 15:43:51
#include <bits/stdc++.h>
using namespace std;
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
const int MAXN = 3e5;
const int LOG_N = 20;
const int INF = 0x3f3f3f3f;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
typedef pair<int, int> pii;
int n, qu, k; pii p[MAXN + 5];
vector<int> vec[MAXN + 5];
int len[MAXN + 5], begx[MAXN + 5], begy[MAXN + 5], bel[MAXN + 5];
map<int, int> id[MAXN + 5], has[MAXN + 5];
struct graph {
	int hd[MAXN + 5], to[MAXN * 4 + 5], nxt[MAXN * 4 + 5], ec = 0;
	void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
} G, T;
void insedge(int x, int y) {
	if (!has[x][y]) {
		T.adde(x, y); T.adde(y, x);
		has[x][y] = has[y][x] = 1;
	}
}
void init() {
	for (int i = 1; i <= MAXN; i++) {
		sort(vec[i].begin(), vec[i].end());
		for (int l = 0, r; l < vec[i].size(); l = r + 1) {
			r = l; while (r + 1 < vec[i].size() && vec[i][r + 1] == vec[i][r] + 1) ++r;
			++k; for (int j = l; j <= r; j++) bel[id[i][vec[i][j]]] = k;
			begx[k] = i; begy[k] = vec[i][l]; len[k] = r - l + 1;
			for (int j = l; j <= r; j++) if (id[i - 1][vec[i][j]])
				insedge(k, bel[id[i - 1][vec[i][j]]]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = p[i].first, y = p[i].second;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (id[nx][ny]) G.adde(i, id[nx][ny]);
		}
	}
}
int siz[MAXN + 5], mx[MAXN + 5], vis[MAXN + 5], cent;
int dfa[MAXN + 5], dep[MAXN + 5];
void findcent(int x, int f, int tot) {
	siz[x] = len[x]; mx[x] = 0;
	for (int e = T.hd[x]; e; e = T.nxt[e]) {
		int y = T.to[e]; if (y == f || vis[y]) continue;
		findcent(y, x, tot); siz[x] += siz[y]; chkmax(mx[x], siz[y]);
	}
	chkmax(mx[x], tot - siz[x]);
	if (mx[x] < mx[cent]) cent = x;
}
int getsiz(int x, int f) {
	int ret = len[x];
	for (int e = T.hd[x]; e; e = T.nxt[e]) {
		int y = T.to[e]; if (y == f || vis[y]) continue;
		ret += getsiz(y, x);
	}
	return ret;
}
vector<int> tr1[MAXN + 5], tr2[MAXN + 5];
int dis[MAXN + 5][LOG_N + 2], pos[MAXN + 5][LOG_N + 2];
void add1(int x, int p, int v) {for (int i = p; i <= len[x]; i += (i & (-i))) chkmin(tr1[x][i], v);}
void add2(int x, int p, int v) {for (int i = p; i; i -= (i & (-i))) chkmin(tr2[x][i], v);}
int query1(int x, int p) {int ret = INF; for (int i = p; i; i -= (i & (-i))) chkmin(ret, tr1[x][i]); return ret;}
int query2(int x, int p) {int ret = INF; for (int i = p; i <= len[x]; i += (i & (-i))) chkmin(ret, tr2[x][i]); return ret;}
void work(int x, int DEP) {
	queue<int> q;
	for (int i = begy[x]; i <= begy[x] + len[x] - 1; i++) {
		int ID = id[begx[x]][i]; q.push(ID);
		dis[ID][DEP] = 0; pos[ID][DEP] = i - begy[x] + 1;
	}
	while (!q.empty()) {
		int y = q.front(); q.pop();
		for (int e = G.hd[y]; e; e = G.nxt[e]) {
			int z = G.to[e];
			if (vis[bel[z]] || pos[z][DEP]) continue;
			dis[z][DEP] = dis[y][DEP] + 1; pos[z][DEP] = pos[y][DEP];
			q.push(z);
		}
	}
	vis[x] = 1;
	for (int i = 0; i <= len[x]; i++) tr1[x].push_back(INF), tr2[x].push_back(INF);
}
int divcent(int x, int DEP) {
	dep[x] = DEP; work(x, DEP);
	for (int e = T.hd[x]; e; e = T.nxt[e]) {
		int y = T.to[e]; if (vis[y]) continue;
		cent = 0; findcent(y, x, getsiz(y, x));
		dfa[cent] = x; divcent(cent, DEP + 1);
	}
}
void upd(int x) {
	int tmp = bel[x];
	while (tmp) {
		add1(tmp, pos[x][dep[tmp]], dis[x][dep[tmp]] - pos[x][dep[tmp]]);
		add2(tmp, pos[x][dep[tmp]], dis[x][dep[tmp]] + pos[x][dep[tmp]]);
		tmp = dfa[tmp];
	}
}
int qry(int x) {
	int tmp = bel[x], ret = INF;
	while (tmp) {
		chkmin(ret, query1(tmp, pos[x][dep[tmp]]) + dis[x][dep[tmp]] + pos[x][dep[tmp]]);
		chkmin(ret, query2(tmp, pos[x][dep[tmp]]) + dis[x][dep[tmp]] - pos[x][dep[tmp]]);
		tmp = dfa[tmp];
	}
	if (ret < 1e9) return ret;
	else return -1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
		id[p[i].first][p[i].second] = i;
		vec[p[i].first].push_back(p[i].second);
	}
	scanf("%d", &qu); init();
	mx[0] = INF; findcent(1, 0, n); divcent(cent, 1);
	while (qu--) {
		int opt, x, y; scanf("%d%d%d", &opt, &x, &y);
		if (opt == 1) upd(id[x][y]);
		else printf("%d\n", qry(id[x][y]));
	}
	return 0;
}