#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <stack>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct LazyContext {
	LazyContext(int v = 0) {
		sum = v;
	}
	
	void reset() {
		sum = 0;
	}
	
	void operator += (LazyContext o) {
		sum += o.sum;
	}
	
	// atributes
	int sum;
};

struct Node {
	Node() {
		ans = std::pair<int, int>(1e9, 0);
	}
	
	Node(int val) {
		// init
		ans = std::pair<int, int>(val, 1);
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans.first = std::min(l.ans.first, r.ans.first);
		ans.second = 0;
		if(ans.first == l.ans.first) ans.second += l.ans.second;
		if(ans.first == r.ans.first) ans.second += r.ans.second;
	}
	
	void apply(LazyContext lazy) {
		ans.first += lazy.sum;
	}
	
	// atributes
	std::pair<int, int> ans;
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
	int n;
	std::cin >> n;
	std::vector<int> p(n, -1);
	for(int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		x--;y--;
		p[x] = y;
	}
	std::stack<std::pair<int, int>> mx, mn;
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(std::vector<int>(n, 0));
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		assert(p[i] != -1);
		// solve max stack
		{
			int f = 1;
			while(!mx.empty() && p[mx.top().first] < p[i]) {
				//std::cout << "removing max from [" << i-f-mx.top().second+1 << ", " << i-f+1 << ")\n";
				tree.upd(i-f-mx.top().second+1, i-f+1, LazyContext(-p[mx.top().first]));
				f += mx.top().second;
				mx.pop();
			}
			//std::cout << "inserting max of " << p[i] << " at [" << i-f+1 << ", " << i+1 << ")\n";
			tree.upd(i-f+1, i+1, LazyContext(p[i]));
			mx.push(std::pair<int, int>(i, f));
		}
		// solve min stack
		{
			int f = 1;
			while(!mn.empty() && p[mn.top().first] > p[i]) {
				//std::cout << "removing min from [" << i-f-mx.top().second+1 << ", " << i-f+1 << ")\n";
				tree.upd(i-f-mn.top().second+1, i-f+1, LazyContext(p[mn.top().first]));
				f += mn.top().second;
				mn.pop();
			}
			//std::cout << "inserting min of " << p[i] << " at [" << i-f+1 << ", " << i+1 << ")\n";
			tree.upd(i-f+1, i+1, LazyContext(-p[i]));
			mn.push(std::pair<int, int>(i, f));
		}
		//std::cout << "at " << i << " got " << tree.qry(0, i+1).ans.second << '\n';
		tree.upd(0, i+1, LazyContext(-1));
		ans += tree.qry(0, i+1).ans.second;
	}
	std::cout << ans << '\n';
}