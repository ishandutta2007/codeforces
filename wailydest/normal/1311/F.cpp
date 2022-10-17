#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX_SIZE = 200000;

class SegmentTree {
	vector<long long> tree;
	long long *arr;
	int n;
	void build(int v, int tl, int tr);
	void update(int v, int tl, int tr, int i);
	long long query(int v, int tl, int tr, int l, int r);
public: 
	SegmentTree(long long *ar, int size) {
		arr = ar;
		n = size;
		tree.reserve(n * 4 + 1);
	}
	void build() {
		build(1, 0, n - 1);
	}
	void update(int i, long long x) {
		arr[i] = x;
		update(1, 0, n - 1, i);
	}
	long long query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}
};

bool comp_second(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}

int main() 
{
	int n;
	cin >> n;
	
	vector<pair<int, int> > point(n);
	
	for (int i = 0; i < n; ++i) cin >> point[i].first;
	for (int i = 0; i < n; ++i) cin >> point[i].second;
	
	sort(point.begin(), point.end(), comp_second);
	
	int prev_val = point[0].second, current_val;
	point[0].second = 0;
	for (int i = 1; i < n; ++i) {
		current_val = point[i].second;
		point[i].second = point[i - 1].second + (prev_val != current_val);
		prev_val = current_val;
	}
	
	sort(point.begin(), point.end());
	
	long long amount[MAX_SIZE];
	long long coordinates[MAX_SIZE];
	
	for (int i = 0; i < n; ++i) amount[i] = 0;
	SegmentTree tree_amount(amount, n);
	tree_amount.build();
	
	for (int i = 0; i < n; ++i) coordinates[i] = 0;
	SegmentTree tree_coordinates(coordinates, n);
	tree_coordinates.build();
	
	long long answer = 0;
	
	for (int i = 0; i < n; ++i) {
		answer += - tree_coordinates.query(0, point[i].second) + tree_amount.query(0, point[i].second) * (long long)point[i].first;
		tree_amount.update(point[i].second, amount[point[i].second] + 1);
		tree_coordinates.update(point[i].second, coordinates[point[i].second] + point[i].first);
	}
	
	cout << answer << '\n';
	
	return 0;
}

void SegmentTree::build(int v, int tl, int tr) 
{
	if (tl == tr) {
		tree[v] = arr[tl];
		return;
	}
	build(v * 2, tl, (tl + tr) / 2);
	build(v * 2 + 1, (tl + tr) / 2 + 1, tr);
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}
void SegmentTree::update(int v, int tl, int tr, int i) 
{
	if (tl == tr) {
		tree[v] = arr[tl];
		return;
	}
	if (i <= (tl + tr) / 2) update(v * 2, tl, (tl + tr) / 2, i);
	else update(v * 2 + 1, (tl + tr) / 2 + 1, tr, i);
	tree[v] = tree[v * 2] + tree[v * 2 + 1];
}
long long SegmentTree::query(int v, int tl, int tr, int l, int r) 
{
	if (l > r) return 0;
	if (l == tl && r == tr) return tree[v];
	return query(v * 2, tl, (tl + tr) / 2, l, min((tl + tr) / 2, r)) + query(v * 2 + 1, (tl + tr) / 2 + 1, tr, max(l, (tl + tr) / 2 + 1), r);
}