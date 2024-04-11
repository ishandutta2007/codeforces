#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;
const int MX_ROW = 2e6;

int seg_tree[4 * MX_ROW];
int lazy[4 * MX_ROW];
int n;

void push(int v) {
	for (int i = 0; i < 2; ++i) {
		seg_tree[v * 2 + i] += lazy[v];
		lazy[v * 2 + i] += lazy[v];
	}
	lazy[v] = 0;
}

void upd(int a, int b, int val, int v = 1, int l = 1, int r = MX_ROW) {
	if (b < l || r < a) {
		return;
	} else if (a <= l && r <= b) {
		seg_tree[v] += val;
		lazy[v] += val;
	} else {
		push(v);
		int m = (l + r) / 2;
		upd(a, b, val, v * 2, l, m);
		upd(a, b, val, v * 2 + 1, m + 1, r);
		seg_tree[v] = max(seg_tree[v * 2], seg_tree[v * 2 + 1]);
	}
}

int qry(int a, int b, int v = 1, int l = 1, int r = MX_ROW) {
	if (b < l || r < a) {
		return -1e9;
	} else if (a <= l && r <= b) {
		return seg_tree[v];
	} else {
		push(v);
		int m = (l + r) / 2;
		return max(qry(a, b, v * 2, l, m),
				qry(a, b, v * 2 + 1, m + 1, r));
	}
}

void display() {
	//for (int i = 1; i <= 2 * n; ++i) {
		//cout << qry(i, i) << " ";
	//}
	//cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, m;
	cin >> n >> k >> m;

	for (int i = 1; i <= MX_ROW; ++i) {
		upd(1, i, -1);
	}
	display();

	set<pair<int, int>> pawns;
	map<int, int> where;
	while (m--) {
		int x, y;
		cin >> x >> y;

		int proj = y + abs(k - x);

		if (pawns.count({x, y})) {
			pawns.erase({x, y});
			--where[proj];
			if (!where[proj]) {
				where.erase(proj);
			}
			upd(1, proj, -1);
		} else {
			pawns.emplace(x, y);
			++where[proj];
			upd(1, proj, 1);
		}
		display();

		int lb = n;
		int rb = MX_ROW;
		if (!where.empty()) {
	        lb = max(lb, where.rbegin()->first);
		}

		while (lb <= rb) {
			int mb = (lb + rb) / 2;
			if (qry(1, mb) <= mb - MX_ROW) {
				rb = mb - 1;
			} else {
				lb = mb + 1;
			}
		}

		cout << lb - n << "\n";
	}
}