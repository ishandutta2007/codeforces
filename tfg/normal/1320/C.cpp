#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 2e9 + 10;

struct Node {
	Node() {
		sum = 0;
		ans = -INF;
	}

	Node(long long v) {
		ans = sum = v;
	}
	
	Node(Node l, Node r) {
		ans = std::max(l.ans, r.ans + l.sum);
		sum = l.sum + r.sum;
	}

	// atributes
	long long ans, sum;
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
	int n, m, p;
	std::cin >> n >> m >> p;
	const int ms = 1 << 20;
	std::vector<long long> a(ms, INF), b(ms, INF);
	std::vector<std::vector<std::pair<int, int>>> monster(ms);
	while(n--) {
		int val, cost;
		std::cin >> val >> cost;
		a[val] = std::min(a[val], (long long) cost);
	}
	while(m--) {
		int val, cost;
		std::cin >> val >> cost;
		b[val] = std::min(b[val], (long long) cost);
	}
	for(int i = ms-1; i > 0; i--) {
		a[i-1] = std::min(a[i-1], a[i]);
		b[i-1] = std::min(b[i-1], b[i]);
	}
	while(p--) {
		int x, y, z;
		std::cin >> x >> y >> z;
		if(a[x+1] < INF && b[y+1] < INF) {
			monster[x].emplace_back(y, z);
		}
	}
	for(auto &x : a) x = -x;
	for(auto &x : b) x = -x;
	std::vector<long long> B(ms);
	B[0] = b[0];
	for(int i = 1; i < ms; i++) {
		B[i] = b[i] - b[i-1];
	}
	SegmentTree<Node, long long> tree;
	tree.init(B);
	long long ans = a[0] + b[0];
	for(int i = 0; i < ms; i++) {
		if(a[i] <= -INF) break;
		// check ans
		//std::cout << "at " << i << " got best " << tree.qry(0, ms).ans << "\n";
		ans = std::max(ans, a[i] + tree.qry(0, ms).ans);
		// update
		for(auto mon : monster[i]) {
			//std::cout << "updating at " << mon.first+1 << " with " << mon.second << '\n';
			tree.upd(mon.first+1, tree.qry(mon.first+1, mon.first+2).sum + mon.second);
		}
	}
	std::cout << ans << '\n';
}