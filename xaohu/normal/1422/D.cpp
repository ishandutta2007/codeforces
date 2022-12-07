#include <bits/stdc++.h>
#define pb push_back
#define sz(x)(int)x.size()
#define all(x)x.begin(),x.end()
 
using ll = long long;
using namespace std;

const int N = 1e5 + 5;

priority_queue <pair<int, int>> Q;
bool vis[N];
int n, m, xx[N], yy[N], d[N];
vector <pair<int, int>> G[N];
vector <int> X, Y;
map <int, vector <int>> MX, MY;

int dis(int i, int j) {
	return abs(xx[i] - xx[j]) + abs(yy[i] - yy[j]);
}

int dis2(int i, int j) {
	return min(abs(xx[i] - xx[j]), abs(yy[i] - yy[j]));
}

void add(int a, int b, int c) {
	G[a].pb({b, c});
	G[b].pb({a, c});
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> xx[0] >> yy[0] >> xx[m + 1] >> yy[m + 1];
	
	for (int i = 1; i <= m; ++i) {
		cin >> xx[i] >> yy[i];
		X.pb(xx[i]);
		MX[xx[i]].pb(i);
		Y.pb(yy[i]);
		MY[yy[i]].pb(i);
	}
	sort(all(X));
	sort(all(Y));
	X.erase(unique(all(X)), X.end());
	Y.erase(unique(all(Y)), Y.end());
	
	
	
	for (int i = 0; i <= m; ++i)
		add(i, m + 1, dis(i, m + 1));
	for (int i = 1; i <= m; ++i)
		add(0, i, dis2(0, i));
	for (auto it : MX) {
		int last = -1;
		for (auto x : it.second) {
			if (last != -1) {
				add(x, last, 0);
			}
			last = x;
		}
	}
	for (auto it : MY) {
		int last = -1;
		for (auto x : it.second) {
			if (last != -1) {
				add(x, last, 0);
			}
			last = x;
		}
	}
	for (int i = 1; i <= m; ++i) {
		int a = (int)(lower_bound(all(X), xx[i]) - X.begin());
		if (a) add(i, MX[X[a - 1]][0], X[a] - X[a - 1]);
		a = (int)(lower_bound(all(Y), yy[i]) - Y.begin());
		if (a) add(i, MY[Y[a - 1]][0], Y[a] - Y[a - 1]);
	}
	
	for (int i = 1; i <= m + 1; ++i)
		d[i] = 2e9 + 500;
	Q.push({0, 0});
	while (!Q.empty()) {
		int v = Q.top().second;
		Q.pop();
		if (vis[v]) continue;
		vis[v] = true;
		//~ cout << v << " -> " << d[v] << endl;
		for (auto [u, w] : G[v]) {
			int nd = d[v] + w;
			if (nd < d[u]) {
				d[u] = nd;
				Q.push({-nd, u});
			}
		}
	}
	cout << d[m + 1] << endl;
	return 0;
}