#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node(int v = 0) {
		ans = v;
	}
	Node(Node l, Node r) {
		// merge
		ans = l.ans | r.ans;
	}

	int val() {
		int bits = 0;
		for(int i = 0; i < 26; i++) {
			if(ans & (1 << i)) {
				bits++;
			}
		}
		return bits;
	}
	// atributes
	int ans;
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
	std::string str;
	std::cin >> str;
	SegmentTree<Node, int> tree;
	std::vector<int> a;
	for(int i = 0; i < (int) str.size(); i++) {
		a.push_back(1 << (str[i] - 'a'));
	}
	tree.init(a);
	int q;
	std::cin >> q;
	while(q--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			int pos;
			char c;
			std::cin >> pos >> c;
			tree.upd(pos-1, 1 << (c - 'a'));
		} else {
			int l, r;
			std::cin >> l >> r;
			std::cout << tree.qry(l-1, r).val() << '\n';
		}
	}
}