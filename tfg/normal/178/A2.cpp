#include <iostream>
#include <vector>

struct Node {
	Node(int v = 1e9) {
		min = v;
	}

	Node(Node l, Node r) {
		min = std::min(l.min, r.min);
	}

	int min;
};

template<class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
		}
	}

	i_t qry(int l, int r) {
		i_t lp, rp;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
private:
	int n;
	std::vector<i_t> tree;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> dist(n, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		dist[i] = dist[i / 2] + i % 2;
	}
	SegmentTree<Node, int> tree;
	tree.init(dist);
	std::vector<long long> ans(n + 1, 0);
	for(int i = 0; i + 1 < n; i++) {
		int l = 1, r = n - i;
		while(l < r) {
			int nl = l, nr = r - 1;
			int got = tree.qry(nl, r).min;
			ans[i + l - 1] += got * a[i];
			while(nl < nr) {
				int mid = (nl + nr + 1) / 2;
				if(tree.qry(mid, r).min > got) {
					nr = mid - 1;
				} else {
					nl = mid;
				}
			}
			//std::cout << "starting from " << i << ", got " << got << " on [" << i + l - 1 << ", " << i + nl << ")\n";
			ans[i + nl] -= got * a[i];
			l = nl + 1;
		}
	}
	for(int i = 1; i < n; i++) {
		ans[i] += ans[i - 1];
	}
	for(int i = 0; i + 1 < n; i++) {
		std::cout << ans[i] << std::endl;
	}
}