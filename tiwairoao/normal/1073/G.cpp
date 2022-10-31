#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 400000;

vector<int>G1[MAXN + 5], G2[MAXN + 5];
int fa[20][MAXN + 5], dep[MAXN + 5], tid[MAXN + 5], val[MAXN + 5], dcnt;
void dfs(int x, int f) {
	tid[x] = (++dcnt), dep[x] = dep[f] + 1, fa[0][x] = f;
	for(int i=1;i<20;i++) fa[i][x] = fa[i-1][fa[i-1][x]];
	for(unsigned i=0;i<G1[x].size();i++) dfs(G1[x][i], x);
}
int lca(int u, int v) {
	if( dep[u] < dep[v] ) swap(u, v);
	for(int i=19;i>=0;i--)
		if( dep[fa[i][u]] >= dep[v] )
			u = fa[i][u];
	if( u == v ) return u;
	for(int i=19;i>=0;i--)
		if( fa[i][u] != fa[i][v] )
			u = fa[i][u], v = fa[i][v];
	return fa[0][u];
}
namespace SAM{
	int root, lst, ncnt;
	int ch[26][MAXN + 5], len[MAXN + 5], fa[MAXN + 5];
	void init() {root = lst = ncnt = 1;}
	int clone(int q) {
		int nq = (++ncnt); fa[nq] = fa[q];
		for(int i=0;i<26;i++) ch[i][nq] = ch[i][q];
		return nq;
	}
	int extend(int c) {
		int cur = (++ncnt), p = lst; len[cur] = len[lst] + 1, lst = cur;
		while( p && !ch[c][p] ) ch[c][p] = cur, p = fa[p];
		if( !p ) fa[cur] = root;
		else {
			int q = ch[c][p];
			if( len[p] + 1 == len[q] ) fa[cur] = q;
			else {
				int nq = clone(q); len[nq] = len[p] + 1;
				fa[q] = fa[cur] = nq;
				while( p && ch[c][p] == q ) ch[c][p] = nq, p = fa[p];
			}
		}
		return cur;
	}
	void get() {
		for(int i=2;i<=ncnt;i++)
			G1[fa[i]].push_back(i), val[i] = len[i];
		dfs(root, 0);
	}
}

int a[MAXN + 5], b[MAXN + 5], c[MAXN + 5], pos[MAXN + 5], cnt;
bool cmp(int x, int y) {return tid[x] < tid[y];}

int stk[MAXN + 5], tp, arr[MAXN + 5], tot;
void insert(int x) {
	if( tp ) {
		int l = lca(stk[tp], x);
		if( tid[l] < tid[stk[tp]] ) {
			while( tp ) {
				int y = stk[tp--]; arr[++tot] = y, l = lca(x, y);
				if( !tp || tid[l] > tid[stk[tp]] ) {
					stk[++tp] = l, G2[l].push_back(y);
					break;
				}
				else {
					G2[stk[tp]].push_back(y);
					if( l == stk[tp] ) break;
				}
			}
		}
	}
	stk[++tp] = x;
}

ll ans; int cnta[MAXN + 5], cntb[MAXN + 5];
void dfs2(int x) {
	ans += 1LL*cnta[x]*cntb[x]*val[x];
	for(unsigned i=0;i<G2[x].size();i++) {
		int to = G2[x][i];
		dfs2(to), ans += (1LL*cnta[x]*cntb[to] + 1LL*cntb[x]*cnta[to])*val[x];
		cnta[x] += cnta[to], cntb[x] += cntb[to];
	}
}

char s[MAXN + 5];
int main() {
	int n, q; scanf("%d%d%s", &n, &q, s), reverse(s, s + n), SAM::init();
	for(int i=0;i<n;i++) pos[n - i] = SAM::extend(s[i] - 'a'); SAM::get();
	for(int i=1,k,l,rt;i<=q;i++) {
		scanf("%d%d", &k, &l), cnt = 0;
		for(int j=1;j<=k;j++) scanf("%d", &a[j]), c[++cnt] = pos[a[j]];
		for(int j=1;j<=l;j++) scanf("%d", &b[j]), c[++cnt] = pos[b[j]];
		sort(c + 1, c + cnt + 1, cmp), cnt = unique(c + 1, c + cnt + 1) - c - 1, tot = 0;
		for(int j=1;j<=cnt;j++) insert(c[j]);
		while( tp ) {
			int x = stk[tp--]; arr[++tot] = x;
			if( tp ) G2[stk[tp]].push_back(x);
			else rt = x;
		}
		for(int j=1;j<=k;j++) cnta[pos[a[j]]]++;
		for(int j=1;j<=l;j++) cntb[pos[b[j]]]++;
		ans = 0, dfs2(rt), printf("%lld\n", ans);
		for(int j=1;j<=tot;j++) G2[arr[j]].clear(), cnta[arr[j]] = cntb[arr[j]] = 0;
	}
}
/*
20 10

cbbaccacbbcaaaababaa

1 18

10

1 2 3 4 5 6 7 9 10 12 13 14 15 16 17 18 19 20




*/