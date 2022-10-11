#include <iostream>
#include <vector>
#include <utility>

struct Node {
	Node() {
		// empty constructor
		size = 0;
		ans = pref = suf = -1;
	}
	
	Node(std::pair<int, int> x) {
		// init
		ans = 0;
		size = x.first;
		suf = pref = 2 * x.second;
	}
	
	Node(Node l, Node r) {
		// merge
		if(l.size == 0) {
			*this = r;
		} else if(r.size == 0) {
			*this = l;
		} else {
			ans = std::max(l.ans, r.ans);
			ans = std::max(ans, r.pref + l.size + l.suf);
			pref = std::max(l.pref, r.pref + l.size);
			suf = std::max(l.suf, r.suf - l.size);
			size = l.size + r.size;
		}
	}

	void print() {
		//std::cout << "(size, ans, pref, suf) : (" << size << ", " << ans << ", " << pref << ", " << suf << ")\n";
	}

	// atributes
	long long size;
	long long ans, pref, suf;
};

template <class i_t, class e_t>
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
	
	void upd(int pos, e_t v) {
		pos += n;
		tree[pos] = i_t(v);
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
	
private:
	int n;
	std::vector<i_t> tree;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> base(n);
	for(int i = 0; i < n; i++) {
		std::cin >> base[i].first;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> base[i].second;
	}
	SegmentTree<Node, std::pair<int, int>> tree;
	tree.init(base);
	while(m--) {
		int l, r;
		std::cin >> l >> r;
		if(l <= r) {
			//std::cout << "left is "; tree.qry(r, n).print();
			//std::cout << "right is"; tree.qry(0, l - 1).print();
			std::cout << Node(tree.qry(r, n), tree.qry(0, l - 1)).ans << std::endl;
		} else {
			std::cout << tree.qry(r, l - 1).ans << std::endl;
		}
	}
}