#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m, d, p[N];
bool u[N], u2[N], ok;
vector<int> mv[N];

int dsu_r[N], dsu_p[N], dsu_c;

void dsu_new(int v) {
	dsu_r[v] = 1;
	dsu_p[v] = v;
	dsu_c++;
}

int dsu_root(int v) {
	if(v == dsu_p[v]) 
		return v;
	return dsu_p[v] = dsu_root(dsu_p[v]);
}

void dsu_unite(int a, int b) {
	a = dsu_root(a);
	b = dsu_root(b);
	if(a != b) {
		if(dsu_r[a] < dsu_r[b]) swap(a, b);
		dsu_p[b] = a;
		if(dsu_r[a] == dsu_r[b]) ++dsu_r[a];
		dsu_c--;
	}
}

void bfs(queue<int>& q) {
	while(!q.empty()) {
		int c = q.front(); q.pop();

		for(int to : mv[c]) {
			if(u[to]) continue;

			u[to] = true;
			cout << c+1 << ' ' << to+1 << endl;
			q.push(to);
		}
	}
}

void dfs(int v) {
	u[v] = true;
	for(int to : mv[v]) {
		if(!u[to]) dfs(to);
		if(v != 0 && to != 0) dsu_unite(v, to);
	}

	if(v == 0) {
		if(d < dsu_c - 1 || d > mv[0].size()) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			fill(u, u+n, false); u[0] = true;
			d -= dsu_c - 1;
			queue<int> q;

			for(int to : mv[v]) {
				if(u2[dsu_root(to)]) continue;

				u[to] = true;
				u2[dsu_root(to)] = true;
				cout << "1 " << to+1 << endl;
				q.push(to);
			}

			for(int to : mv[v]) {
				if(d == 0) break;
				if(u[to]) continue;

				u[to] = true;
				cout << "1 " << to+1 << endl;
				q.push(to); --d;
			}

			bfs(q);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(cin >> n >> m >> d; m--;) {
		int a, b; cin >> a >> b;
		mv[a-1].push_back(b-1);
		mv[b-1].push_back(a-1);
	}

	for(int i = 0; i < n; ++i)
		dsu_new(i);

	dfs(0);
}