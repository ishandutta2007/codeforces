#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int MOD;

long long modinverse(long long a, long long b, long long s0 = 1, long long s1 = 0) {
    //std::cout << "on (" << a << ", " << b << ", " << s0 << ", " << s1 << ")\n";
    if(!b)
        return s0;
    else
        return modinverse(b, a % b, s1, s0 - s1 * (a / b));
}

struct LazyContext {
	LazyContext() {
		reset();
	}

	LazyContext(long long _v) {
		v = _v % MOD;
	}
	
	void reset() {
		v = 1;
	}
	
	void operator += (LazyContext o) {
		v = (long long) v * o.v % MOD;
	}
	
	// atributes
	long long v;
};

long long fexp(long long x, int e) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

struct Node {
	Node() {
		ans = 0;
	}

	Node(int v) {
		// init
		ans = v % MOD;
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = (l.ans + r.ans) % MOD;
	}
	
	void apply(LazyContext lazy) {
		ans = ans * lazy.v % MOD;
	}
	// atributes
	long long ans;
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
	
	void upd(int x, e_t v) {
		x += n;
		push(x);
		tree[x] = i_t(v);
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

template <class T>
class FenwickTree {
public:
	void init(int nn) {
		this->n = nn;
		bit.assign(n + 1, 0);
	}

	void init(const std::vector<T> &a) {
		n = a.size();
		bit.assign(n + 1, 0);
		for(int i = 1; i <= n; i++) {
			bit[i] += a[i - 1];
			if(i + (i & -i) <= n) {
				bit[i + (i & -i)] += bit[i];
			}
		}
	}

	T qry(int x) {
		x = std::min(x, n);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}
private:
	int n;
	std::vector<T> bit;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> MOD;
	std::vector<int> primes;
	{
		int x = MOD;
		for(int i = 2; i * i <= x; i++) {
			int e = 0;
			while(x % i == 0) {
				e++;
				x /= i;
			}
			if(e) {
				primes.emplace_back(i);
			}
		}
		if(x > 1) {
			primes.emplace_back(x);
		}
	}
	std::vector<FenwickTree<int>> fw(primes.size());
	for(auto &tree : fw) {
		tree.init(n + 10);
	}
	std::vector<int> a(n);
	std::vector<int> b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		b[i] = a[i];
		for(int j = 0; j < (int) primes.size(); j++) {
			int e = 0;
			while(b[i] % primes[j] == 0) {
				b[i] /= primes[j];
				e++;
			}
			if(e) {
				//std::cout << "got " << e << " times " << primes[j] << " for position " << i << "\n";
				fw[j].upd(i + 1, e);
				fw[j].upd(i + 2, -e);
			}
		}
		b[i] %= MOD;
		a[i] %= MOD;
		//std::cout << i << ": (" << a[i] << ", " << b[i] << ")\n";
		assert(b[i] != 0);
	}
	SegmentTree<Node, int, LazyContext> tree1, tree2;
	tree1.init(a);
	tree2.init(b);
	int q;
	std::cin >> q;
	while(q--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			// update
			int l, r;
			long long x;
			std::cin >> l >> r >> x;
			tree1.upd(l-1, r, LazyContext(x));
			for(int i = 0; i < (int) primes.size(); i++) {
				int e = 0;
				while(x % primes[i] == 0) {
					e++;
					x /= primes[i];
				}
				if(e) {
					fw[i].upd(l, e);
					fw[i].upd(r+1, -e);
				}
			}
			x %= MOD;
			assert(x != 0);
			tree2.upd(l-1, r, LazyContext(x));
		} else if(t == 2) {
			// division
			int p;
			long long x;
			std::cin >> p >> x;
			for(int i = 0; i < (int) primes.size(); i++) {
				int e = 0;
				while(x % primes[i] == 0) {
					e++;
					x /= primes[i];
				}
				if(e) {
					fw[i].upd(p, -e);
					fw[i].upd(p+1, e);
				}
			}
			x %= MOD;
			assert(x != 0);
			long long y = modinverse(x, MOD);
			y = (y % MOD + MOD) % MOD;
			assert(y * x % MOD == 1);
			tree2.upd(p-1, p, LazyContext(y));
			x = tree2.qry(p-1, p).ans;
			assert(x != 0);
			for(int i = 0; i < (int) primes.size(); i++) {
				x = (long long) x * fexp(primes[i], fw[i].qry(p)) % MOD;
			}
			tree1.upd(p-1, (int) x);
		} else {
			int l, r;
			std::cin >> l >> r;
			std::cout << tree1.qry(l-1, r).ans << '\n';
		}
	}
}