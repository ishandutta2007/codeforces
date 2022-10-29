#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
const int maxn = 200010;
vector<int> G[maxn];
typedef long long LL;
vector<int> tmp, f[maxn];
LL ans, g[maxn];
bool visit[maxn];
int n, K;
inline void init(vector<int>& f) {
	for (int i = 0; i < K; ++i) f.PB(0);
}
inline void change(vector<int>& f) {
	for (int j = 0; j < K; ++j)
		tmp[j] = f[j];
	for (int j = 0; j < K; ++j)
		f[j] = tmp[(j + K - 1) % K];
}
void dfs(int x) {
	visit[x] = true;
	init(f[x]);
	for (auto v : G[x]) {
		if (visit[v]) continue;
		dfs(v);
		for (int j = 0; j < K; ++j)
			f[x][j] += f[v][j];
		g[x] += g[v] + f[v][0]; 
	}
	change(f[x]);
	++f[x][0];
}
void dfs2(int x, vector<int> h, LL s) {
	visit[x] = true;
	s += h[0];
	change(h);
	
	ans += s + g[x];

	for (int j = 0; j < K; ++j)
		h[j] += f[x][j];

	s += g[x];

	for (auto v : G[x])  {
		if (visit[v]) continue;
		for (int j = 0; j < K; ++j)
			h[j] -= f[v][(j + K - 1) % K];
		s -= g[v] + f[v][0];
		dfs2(v, h, s);
		for (int j = 0; j < K; ++j)
			h[j] += f[v][(j + K - 1) % K];
		s += g[v] + f[v][0];
	}
}
int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].PB(v);
		G[v].PB(u);
	}
	tmp.resize(K);
	dfs(1);
	
	memset(visit, 0, sizeof visit);
	vector<int> t;
	init(t);
	dfs2(1, t, 0);
	
	cout << ans / 2 << endl;
}