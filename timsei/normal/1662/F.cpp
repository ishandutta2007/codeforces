#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int T, n, a, b, dis[maxn], vis[maxn], val[maxn];
vector<int>tr[maxn << 2];
set<int>s;
inline void Build(int o, int l, int r) {
	tr[o].clear();
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	Build(o << 1, l, mid), Build(o << 1 | 1, mid + 1, r);
}
inline void Add(int o, int l, int r, int ql, int qr, int d) {
	if(ql <= l && r <= qr) {
// cerr << o << " " << l << " " << r << " " << d << endl;
		tr[o].push_back(d);
		return;
	}
	int mid = (l + r) >> 1;
	if(ql <= mid)
		Add(o << 1, l, mid, ql, qr, d);
	if(qr > mid)
		Add(o << 1 | 1, mid + 1, r, ql, qr, d);
}
inline void Upd(int o, int l, int r, int p) {
	for(auto id : tr[o])
		if(!vis[id])
			vis[id] = 1, s.insert(id);
	tr[o].clear();
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	if(p <= mid)
		Upd(o << 1, l, mid, p);
	else
		Upd(o << 1 | 1, mid + 1, r, p);
}
queue<int>q;
int main() {
	for(scanf("%d", &T); T --; ) {
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 1; i <= n; ++ i)
			dis[i] = 0x3f3f3f3f, vis[i] = 0;
		s.clear();
		Build(1, 1, n);
		for(int i = 1; i <= n; ++ i)
			scanf("%d", &val[i]), Add(1, 1, n, max(1, i - val[i]), min(n, i + val[i]), i);
		while(!q.empty())
			q.pop();
		vis[a] = 1, dis[a] = 0, q.push(a);
		s.insert(n + 1);
		while(!q.empty()) {
			int u = q.front();
// cerr << u << " " << dis[u] << endl;
			q.pop();
			if(u == b)
				break;
			Upd(1, 1, n, u);
			int l = max(1, u - val[u]), r = min(n, u + val[u]);
			auto it = s.lower_bound(l);
			while(1) {
				int v = *it;
				if(v > r)
					break;
// cerr << u << " -> " << v << " " << dis[u] << " " << dis[v] << endl;
				if(abs(u - v) <= min(val[u], val[v]) && dis[v] > dis[u] + 1)
					dis[v] = dis[u] + 1, q.push(v), s.erase(it), it = s.lower_bound(l);
				else
					++ it;
			}
		}
		printf("%d\n", dis[b]);
	}
}