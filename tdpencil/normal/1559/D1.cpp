#include <bits/stdc++.h>
using namespace std;
const int mxN=1005;
int e1[mxN], e2[mxN];
int n, m1, m2;
int l(int *e, int num) {
	return e[num] < 0 ? num : e[num] = l(e, e[num]);
}
bool m(int *e, int u, int v) {
	int f=l(e,u),s=l(e,v);
	if(f!=s) {
		if(e[f] > e[s]) {
			swap(f, s);
		}
		e[f] += e[s];
		e[s] = f;
		return 1;
	}
	return 0;
}
bool sc(int *e, int u, int v) {
	return l(e,u)==l(e,v);
}
void solve() {
	cin >> n >> m1 >> m2;
	memset(e1, -1, 4*n);
	memset(e2, -1, 4*n);
	for (int i = 0; i < m1; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		m(e1,u,v);
	}
	for (int i = 0; i < m2; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		m(e2,u,v);
	}
	// return;
	vector<pair<int, int>> added_edges;
	for (int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(!sc(e1,i,j)&&!sc(e2,i,j)) {
				added_edges.push_back({i, j});
				m(e1,i,j);
				m(e2,i,j);
			}
		}
	}

	cout << added_edges.size() << "\n";
	for(auto u : added_edges) {
		cout << u.first+1 << " " << u.second+1 << "\n";
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t=1;

	while(t--) {
		solve();
	}
}