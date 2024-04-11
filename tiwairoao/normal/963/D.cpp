#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

#define pr make_pair
#define fi first
#define se second

const int N = 200000;

char s[N + 5], m[N + 5]; int ans[N + 5], lens, n;
vector<int>G[N + 5]; vector<pii>qry[N + 5];
namespace sam{
	int ep[N + 5], ch[26][N + 5], fa[N + 5], len[N + 5];
	int ncnt, lst, rt;
	
	void init() {
		ncnt = lst = rt = 1;
		for(int i=0;i<26;i++) ch[i][rt] = 0;
		fa[rt] = ep[rt] = len[rt] = 0;
	}
	int newnode() {
		int p = (++ncnt);
		for(int i=0;i<26;i++) ch[i][p] = 0;
		fa[p] = ep[p] = len[p] = 0; return p;
	}
	int clone(int q) {
		int nq = (++ncnt);
		for(int i=0;i<26;i++) ch[i][nq] = ch[i][q];
		fa[nq] = fa[q], ep[nq] = 0; return nq;
	}
	void extend(int c) {
		int cur = newnode(), p = lst;
		len[cur] = ep[cur] = len[lst] + 1, lst = cur;
		while( p && !ch[c][p] ) ch[c][p] = cur, p = fa[p];
		if( !p ) fa[cur] = rt;
		else {
			int q = ch[c][p];
			if( len[p] + 1 == len[q] ) fa[cur] = q;
			else {
				int nq = clone(q); len[nq] = len[p] + 1;
				fa[cur] = fa[q] = nq;
				while( p && ch[c][p] == q ) ch[c][p] = nq, p = fa[p];
			}
		}
	}
	
	int siz[N + 5], hvy[N + 5];
	void dfs1(int x) {
		siz[x] = 1;
		for(auto to : G[x]) {
			dfs1(to), siz[x] += siz[to];
			if( siz[to] > siz[hvy[x]] ) hvy[x] = to;
		}
	}
	
	set<int>st; int a[N + 5], cnt;
	void add(int x) {
		if( ep[x] ) st.insert(ep[x]);
		for(auto to : G[x]) add(to);
	}
	void dfs2(int x, bool kep) {
		for(auto to : G[x]) if( to != hvy[x] ) dfs2(to, false);
		if( hvy[x] ) dfs2(hvy[x], true);
		if( ep[x] ) st.insert(ep[x]);
		for(auto to : G[x]) if( to != hvy[x] ) add(to);
		
		if( !qry[x].empty() ) {
			cnt = 0; for(auto i : st) a[++cnt] = i;
			for(auto p : qry[x]) {
				if( p.fi <= cnt ) {
					int res = N + 5;
					for(int i=1;i+p.fi-1<=cnt;i++)
						res = min(res, a[i+p.fi-1] - a[i]);
					ans[p.se] += res;
				} else ans[p.se] = -1;
			}
		}
		if( !kep ) st.clear();
	}
	void solve() {
		for(int i=2;i<=ncnt;i++) G[fa[i]].push_back(i);
		dfs1(1), dfs2(1, false);
	}
}

int main() {
	scanf("%s%d", s, &n), lens = strlen(s), sam::init();
	for(int i=0;i<lens;i++) sam::extend(s[i] - 'a');
	
	for(int i=1,k,lenm;i<=n;i++) {
		scanf("%d%s", &k, m), lenm = strlen(m);
		
		int nw = sam::rt;
		for(int j=0;j<lenm;j++) {
			nw = sam::ch[m[j] - 'a'][nw];
			if( !nw ) break;
		}
		if( nw ) qry[nw].push_back(pr(k, i)), ans[i] = lenm;
		else ans[i] = -1;
	}
	sam::solve(); for(int i=1;i<=n;i++) printf("%d\n", ans[i]);
}