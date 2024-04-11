#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, child[N];
bool visit[N];
vector<int> a[N];
char rankn[N];

void dfs(int u, int p) {
    child[u] = 1;
    for(int v: a[u]) if(v != p && !visit[v]) {
        dfs(v, u);
        child[u] += child[v];
    }
}

int findcen(int u, int p, int sz) {
    for(int v: a[u]) if(v != p && !visit[v]) {
        if(child[v] > sz / 2) return findcen(v, u, sz);
    }
    return u;
}

void centroid(int root, int rnk) {
	dfs(root, root);
    int cen = findcen(root, root, child[root]);
    /*
    .....
    */
    visit[cen] = true;
    rankn[cen] = (char)('A' + rnk);
    for(int v: a[cen]) if(!visit[v]) {
    	centroid(v, rnk + 1);
    }
}

int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	centroid(1, 0);
	for (int i = 1; i <= n; i++) cout << rankn[i] << " ";
}