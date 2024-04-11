#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

const int ms = 200100;

int n;

int tree[ms];

void build() {
	memset(tree, -1, sizeof tree);
}

void upd(int pos, int val) {
	pos += n;
	tree[pos] = val;
	while(pos > 1) {
		pos /= 2;
		tree[pos] = std::max(tree[pos + pos], tree[pos + pos + 1]);
	}
}

int qry(int l, int r) {
	int ans = -1;
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l & 1) ans = std::max(ans, tree[l++]);
		if(r & 1) ans = std::max(ans, tree[--r]);
	}
	return ans;
}

int a[ms];

struct Info {
	int l, r, idx;
	void read(int i) {
		idx = i;
		std::cin >> l >> r;
		l--;
		r--;
	}
};

struct BIT {
	int a[ms];
	void init() {
		memset(a, 0, sizeof a);
	}
	int qry(int x) {x++;
		int ans = 0;for(; x > 0; x -= x & -x) ans += a[x];return ans;
	}
	void upd(int x, int v) {x++;
		for(; x < ms; x += x & -x) a[x] += v;
	}
};

BIT wtf;

bool operator < (Info a, Info b) {
	return a.l < b.l;
}

Info qries[ms];

std::vector<int> pos[ms];
int where[ms];
int ans[ms], to[ms];

int main() {
	std::cin >> n;
	wtf.init();
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		pos[a[i]].push_back(i);
	}
	build();
	int m;
	std::cin >> m;
	for(int i = 0; i < m; i++) {
		qries[i].read(i);
	}
	for(int i = 0; i < ms; i++) {
		if(pos[i].empty()) continue;
		for(int j = pos[i].size() - 1; j >= 0; j--) {
			if(pos[i].size() - j <= 2) {
				to[pos[i][j]] = n + 10;
			} else {
				if(pos[i][j] - pos[i][j + 1] == pos[i][j + 1] - pos[i][j + 2]) {
					to[pos[i][j]] = to[pos[i][j + 1]];
				} else {
					to[pos[i][j]] = pos[i][j + 2] - 1;
				}
			}
		}
		wtf.upd(pos[i][0], 1);
		upd(pos[i][0], to[pos[i][0]]);
	}
	std::sort(qries, qries + m);
	int p = 0;
	for(int i = 0; i < m; i++) {
		while(p < qries[i].l) {
			wtf.upd(p, -1);
			upd(p, -1);
			where[a[p]]++;
			if(where[a[p]] < pos[a[p]].size()) {
				upd(pos[a[p]][where[a[p]]], to[pos[a[p]][where[a[p]]]]);
				wtf.upd(pos[a[p]][where[a[p]]], 1);
			}
			p++;
		}
		ans[qries[i].idx] = wtf.qry(qries[i].r) + 1;
		if(qry(qries[i].l, qries[i].r + 1) >= qries[i].r) ans[qries[i].idx]--;
	}
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << '\n';
	}
}