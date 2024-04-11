#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 400000;

namespace segtree{
	int ch[2][40*MAXN + 5], cnt[40*MAXN + 5], ncnt;
	
	int insert(int pre, int l, int r, int p) {
		int x = (++ncnt); cnt[x] = cnt[pre] + 1;
		if( l != r ) {
			int m = (l + r) >> 1;
			if( p <= m ) ch[0][x] = insert(ch[0][pre], l, m, p), ch[1][x] = ch[1][pre];
			else ch[1][x] = insert(ch[1][pre], m + 1, r, p), ch[0][x] = ch[0][pre];
		}	
		return x;
	}
	int sum(int x, int l, int r, int ql, int qr) {
		if( !x || ql > r || qr < l ) return 0;
		if( ql <= l && r <= qr ) return cnt[x];
		int m = (l + r) >> 1;
		return sum(ch[0][x], l, m, ql, qr) + sum(ch[1][x], m + 1, r, ql, qr);
	}
	int merge(int x, int y) {
		if( !x || !y ) return x + y;
		int p = (++ncnt); cnt[p] = cnt[x] + cnt[y];
		ch[0][p] = merge(ch[0][x], ch[0][y]);
		ch[1][p] = merge(ch[1][x], ch[1][y]);
		return p;
	}
}

int n, q;

namespace SAM{
	int root, lst, ncnt;
	int ch[26][MAXN + 5], fa[MAXN + 5], len[MAXN + 5];
	int rt[MAXN + 5];
	
	void init() {root = lst = ncnt = 1;}
	int clone(int q) {
		int nq = (++ncnt); fa[nq] = fa[q];
		for(int i=0;i<26;i++) ch[i][nq] = ch[i][q];
		rt[nq] = 0; return nq;
	}
	int extend(int c, int k) {
		int p = lst, cur = (++ncnt);
		rt[cur] = segtree::insert(rt[cur], 1, n, k), len[cur] = len[lst] + 1, lst = cur;
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
	
	vector<int>G[MAXN + 5];
	void dfs(int x) {
		for(unsigned i=0;i<G[x].size();i++)
			dfs(G[x][i]), rt[x] = segtree::merge(rt[x], rt[G[x][i]]);
	}
	void get() {
		for(int i=2;i<=ncnt;i++)
			G[fa[i]].push_back(i);
		dfs(root);
	}
}

char s[MAXN + 5]; int id[MAXN + 5];
int main() {
	scanf("%d%d", &n, &q), SAM::init();
	for(int i=1,len;i<=n;i++) {
		scanf("%s", s), len = strlen(s);
		SAM::lst = SAM::root;
		for(int j=0;j<len;j++)
			id[i] = SAM::extend(s[j] - 'a', i);
	}
	
	for(int i=1;i<=n;i++)
		while( SAM::len[SAM::fa[id[i]]] == SAM::len[id[i]] )
			id[i] = SAM::fa[id[i]];
	
	SAM::get();
	for(int i=1,l,r,k;i<=q;i++) {
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", segtree::sum(SAM::rt[id[k]], 1, n, l, r));
	}
}