#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// Range update, range query segment tree

struct LazyContext {
	LazyContext(int a = 0, int b = 0) {
		t = a, sum = b;
	}
	
	void reset() {
		t = sum = 0;
	}
	
	void operator += (LazyContext o) {
		t += o.t;
		sum += o.sum;
	}
	
	// atributes
	int t, sum;
};

struct Node {
	Node() {
		// neutral element or empty node
		t = 2;
	}
	
	Node(int x) {
		// init
		t = 0;
		sum = 0;
		id = x;
	}
	
	Node(Node &l, Node &r) {
		// merge
		if(l < r) {
			*this = l;
		} else {
			*this = r;
		}
	}
	
	void apply(LazyContext lazy) {
		t += lazy.t;
		sum += lazy.sum;
	}
	
	bool operator < (Node o) const {
		if(t != o.t) return t < o.t;
		if(sum != o.sum) return sum < o.sum;
		return id < o.id;
	}

	// atributes
	int t, sum, id;
};

template <class i_t, class e_t, class lazy_cont = int>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		h = 0;
		while((1 << h) < n) h++;
		tree.resize(2 * n);
		dirty.assign(n, false);
		lazy.resize(n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
			lazy[i].reset();
		}
	}
	
	i_t qry(int l, int r) {
		if(l >= r) return i_t();
		l += n, r += n;
		push(l);
		push(r - 1);
		i_t lp, rp;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
	
	void upd(int l, int r, lazy_cont lc) {
		if(l >= r) return;
		l += n, r += n;
		push(l);
		push(r - 1);
		int l0 = l, r0 = r;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) apply(l++, lc);
			if(r & 1) apply(--r, lc);
		}
		build(l0);
		build(r0 - 1);
	}
	
private:
	int n, h;
	std::vector<bool> dirty;
	std::vector<i_t> tree;
	std::vector<lazy_cont> lazy;
	
	void apply(int p, lazy_cont &lc) {
		tree[p].apply(lc);
		if(p < n) {
			dirty[p] = true;
			lazy[p] += lc;
		}
	}
	
	void push(int p) {
		for(int s = h; s > 0; s--) {
			int i = p >> s;
			if(dirty[i]) {
				apply(i + i, lazy[i]);
				apply(i + i + 1, lazy[i]);
				lazy[i].reset();
				dirty[i] = false;
			}
		}
	}
	
	void build(int p) {
		for(p /= 2; p > 0; p /= 2) {
			tree[p] = i_t(tree[p + p], tree[p + p + 1]);
			if(dirty[p]) {
				tree[p].apply(lazy[p]);
			}
		}
	}
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	long long cur = 0;
	std::vector<int> a(n);
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(p);
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] != a[v2] ? a[v1] < a[v2] : v1 < v2; });
	//for(auto x : p) std::cout << x << '\n';
	std::queue<int> q;
	std::vector<long long> ans(n, -1);
	int pt = 0;
	int got = 0;
	while(got < n) {
		if(q.empty() || (pt < n && a[p[pt]] <= cur + k)) {
			// insert pt guy in there
			int on = p[pt++];
			if(tree.qry(on, on + 1).sum == 0) {
				// insert into queue directly
				//std::cout << "inserting " << on << std::endl;
				if(q.empty()) {
					cur = a[on];
				}
				q.push(on);
				tree.upd(on + 1, n, LazyContext(0, 1));
				tree.upd(on, on + 1, LazyContext(1, 0));
			} else {
				//std::cout << "waiting for " << on << std::endl;
				tree.upd(on, on + 1, LazyContext(-1, 0));
			}
		} else {
			// remove from queue
			int on = q.front();
			q.pop();
			tree.upd(on + 1, n, LazyContext(0, -1));
			got++;
			auto root = tree.qry(0, n);
			cur += k;
			ans[on] = cur;
			//std::cout << "removing " << on << std::endl;
			if(root.t == -1 && root.sum == 0) {
				// insert id in queue
				int id = root.id;
				tree.upd(id, id + 1, LazyContext(2, 0));
				tree.upd(id + 1, n, LazyContext(0, 1));
				q.push(id);
				//std::cout << "inserting2 " << id << std::endl;
			}
		}
	}
	//for(auto x : p) std::cout << x << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}