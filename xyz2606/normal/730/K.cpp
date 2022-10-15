#include<bits/stdc++.h>
using namespace std;
const int N(444444), M(1111111);
int a[M], b[M], dir[M];
vector<pair<int, int> > aux[N];
bool vst[N];
int fa[N], fae[N], dep[N], lnk[N];
vector<pair<int, int> > edges[N];
int main() {
	int tests;
	cin >> tests;
	for(int qq(0); qq < tests; qq++) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		for(int i(1); i <= n; i++) {
			edges[i].clear();
			vst[i] = false;
			aux[i].clear();
		}
		for(int i(0); i < m; i++) {
			cin >> a[i] >> b[i];
			edges[a[i]].push_back(make_pair(b[i], i));
			edges[b[i]].push_back(make_pair(a[i], i));
			dir[i] = -1;
		}
		static vector<pair<int, int> > q;
		q.clear();
		q.push_back(make_pair(s, 0));
		vst[s] = true;
		fa[s] = 0;
		dep[s] = 0;
		while(!q.empty()) {
			int v(q.back().first), p(q.back().second++);
			if(p != edges[v].size()) {
				int y(edges[v][p].first);
				if(y == fa[v]) {
					continue;
				}
				if(!vst[y]) {
					//printf("%d->%d\n", v, y);
					vst[y] = true;
					lnk[v] = y;
					fa[y] = v;
					fae[y] = edges[v][p].second;
					dep[y] = dep[v] + 1;
					q.push_back(make_pair(y, 0));
				}else if(dep[y] < dep[v]) {
					//printf("%d %d\n", lnk[y], v);
					aux[lnk[y]].push_back(make_pair(v, edges[v][p].second));
				}
			}else {
				q.pop_back();
			}
		}
		bool ok(true);
		if(!vst[t]) {
			ok = false;
		}
		q.clear();
		q.push_back(make_pair(t, 1));
		for(int i(0); i < (int)q.size(); i++) {
			int v(q[i].first), d(q[i].second);
			while(fa[v] && dir[fae[v]] == -1) {
				dir[fae[v]] = d;
				//printf("%d %d %d\n", v, fae[v], d);
				for(auto p : aux[v]) {
					dir[p.second] = d;
					q.push_back(make_pair(p.first, d ^ 1));
				}
				v = fa[v];
			}
		}
		for(int i(0); i < m; i++) {
			if(dir[i] == -1) {
				ok = false;
				break;
			}
		}
		if(!ok) {
			printf("No\n");
		}else {
			printf("Yes\n");
			for(int i(0); i < m; i++) {
				if((dep[a[i]] < dep[b[i]]) != dir[i]) {
					swap(a[i], b[i]);
				}
				printf("%d %d\n", a[i], b[i]);
			}
		}
	}
}