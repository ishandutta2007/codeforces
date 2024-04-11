#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1000;

int dsu_p[N], dsu_r[N], dsu_c;

void dsu_new(int v) {
	dsu_p[v] = v;
	dsu_r[v] = 1;
	dsu_c++;
}

int dsu_find(int v) {
	if(dsu_p[v] == v)
		return v;
	return dsu_p[v] = dsu_find(dsu_p[v]);
}

void dsu_union(int a, int b) {
	a = dsu_find(a);
	b = dsu_find(b);
	
	if(a != b) {
		if(dsu_r[a] < dsu_r[b]) swap(a, b);
		dsu_p[b] = a;
		if(dsu_r[a] == dsu_r[b]) dsu_r[a]++;
	}
}

int n;
vector<int> mv[N];
vector<int> unions;
queue< pair<int, int> > q;
bool u[N];

void dfs(int from, int v) {
	if(!u[v]) dsu_new(v), u[v] = 1;

	for(int to : mv[v]) {
		if(u[to]) { 
			if(to != from && v < to) q.push({v, to});
		}
		else {
			dfs(v, to);
			dsu_union(v, to);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		mv[u-1].push_back(v-1);
		mv[v-1].push_back(u-1);
	}

	for(int i = 0; i < n; ++i) {
		if(u[i]) continue;
		dfs(n, i); unions.push_back(i);
	}

	cout << unions.size() - 1 << endl;
	for(int k = 1; k < unions.size(); ++k) {
		int i = q.front().first, j = q.front().second; q.pop();
		int u = dsu_find(0), v = dsu_find(unions[k]);
		cout << i+1 << ' ' << j+1 << ' ' << u+1 << ' ' << v+1 << endl;
	}
}