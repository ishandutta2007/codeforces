#include <cstdio>
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%d: ", __LINE__); fprintf(stderr, args);
#else
#	define debug(args...) //
#endif
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 100008;
int n, m;
vector<int> adj[MAX];
int c[MAX];
int ord[MAX], to[MAX], from[MAX];
bool seen[MAX];
int tempo;
int dfs(int u) {
	if(seen[u]) return 0;
	seen[u] = true;
	int sz = 1;
	for(int v : adj[u])
		sz += dfs(v);
	from[u] = tempo - sz + 1;
	to[u] = tempo;
	ord[tempo++] = u;
	return sz;
}

int qv[MAX], qk[MAX];
int qs[MAX];
int sq_n;
bool cmp_block(int i, int j) {
	return ((int) (from[qv[i]] / sq_n)) < ((int) (from[qv[j]] / sq_n));
}

bool cmp_r(int i, int j) {
	return to[qv[i]] < to[qv[j]];
}

int l, r, k, resp;
int cores[MAX];
// num_cores[k] numero de cores com pelo menos k na resp
int num_cores[MAX];
inline void add(int v) {
	num_cores[++cores[c[v]]]++;
}
inline void rem(int v) {
	num_cores[cores[c[v]]--]--;
}

inline void right_l() {
	if(l > r) { l++; return; }
	rem(ord[l++]);
}
inline void left_l() {
	if(l > r + 1) { l--; return; }
	add(ord[--l]);
}
inline void right_r() {
	if(r < l - 1) { r++; return; }
	add(ord[++r]);
}
inline void left_r() {
	if(r < l) { r--; return; }
	rem(ord[r--]);
}


int main() {
	int i, j, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	tempo = 0;
	dfs(0);
	for(i = 0; i < m; i++) {
		qs[i] = i;
		scanf("%d %d", &qv[i], &qk[i]); qv[i]--;
	}
	for(sq_n = 1; sq_n * sq_n <= m; sq_n++); sq_n--;
	sort(qs, qs + m, cmp_r);
	stable_sort(qs, qs + m, cmp_block);
	l = 0; r = -1; k = 0; resp = 0;
	for(i = 0; i < m; i++) {
		while(l < from[qv[qs[i]]]) right_l();
		while(l > from[qv[qs[i]]]) left_l();
		while(r < to[qv[qs[i]]]) right_r();
		while(r > to[qv[qs[i]]]) left_r();
		qv[qs[i]] = num_cores[qk[qs[i]]]; // qv guarda a resposta
	}
	for(i = 0; i < m; i++)
		printf("%d\n", qv[i]);
	return 0;
}