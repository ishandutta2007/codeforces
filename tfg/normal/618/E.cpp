#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const double PI = acos(-1);

struct PT {
	typedef double T;
	T x, y;
	PT(T xx = 0, T yy = 0) : x(xx), y(yy){}
	PT operator +(const PT &p) const { return PT(x+p.x,y+p.y); }
	PT operator -(const PT &p) const { return PT(x-p.x,y-p.y); }
	PT operator *(T c)         const { return PT(x*c,y*c);     }
	PT operator /(double c)    const { return PT(x/c,y/c);     }
	T operator *(const PT &p)  const { return x*p.x+y*p.y;     }
	T operator %(const PT &p)  const { return x*p.y-y*p.x;     }
	PT rotate(double d) const { return PT(cos(d) * x - sin(d) * y, sin(d) * x + cos(d) * y); }
	double operator !()        const { return sqrt(x*x+y*y);   }
	//double operator ^(const PT &p) const { return atan2(*this%p, *this*p);}
};

struct Node {
	Node(PT val = PT(0, 0)) {
		// init
		ans = val;
	}
	
	Node(Node &l, Node &r) {
		// merge
		ans = (l.ans + r.ans);
	}
	
	void apply(double lazy) {
		ans = ans.rotate(lazy);
	}
	
	// atributes
	PT ans;
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

	void upd(int x, e_t val) {
		push(x + n);
		tree[x + n] = i_t(val);
		build(x + n);
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


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	SegmentTree<Node, PT, double> tree;
	tree.init(std::vector<PT>(n, PT(1, 0)));
	std::cout << std::fixed << std::setprecision(10);
	while(m--) {
		int t, x, y;
		std::cin >> t >> x >> y;
		if(t == 1) {
			PT cur = tree.qry(x-1, x).ans;
			cur = cur + (cur / !(cur) * y);
			tree.upd(x-1, cur);
		} else {
			y = -y;
			tree.upd(x-1, n, y / 180.0 * PI);
		}
		PT ans = tree.qry(0, n).ans;
		std::cout << ans.x << ' ' << ans.y << '\n';
	}
}