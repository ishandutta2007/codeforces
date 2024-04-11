#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

struct LazyContext {
	LazyContext() {
		reset();
	}

	LazyContext(int _v, long long _msk) {
		v = _v;
		mask = _msk;
	}
	
	void reset() {
		v = 1;
		mask = 0;
	}
	
	void operator += (LazyContext o) {
		v = (long long) v * o.v % MOD;
		mask |= o.mask;
	}
	
	// atributes
	long long v;
	long long mask;
};

long long fexp(long long x, int e = MOD - 2) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

std::vector<int> primes;
std::vector<long long> inv;

long long getMask(int v) {
	long long ans = 0;
	for(int i = 0; i < (int) primes.size(); i++) {
		if(v % primes[i] == 0) {
			ans |= 1LL << i;
		}
	}
	return ans;
}

struct Node {
	Node() {
		ans = 1;
		mask = 0;
		size = 0;
	}

	Node(int v) {
		// init
		ans = v;
		mask = getMask(v);
		size = 1;
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = (long long) l.ans * r.ans % MOD;
		mask = l.mask | r.mask;
		size = l.size + r.size;
	}
	
	void apply(LazyContext lazy) {
		ans = (long long) ans * fexp(lazy.v, size) % MOD;
		mask |= lazy.mask;
	}
	
	long long get() {
		long long x = ans;
		for(int i = 0; i < (int) primes.size(); i++) {
			if(mask & (1LL << i)) {
				x = (long long) x * inv[i] % MOD;
			}
		}
		return x;
	}

	// atributes
	long long ans;
	long long mask;
	int size;
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

bool isPrime(int x) {
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 2; i <= 300; i++) {
		if(isPrime(i)) {
			primes.push_back(i);
			inv.push_back((long long) fexp(i) * (i - 1) % MOD);
		}
	}
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	SegmentTree<Node, int, LazyContext> tree;
	tree.init(a);
	while(q--) {
		std::string str;
		std::cin >> str;
		if(str[0] == 'T') {
			int l, r;
			std::cin >> l >> r;
			std::cout << tree.qry(l-1, r).get() << '\n';
		} else {
			int l, r, v;
			std::cin >> l >> r >> v;
			tree.upd(l-1, r, LazyContext(v, getMask(v)));
		}
	}
}