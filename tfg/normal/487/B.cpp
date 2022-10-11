#include <vector>

struct Node {
	Node() {
		// empty constructor
		min = 1e9;
		max = -1e9;
	}
	
	Node(int v) {
		// init
		min = v, max = v;
	}
	
	Node(Node l, Node r) {
		// merge
		min = std::min(l.min, r.min);
		max = std::max(l.max, r.max);
	}

	int diff() { return max - min; }

	// atributes
	int min, max;
};

template <class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(4 * n);
		build(1, 0, n - 1, base);
	}
	
	i_t qry(int l, int r) { return qry(1, 0, n - 1, l, r - 1); }
private:
	int n;
	std::vector<i_t> tree;

	void build(int p, int l, int r, std::vector<e_t> &base) {
		if(l == r) {
			tree[p] = i_t(base[l]);
		} else {
			int mid = (l + r) / 2;
			build(p + p, l, mid, base);
			build(p + p + 1, mid + 1, r, base);
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
		}
	}

	i_t qry(int p, int l, int r, int i, int j) {
		if(i > r || j < l) {
			return i_t();
		} else if(i <= l && r <= j) {
			return tree[p];
		} else {
			int mid = (l + r) / 2;
			return i_t(qry(p + p, l, mid, i, j), qry(p + p + 1, mid + 1, r, i, j));
		}
	}
};

#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

std::vector<int> events[100100][2];

int main() {
	int n, s, len;
	std::cin >> n >> s >> len;
	std::vector<int> base(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &base[i]);
	}
	SegmentTree<Node, int> tree;
	tree.init(base);
	std::vector<int> dp(n + 1, (int) 1e9);
	std::multiset<int> vals;
	events[0][0].push_back(0);
	events[0][1].push_back(0);
	for(int i = 0, j = 0; i + len <= n; i++) {
		for(auto v : events[i][0]) vals.insert(v);
		if(vals.size() == 0) continue;
		dp[i] = *vals.begin();
		for(auto v : events[i][1]) vals.erase(vals.find(v));
		if(tree.qry(i, i + len).diff() > s) continue;
		j = std::max(j, i + len);
		while(j < n && tree.qry(i, j + 1).diff() <= s) j++;
		events[i + len][0].push_back(dp[i] + 1);
		events[j][1].push_back(dp[i] + 1);
	}
	if(events[n][1].size() == 0) {
		events[n][1].push_back(-1);
	}
	std::sort(events[n][1].begin(), events[n][1].end());
	std::cout << events[n][1][0] << std::endl;
}