#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 500000;
vector<pair<int, char> >G[MAXN + 5];
void addedge(int u, int v, char ch) {
	G[u].push_back(make_pair(v, ch));
}
inline int lowbit(int x) {
	return x & -x;
}
int siz[MAXN + 5], ans[MAXN + 5];
int po[26 + 5], Max[MAXN + 5];
int Stt[(1<<23) + 5], vis[(1<<23) + 5], f, g;
vector<int>Vec;
void ADD(int x, int dep, int col) {
	if( !vis[col^f] ) {
		Stt[col^f] = dep - g;
		vis[col^f] = true;
		Vec.push_back(col^f);
	}
	else Stt[col^f] = max(dep-g, Stt[col^f]);
	for(int i=0;i<G[x].size();i++)
		ADD(G[x][i].first, dep+1, col^po[G[x][i].second-'a']);
}
void QUERY(int x, int dep, int col, int rt) {
	for(int i=0;i<22;i++)
		if( vis[col^po[i]^f] )
			ans[rt] = max(ans[rt], dep + g + Stt[col^po[i]^f]);
	if( vis[col^f] )
		ans[rt] = max(ans[rt], dep + g + Stt[col^f]);
	for(int i=0;i<G[x].size();i++)
		QUERY(G[x][i].first, dep+1, col^po[G[x][i].second-'a'], rt);
}
void dfs(int x, bool kep) {
	ans[x] = 0;
	if( Max[x] == -1 ) {
		if( kep ) {
			Stt[0] = 0;
			vis[0] = true;
			Vec.push_back(0);
		}
		return ;
	}
	for(int i=0;i<G[x].size();i++) {
		int c = G[x][i].first;
		if( i != Max[x] ) {
			dfs(c, false);
			ans[x] = max(ans[x], ans[c]);
		}
	}
	dfs(G[x][Max[x]].first, true);
	ans[x] = max(ans[x], ans[G[x][Max[x]].first]);
	f = f ^ po[G[x][Max[x]].second-'a'];
	g = g + 1;
	for(int i=0;i<G[x].size();i++) {
		if( i == Max[x] ) continue;
		QUERY(G[x][i].first, 1, po[G[x][i].second-'a'], x);
		ADD(G[x][i].first, 1, po[G[x][i].second-'a']);
	}
	for(int i=0;i<22;i++) {
		if( vis[po[i]^f] )
			ans[x] = max(ans[x], Stt[po[i]^f] + g);
	}
	if( vis[f] ) ans[x] = max(ans[x], Stt[f]+g);
	if( !vis[f] ) {
		Stt[f] = -g;
		vis[f] = true;
		Vec.push_back(f);
	}
	else Stt[f] = max(-g, Stt[f]);
	if( !kep ) {
		for(int i=0;i<Vec.size();i++)
			Stt[Vec[i]] = vis[Vec[i]] = 0;
		f = g = 0;
		Vec.clear();
	}
}
char s[3];
void dfs2(int x) {
	siz[x] = 1;
	int maxiz = -1; Max[x] = -1;
	for(int i=0;i<G[x].size();i++) {
		int c = G[x][i].first;
		dfs2(c);
		siz[x] = siz[x] + siz[c];
		if( siz[c] > maxiz ) {
			maxiz = siz[c];
			Max[x] = i;
		}
	}
}
int main() {
	po[0] = 1;
	for(int i=1;i<26;i++)
		po[i] = po[i-1] * 2;
	int n, p;
	scanf("%d", &n);
	for(int i=2;i<=n;i++) {
		scanf("%d%s", &p, s);
		addedge(p, i, s[0]);
	}
	dfs2(1);
	dfs(1, true);
	for(int i=1;i<n;i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[n]);
}