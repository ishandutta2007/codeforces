#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, q, u[300005], v[300005], w[300005];
int rt[600005], prv[600005][25], dep[600005];
int dfn[600005], dfo[600005], tot;
PII cw[300005];
vector<int> T[600005];
set<PII> segs;

struct segt
{
	PII mn[4000005], mx[4000005];
	pair<PII, PII> dat[4000005];
	int tag[4000005];
	void upd(int cv, int v) {
		if(v == 1) {
			dat[cv] = MP(mn[cv], mx[cv]);
		}
		if(v == 2) {
			dat[cv] = MP(MP(1e9, -1), MP(-1, -1));	
		}
	}
	void push(int cv) {
		if(tag[cv] == 0) return;
		upd(cv << 1, tag[cv]);
		upd(cv << 1 | 1, tag[cv]);
		tag[cv << 1] = tag[cv];
		tag[cv << 1 | 1] = tag[cv];
		tag[cv] = 0;
	}
	void build(int cv = 1, int cl = 1, int cr = n) {
		dat[cv] = MP(MP(1e9, -1), MP(-1, -1));
		tag[cv] = 0;
 		if(cl == cr) {
			mn[cv] = mx[cv] = MP(dfn[cl], cl); return;
		}
		int mid = cl + cr >> 1;
		build(cv << 1, cl, mid);
		build(cv << 1 | 1, mid + 1, cr);
		mn[cv] = min(mn[cv << 1], mn[cv << 1 | 1]);
		mx[cv] = max(mx[cv << 1], mx[cv << 1 | 1]);
	}
	void modify(int ql, int qr, int v, int cv = 1, int cl = 1, int cr = n) {
		if(cl > cr || ql > cr || qr < cl) return;
		if(ql <= cl && cr <= qr) {
			upd(cv, v);
			tag[cv] = v; 
			push(cv); 
			return;
		}
		int mid = cl + cr >> 1;
		push(cv);
		modify(ql, qr, v, cv << 1, cl, mid);
		modify(ql, qr, v, cv << 1 | 1, mid + 1, cr);
		dat[cv].first = min(dat[cv << 1].first, dat[cv << 1 | 1].first);
		dat[cv].second = max(dat[cv << 1].second, dat[cv << 1 | 1].second);
	}
}tre;

int root(int x) 
{
	return rt[x] == x ? x : rt[x] = root(rt[x]);
}
void dfs0(int v, int par)
{
	dfn[v] = ++ tot;
	dep[v] = dep[par] + 1;
	prv[v][0] = par;
	rep1(i, 24) prv[v][i] = prv[prv[v][i - 1]][i - 1];
	rep(i, T[v].size()) {
		int u = T[v][i];
		if(u == par) continue;
		dfs0(u, v);
	}
	dfo[v] = tot;
}
int lca(int u, int v)
{
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 24; i >= 0; i --) if(dep[prv[u][i]] >= dep[v]) u = prv[u][i];
	assert(dep[u] == dep[v]);
	for(int i = 24; i >= 0; i --) if(prv[u][i] != prv[v][i]) u = prv[u][i], v = prv[v][i];
	return u == v ? u : prv[v][0];
}
int calc(int u, int v)
{
	if(v < 0 || v > 2 * n || u == v) return -1;
	int l = lca(u, v);
	assert(l > n && l < 2 * n);
	return w[l - n - 1];
}
int main()
{
	scanf("%d%d", &n, &q);
	rep(i, n - 1) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		cw[i] = MP(w[i], i);
	}
	sort(cw, cw + n - 1);
	rep1(i, 2 * n) rt[i] = i;
	rep(i, n - 1) {
		int id = n + cw[i].second + 1;
		int j = cw[i].second;
		u[j] = root(u[j]); v[j] = root(v[j]);
		rt[u[j]] = id; rt[v[j]] = id;
		T[u[j]].push_back(id);
		T[id].push_back(u[j]);
		T[v[j]].push_back(id);
		T[id].push_back(v[j]);
	}
	int r = n + cw[n - 2].second + 1;
	dfs0(r, r);
	tre.build();
	while(q --) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			tre.modify(l, r, 1);
		} else if(t == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			tre.modify(l, r, 2);
		} else {
			int x;
			scanf("%d", &x);
			pair<PII, PII> sta = tre.dat[1];
			int L = sta.first.second;
			int R = sta.second.second;
			int ans = max(calc(x, L), calc(x, R)); 
			printf("%d\n", ans);
		}
	}
	return 0;
}