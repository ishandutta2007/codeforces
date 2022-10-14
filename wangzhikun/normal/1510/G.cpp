#include <bits/stdc++.h>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2020;
int n, k, fath[MAXN], deg[MAXN], valid[MAXN], depth[MAXN], mxdep[MAXN], lastver;
std::vector<int> sons[MAXN], answer;

void dfs0(int v, int dep) {
	depth[v] = mxdep[v] = dep;
	for(auto g : sons[v]) {
		dfs0(g, dep+1);
		mxdep[v] = max(mxdep[v], mxdep[g]);
	}
	sort(sons[v].begin(), sons[v].end(),
		[&](int x, int y) { return mxdep[x] < mxdep[y]; });
}
int deepest() {
	int v = 1;
	while(sons[v].size())
		v = sons[v].back();
	return v;
}
void dfs(int v) {
	lastver = v;
	answer.push_back(v);
	for(auto g : sons[v]) if(valid[v]) {
		dfs(g);
		answer.push_back(v);
	}
}
/*
3
6 2
1 1 2 2 3
6 6 
1 1 2 2 3
6 4
1 2 3 4 5
*/
void solve() {
	//puts("ZZ");
	scanf("%d%d", &n, &k);
	answer.clear();
	//puts("ZZ");
	rep(i, n) sons[i].clear(), valid[i] = true, deg[i] = 0;
	for(int i = 2; i <= n; ++i) {
		scanf("%d", &fath[i]);
		sons[fath[i]].push_back(i);
		deg[fath[i]]++;
	}
	dfs0(1, 1);
	//printf("FFF\n");
	int z = deepest();
	//printf("FFF z=%d\n",z);

	queue<int> q;
	rep(i, n) if(deg[i] == 0 && i != z) q.push(i);
	int cut = n-k;
	while(cut--) {
		if(q.size() == 0) q.push(z);
		int f = q.front();
		q.pop();
		//printf("%d invalid\n", f);
		valid[f] = false;
		if(--deg[fath[f]] == 0)
			q.push(fath[f]);
	}
	//rep(i, n) printf("VALID[%d] = %d\n", i, valid[i]);

	rep(i, n) if(valid[i]) {
		std::vector<int> mv;
		for(auto g: sons[i]) if(valid[g]) mv.push_back(g);
		sons[i] = mv;
	}
	dfs0(1, 1);
	//rep(i, n) if(valid[i]) for(auto g:sons[i]) printf("%d -> %d\n", i, g);

	dfs(1);
	while(answer.back() != lastver)
		answer.pop_back();
	printf("%d\n", (int)answer.size() - 1);
	for(auto g : answer)
		printf("%d ", g);
	printf("\n");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}