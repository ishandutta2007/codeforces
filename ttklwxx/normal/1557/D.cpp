#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define ll long long
#define sz(s) (int)(s.size())
#define INF 0x3f3f3f3f3f3f3f3fLL
#define all(v) v.begin(),v.end()
#define watch(x) cout<<(#x)<<" = "<<x<<endl
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
#if __cplusplus >= 201402L
template<typename T>
vector<T> create(size_t n) {
	return vector<T>(n);
}
template<typename T, typename ... Args>
auto create(size_t n, Args ... args) {
	return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}
#endif
void run() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#else
#endif
}
 
 
const pair<int, int> NIL = { 0,-1 };
struct segment_tree {
#define LEFT (idx<<1)
#define RIGHT (idx<<1|1)
#define MID (start+end>>1)
	int n;
	vector<pair<int, int>> tree, lazy;
	segment_tree(int n) :n(n) {
		tree = lazy = vector<pair<int, int>>(n << 2, NIL);
	}
	void push_down(int idx, int start, int end) {
		if (lazy[idx] == NIL)
			return;
		tree[idx] = max(tree[idx], lazy[idx]);
		if (start != end) {
			lazy[LEFT] = max(lazy[LEFT], lazy[idx]);
			lazy[RIGHT] = max(lazy[RIGHT], lazy[idx]);
		}
		lazy[idx] = NIL;
	}
	void update(int idx, int start, int end, int l, int r, pair<int, int> p) {
		push_down(idx, start, end);
		if (r < start || end < l)
			return;
		if (l <= start && end <= r) {
			lazy[idx] = max(lazy[idx], p);
			push_down(idx, start, end);
			return;
		}
		update(LEFT, start, MID, l, r, p);
		update(RIGHT, MID + 1, end, l, r, p);
		tree[idx] = max(tree[LEFT], tree[RIGHT]);
	}
	pair<int, int> query(int idx, int start, int end, int l, int r) {
		push_down(idx, start, end);
		if (r < start || end < l)
			return NIL;
		if (l <= start && end <= r)
			return tree[idx];
		return max(query(LEFT, start, MID, l, r),
			query(RIGHT, MID + 1, end, l, r));
	}
	void update(int l, int r,pair<int,int> p) {
		update(1, 1, n, l, r, p);
	}
	pair<int, int> query(int l, int r) {
		return query(1, 1, n, l, r);
	}
};
int main() {
	run();
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n);
	vector<int> id;
	while (m--) {
		int i, l, r;
		cin >> i >> l >> r;
		id.push_back(l);
		id.push_back(r);
		v[i - 1].push_back({ l,r });
	}
	sort(all(id));
	id.erase(unique(all(id)), id.end());
	for (int i = 0; i < n; i++)
		for (auto& it : v[i]) {
			it.first = upper_bound(all(id), it.first) - id.begin();
			it.second = upper_bound(all(id), it.second) - id.begin();
		}
	segment_tree seg(id.size());
	vector<int> prv(n, -1);
	for (int i = 0; i < n; i++) {
		pair<int, int> mx = NIL;
		for (auto& it : v[i])
			mx = max(mx, seg.query(it.first, it.second));
 
		prv[i] = mx.second;
		mx.first++;
		mx.second = i;
		for (auto& it : v[i])
			seg.update(it.first, it.second, mx);
	}
	pair<int, int> p = seg.query(1, id.size());
	vector<bool> vis(n);
	int cur = p.second;
	while (cur != -1) {
		vis[cur] = true;
		cur = prv[cur];
	}
 
	cout << n - p.first << endl;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			cout << i + 1 << ' ';
}