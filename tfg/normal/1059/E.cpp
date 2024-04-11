#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<int> edges[ms];
int weight[ms];
int in[ms], out[ms], t = 0, rin[ms];
int h[ms];
long long H[ms];

void prep(int on) {
	in[on] = t;
	rin[t] = on;
	t++;
	H[on] += weight[on];
	for(auto to : edges[on]) {
		h[to] = h[on] + 1;
		H[to] = H[on];
		prep(to);
	}
	out[on] = t;
	//std::cout << "out of " << on << ", [" << in[on] << ", " << out[on] << ")\n";
}

struct Node1 {
	Node1() {
		ans = {-1, -1};
	}
	
	Node1(std::pair<long long, int> v) {
		ans = v;
	}
	
	Node1(Node1 &l, Node1 &r) {
		ans = std::max(l.ans, r.ans);
	}
	
	void apply(int lazy) {
		lazy = 0;
	}
	
	// atributes
	std::pair<long long, int> ans;
};

struct Node2 {
	Node2() {
		ans = (int) 1e8;
	}
	
	Node2(int v) {
		ans = v;
	}
	
	Node2(Node2 &l, Node2 &r) {
		ans = std::min(l.ans, r.ans);
	}
	
	void apply(int lazy) {
		ans += lazy;
	}
	
	// atributes
	int ans;
};

template <class i_t, class e_t, class lazy_cont = int>
class SegTree {
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
			lazy[i] = 0;
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

	void upd(int x, e_t val) {
		x += n;
		push(x);
		tree[x] = i_t(val);
		build(x);
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
				lazy[i] = 0;
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

int ans[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, L;
	long long S;
	std::cin >> n >> L >> S;
	for(int i = 0; i < n; i++) {
		std::cin >> weight[i];
		if(weight[i] > S) {
			std::cout << "-1\n";
			return 0;
		}
	}
	for(int i = 1; i < n; i++) {
		int p;
		std::cin >> p;
		edges[p-1].push_back(i);
	}
	prep(0);
	std::vector<std::pair<long long, int>> base1(n);
	std::vector<std::pair<long long, int>> base2(n);
	for(int i = 0; i < n; i++) {
		base1[in[i]] = {h[i], in[i]};
		base2[in[i]] = {H[i], in[i]};
	}
	SegTree<Node1, std::pair<long long, int>, int> set1, set2;
	set1.init(base1);
	set2.init(base2);
	SegTree<Node2, int, int> trans;
	trans.init(std::vector<int>(n, n + 10));
	for(int i = n-1; i >= 0; i--) {
		int v = rin[i];
		//std::cout << "solving for " << v << std::endl;
		auto node1 = set1.qry(in[v], out[v]);
		while(node1.ans.first - h[v] + 1 > L) {
			int u = node1.ans.second;
			//std::cout << "first delete of " << u << std::endl;
			//std::cout << node1.ans.first << ", " << node1.ans.second << "\n";
			trans.upd(u, n + 10);
			set1.upd(u, {-1, -1});
			node1 = set1.qry(in[v], out[v]);
		}
		node1 = set2.qry(in[v], out[v]);
		while(node1.ans.first - (H[v] - weight[v]) > S) {
			int u = node1.ans.second;
			//std::cout << "second delete of " << u << std::endl;
			trans.upd(u, n + 10);
			set2.upd(u, {-1, -1});
			node1 = set2.qry(in[v], out[v]);
		}
		int tot = 0;
		for(auto to : edges[v]) {
			tot += ans[to];
		}
		for(auto to : edges[v]) {
			trans.upd(in[to], out[to], tot - ans[to]);
		}
		ans[v] = std::min(tot + 1, trans.qry(in[v], out[v]).ans);
		trans.upd(in[v], tot + 1);
	}
	std::cout << ans[0] << std::endl;
}