#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	Node() {
		ans = lp = rp = size = 0;
	}

	Node(int v) {
		// init
		ans = lp = rp = v;
		size = 1;
	}
	
	Node(Node l, Node r) {
		// merge
		ans = std::max(l.ans, std::max(r.ans, r.lp + l.rp));
		this->lp = l.lp;
		if(l.size == l.lp) {
			lp += r.lp;
		}
		this->rp = r.rp;
		if(r.size == r.rp) {
			rp += l.rp;
		}
		size = l.size + r.size;
	}

	// atributes
	int ans, lp, rp, size;
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
	std::vector<int> a(n), p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] > a[v2]; });
	struct Query {
		int id, l, r, mid;
		int left, right, w;
		void calculateMid() {
			mid = (l + r) / 2;
		}
		bool operator < (const Query &o) const { return mid < o.mid; }
	};
	int m;
	std::cin >> m;
	std::vector<Query> qries(m);
	for(int i = 0; i < m; i++) {
		qries[i].l = 0;
		qries[i].r = n-1;
		qries[i].id = i;
		std::cin >> qries[i].left >> qries[i].right >> qries[i].w;
		qries[i].left--;
		qries[i].calculateMid();
	}
	SegmentTree<Node, int> tree;
	while(1) {
		std::sort(qries.begin(), qries.end());
		int pt = -1;
		tree.init(std::vector<int>(n, 0));
		bool run = false;
		for(auto &q : qries) {
			while(pt < q.mid) {
				tree.upd(p[++pt], 1);
			}
			//std::cout << "qry on " << pt << ", " << a[p[pt]] << ", for id " << q.id << " gets " << tree.qry(q.left, q.right).ans << '\n';
			if(tree.qry(q.left, q.right).ans >= q.w) {
				q.r = q.mid;
			} else {
				q.l = q.mid + 1;
			}
			q.calculateMid();
			run = run || q.l != q.r;
		}
		if(!run) break;
	}
	std::vector<int> ans(m);
	for(auto q : qries) {
		ans[q.id] = a[p[q.l]];
	}
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << '\n';
	}
}