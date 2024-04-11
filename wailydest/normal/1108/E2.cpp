#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;

class SegmentTree {
	vector<int> tree;
	vector<int> add;
	vector<int> *arr;
	int n;
	
	void build(int v, int tl, int tr);
	void push(int v, int tl, int tr);
	void update(int v, int tl, int tr, int l, int r, int val);
	int query(int v, int tl, int tr, int l, int r);
public:
	SegmentTree(int size, vector<int> &ar) {
		n = size;
		arr = &ar;
		tree.resize(4 * n);
		add.resize(4 * n, 0);
		build(1, 0, n - 1);
	}
	void update(int l, int r, int val) 
	{
		update(1, 0, n - 1, l, r, val);
	}
	int query(int l, int r) 
	{
		return query(1, 0, n - 1, l, r);
	}
};
void SegmentTree::build(int v, int tl, int tr) 
{
	if (tl == tr) tree[v] = arr->at(tl);
	else {
		build(v * 2, tl, (tl + tr) / 2);
		build(v * 2 + 1, (tl + tr) / 2 + 1, tr);
		tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
	}
}
void SegmentTree::push(int v, int tl, int tr) 
{
	if (add[v] != 0) {
		tree[v] += add[v];
		if (tl != tr) {
			add[v * 2] += add[v];
			add[v * 2 + 1] += add[v];
		}
		add[v] = 0;
	}
}
void SegmentTree::update(int v, int tl, int tr, int l, int r, int val) 
{
	push(v, tl, tr);
	if (tr < l || tl > r) return;
	if (tl >= l && tr <= r) {
		add[v] = val;
		push(v, tl, tr);
		return;
	}
	update(v * 2, tl, (tl + tr) / 2, l, r, val);
	update(v * 2 + 1, (tl + tr) / 2 + 1, tr, l, r, val);
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}
int SegmentTree::query(int v, int tl, int tr, int l, int r) 
{
	push(v, tl, tr);
	if (tr < l || tl > r) return INT_MIN;
	if (tl >= l && tr <= r) return tree[v];
	return max(query(v * 2, tl, (tl + tr) / 2, l, r), query(v * 2 + 1, (tl + tr) / 2 + 1, tr, l, r));
}

int main() 
{
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	vector<pair<int, int> > seg(m);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < m; ++i) {
		cin >> seg[i].first;
		cin >> seg[i].second;
	}
	
	vector<int> seg_on_point_amt(n, 0);
	for (int i = 0; i < m; ++i) {
		for (int j = seg[i].first - 1; j < seg[i].second; ++j) ++seg_on_point_amt[j];
	}
	
	SegmentTree tr(n, arr);
	for (int i = 0; i < m; ++i) {
		if (seg[i].first - 1 == 0) tr.update(0, seg[i].second - 1, -1);
	}
	pair<int, int> max_res = make_pair(tr.query(0, n - 1) - arr[0] + seg_on_point_amt[0], 0);
	
	int result;
	for (int current = 1; current < n; ++current) {
		for (int i = 0; i < m; ++i) {
			if (seg[i].second == current) tr.update(seg[i].first - 1, seg[i].second - 1, 1);
			if (seg[i].first - 1 == current) tr.update(seg[i].first - 1, seg[i].second - 1, -1);
		}
		result = tr.query(0, n - 1) - arr[current] + seg_on_point_amt[current];
		if (max_res.first < result) max_res = make_pair(result, current);
	}

	cout << max_res.first << '\n';
	cout << seg_on_point_amt[max_res.second] << '\n';
	for (int i = 0; i < m; ++i) if (seg[i].first - 1 <= max_res.second && seg[i].second > max_res.second) cout << i + 1 << ' ';
	cout << '\n';
	
	return 0;
}