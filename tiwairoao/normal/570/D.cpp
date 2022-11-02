#include<map>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 500000;
struct query{
	int h, id;
	query(int _h=0, int _id=0):h(_h), id(_id){}
};
vector<query>qry[MAXN + 5];
vector<int>G[MAXN + 5];
void addedge(int u, int v) {G[u].push_back(v); }
int val[MAXN + 5], n, m;
bool ans[MAXN + 5];
int lowbit(int x) {
	return x & -x;
}
int siz[MAXN + 5], hvy[MAXN + 5], dep[MAXN + 5];
int dfn[MAXN + 5], le[MAXN + 5], ri[MAXN + 5], dcnt = 0;
void dfs1(int rt) {
	siz[rt] = 1;
	le[rt] = (++dcnt); dfn[dcnt] = rt;
	int maxize = -1; hvy[rt] = -1;
	for(int i=0;i<G[rt].size();i++) {
		int c = G[rt][i];
		dep[c] = dep[rt] + 1;
		dfs1(c);
		if( siz[c] > maxize ) {
			maxize = siz[c];
			hvy[rt] = c;
		}
		siz[rt] += siz[c];
	}
	ri[rt] = dcnt;
}
int key[MAXN + 5];
void dfs2(int rt, bool kep) {
	for(int i=0;i<G[rt].size();i++) {
		int c = G[rt][i];
		if( c == hvy[rt] ) continue;
		dfs2(c, false);
	}
	if( hvy[rt] == -1 ) {
		key[dep[rt]] ^= val[rt];
		for(int i=0;i<qry[rt].size();i++)
			ans[qry[rt][i].id] = true;
		if( !kep ) {
			for(int j=le[rt];j<=ri[rt];j++)
				key[dep[dfn[j]]] = 0;
		}
		return ;
	}
	dfs2(hvy[rt], true);
	key[dep[rt]] ^= val[rt];
	for(int i=0;i<G[rt].size();i++) {
		int c = G[rt][i];
		if( c == hvy[rt] ) continue;
		for(int j=le[c];j<=ri[c];j++)
			key[dep[dfn[j]]] ^= val[dfn[j]];
	}
	for(int i=0;i<qry[rt].size();i++) {
		if( lowbit(key[qry[rt][i].h]) == key[qry[rt][i].h] )
			ans[qry[rt][i].id] = true;
	}
	if( !kep ) {
		for(int j=le[rt];j<=ri[rt];j++)
			key[dep[dfn[j]]] = 0;
	}
}
char s[MAXN + 5];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=2;i<=n;i++) {
		int p;
		scanf("%d", &p);
		addedge(p, i);
	}
	scanf("%s", s);
	for(int i=0;i<n;i++)
		val[i+1] = (1<<(s[i]-'a'));
	for(int i=1;i<=m;i++) {
		int v, h;
		scanf("%d%d", &v, &h);
		qry[v].push_back(query(h, i));
	}
	dep[1] = 1;
	dfs1(1);
	dfs2(1, true);
	for(int i=1;i<=m;i++)
		if( ans[i] ) puts("Yes");
		else puts("No");
}