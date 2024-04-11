#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int N = 3e5L + 11;
int t[N], u[N], v[N];

struct edge {
	int v, type, dir, id;
};
vector <edge> e[N];

bool vis[N];
int ans[N];

void dfs1(int x) {
	vis[x] = 1;
	for(edge i : e[x]) if(!vis[i.v]) {
		ans[i.id] = i.dir;
		dfs1(i.v);
	}
}

void dfs2(int x) {
	vis[x] = 1;
	for(edge i : e[x]) if(!vis[i.v] && i.type == 1)
		dfs2(i.v);
}

int main() {
	int n, m, s; cin >> n >> m >> s;
	for(int i = 0; i < m; i ++) {
		scanf("%d%d%d", t + i, u + i, v + i);
		if(t[i] == 1)
			e[u[i]].pb({v[i], 1, -1, i});
		else {
			e[u[i]].pb({v[i], 2, 0, i});
			e[v[i]].pb({u[i], 2, 1, i});
		}
	}
	
	dfs1(s);
	cout << count(vis + 1, vis + n + 1, 1) << '\n';
	for(int i = 0; i < m; i ++) if(t[i] == 2)
		printf("%c", (ans[i] ? '-' : '+'));
	cout << '\n';
	
	memset(vis, 0, sizeof vis);
	dfs2(s);
	cout << count(vis + 1, vis + n + 1, 1) << '\n';
	for(int i = 0; i < m; i ++) if(t[i] == 2) {
		if(vis[u[i]] && !vis[v[i]])
			ans[i] = 1;
		if(!vis[u[i]] && vis[v[i]])
			ans[i] = 0;
		printf("%c", (ans[i] ? '-' : '+'));
	}
	cout << '\n';
	
	return 0;
}