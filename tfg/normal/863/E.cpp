#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node(int v = 2) {
		// init
		ans = v;
	}
	
	Node(Node l, Node r) {
		// merge
		ans = std::min(l.ans, r.ans);
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
	int n;
	std::cin >> n;
	std::map<int, int> wtf;
	std::vector<std::pair<int, int>> a(n);
	for(auto &p : a) {
		std::cin >> p.first >> p.second;
		p.second++;
		wtf[p.first] = wtf[p.second] = 0;
	}
	int c = 0;
	for(auto &it : wtf) {
		it.second = c++;
	}
	std::vector<int> sum(c + 1, 0);
	for(auto &p : a) {
		p.first = wtf[p.first];
		p.second = wtf[p.second];
		sum[p.first]++;
		sum[p.second]--;
	}
	for(int i = 1; i <= c; i++) {
		sum[i] += sum[i-1];
	}
	c = 0;
	SegmentTree<Node, int> tree;
	tree.init(sum);
	for(auto p : a) {
		c++;
		if(tree.qry(p.first, p.second).ans > 1) {
			std::cout << c << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
}