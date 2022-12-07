#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define x first
#define y second

typedef long long ll;
using namespace std;

const int T = 1 << 20;

pair<int, int> mini[T + T];
int lazy[T + T];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
	if (a.x == b.x) return {a.x, a.y + b.y};
	if (a.x < b.x) return a;
	return b;
}

void push(int v) {
	for (auto u : {v+v, v+v+1}) {
		lazy[u] += lazy[v];
		mini[u].x += lazy[v];
	}
	lazy[v] = 0;
}

void add(int x, int y, int z, int v = 1, int l = 0, int r = T - 1) {
	if (y < l || r < x) return;
	if (x <= l && r <= y) {
		lazy[v] += z;
		mini[v].x += z;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	add(x, y, z, v+v, l, m);
	add(x, y, z, v+v+1, m + 1, r);
	mini[v] = merge(mini[v+v], mini[v+v+1]);
}

pair<int, int> query(int x, int y, int v = 1, int l = 0, int r = T - 1) {
	if (y < l || r < x) return {1e9, 0};
	if (x <= l && r <= y) return mini[v];
	push(v);
	int m = (l + r) / 2;
	pair<int, int> ans = {1e9, 0};
	ans = merge(ans, query(x, y, v+v, l, m));
	ans = merge(ans, query(x, y, v+v+1, m + 1, r));
	return ans;
}

const int N = 1e6;

int n, a[N];
vector <int> vals[N];

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;
	
	for (int i = 0; i < T; ++i) 
		if (i < n) mini[i + T].y = mini[i + T].x = 1;
	for (int i = T - 1; 1 <= i; --i)
		mini[i] = merge(mini[i+i], mini[i+i+1]);
	
	FOR(i, n) cin >> a[i], a[i]--;
	FOR(i, n) vals[i].push_back(-1);
	int block = -1;
	ll ans = 0;
	FOR(i, n) {
		add(i, i, -1);
		vals[a[i]].push_back(i);
		int sz = (int)vals[a[i]].size();
		for (int j = 1; j < sz; ++j) {
			int r = vals[a[i]][sz - j];
			if (j == 4) {
				block = max(block, r);
				break;
			}
			int l = vals[a[i]][sz - j - 1] + 1;
			if (j == 1) add(l, r, 1);
			if (j == 2) ;
			if (j == 3) add(l, r, -1);
		}
		auto it = query(block + 1, i);
		if (it.x == 0) ans += it.y;
	}
	printf ("%lld\n", ans);
	return 0;
}