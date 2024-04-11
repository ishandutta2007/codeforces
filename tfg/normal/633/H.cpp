#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <set>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct LazyContext {
	LazyContext() { }
	void reset() { }
	void operator += (LazyContext o) { }
	// atributes
};

int mod;
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase o) { *this = *this + o; }
	void operator -= (modBase o) { *this = *this - o; }
	void operator *= (modBase o) { *this = *this * o; }
	modBase operator * (modBase o) { return (int)(val * o.val % mod); }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase operator + (modBase o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase operator - (modBase o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

struct Info {
	Info(int x) {
		val = x;
		recalc();
	}

	void recalc() {
		if(freq <= 0) {
			a[0] = 1, a[1] = 0;
			b[0] = b[1] = 0;
		} else {
			a[0] = 0, a[1] = 1;
			b[0] = 0, b[1] = val % mod;
		}
	}
	Info(Info l, Info r) {
		a[0] = l.a[0] * r.a[0] + l.a[1] * r.a[1];
		a[1] = l.a[1] * r.a[0] + l.a[0] * r.a[1] + l.a[1] * r.a[1];
		b[0] = l.a[0] * r.b[0] + l.a[1] * r.b[1] + l.b[0];
		b[1] = l.a[1] * r.b[0] + l.a[0] * r.b[1] + l.a[1] * r.b[1] + l.b[1];
	}
	void apply(LazyContext lazy, int size) {}
	void rotate() {}
	bool operator < (const Info &o) const { return val < o.val; }
	// atributes
	modBase a[2];
	modBase b[2];
	int freq = 0;
	int val;
};

template<class i_t, class lazy_cont>
struct SplayTree {
	struct Node {
		Node *p = NULL, *left = NULL, *right = NULL;
		int size = 1;
		bool flip = false;
		i_t base, info;
		lazy_cont lazy;

		Node(i_t v) : base(v), info(v) {}
		~Node() {
			if(left) delete left;
			if(right) delete right;
		}

		void applyLazy(lazy_cont l) {
			info.apply(l, size);
			base.apply(l, 1);
			lazy += l;
		}

		void fix() {
			push(), info = base;
			size = 1;
			if(left) info = i_t(left->info, info), size += left->size, left->p = this;
			if(right) info = i_t(info, right->info), size += right->size, right->p = this;
		}

		Node* splay() {
			pull();
			while(p) {
				Node *y = p, *z = p->p;
				bool t1 = (y->left != this);
				bool t2 = z && (z->left != y) == t1;
				if(t2) y->rotate(t1);
				rotate(t1);
				if(z && !t2) rotate(!t1);
			}
			fix();
			return this;
		}
		
		void push() {
			if(flip) {
				std::swap(left, right);
				if(left) left->flip = !left->flip, left->info.rotate();
				if(right) right->flip = !right->flip, right->info.rotate();
				flip = false;
			}
			if(left) left->applyLazy(lazy);
			if(right) right->applyLazy(lazy);
			lazy.reset();
		}

		void pull() {
			if(p) {
				p->pull();
			}
			push();
		}

		void rotate(bool leftRotate) {
			Node* y = p, *z = p->p, *&w = leftRotate ? left : right;
			if(z) (z->right == y ? z->right : z->left) = this;
			if(w) w->p = y;
			(leftRotate ? y->right : y->left) = w;
			w = y; p = z;
			y->p = this;
			y->fix();
			//fix();
		}
	};
	Node* root;
	SplayTree(Node* r = NULL) : root(r) {}
	Node* lower_bound(i_t val) { return search(val, [](const i_t &a, const i_t &b){ return !(b < a); }); }
	Node* upper_bound(i_t val) { return search(val, [](const i_t &a, const i_t &b){ return a < b; }); }

	Node* splayFirst() { return expose(1); }
	Node* splayLast() { return expose(1e9); }
	Node* expose(int k) {
		Node* cur = root;
		if(!cur) return NULL;
		k = std::min(k, cur->size);
		k = std::max(k, 1);
		while(cur) {
			cur->push();
			if(cur->left) {
				if(cur->left->size >= k) {
					cur = cur->left;
					continue;
				} else {
					k -= cur->left->size;
				}
			}
			if(k == 1) {
				break;
			}
			k--;
			cur = cur->right;
		}
		assert(cur);
		return root = cur->splay();
	}

	template<class F>
	Node* search(i_t val, F f) {
		Node* ans = NULL, *cur = root, *last = NULL;
		while(cur) {
			cur->push();
			last = cur;
			if(f(val, cur->base)) {
				ans = cur;
				cur = cur->left;
			} else {
				cur = cur->right;
			}
		}
		root = last->splay();
		if(ans) root = ans->splay();
		return ans;
	}
	void insert(i_t t) { insert(new Node(t)); }
	void insert(Node* node) {
		if(!root) {
			root = node;
			return;
		}
		Node* tree = root;
		while(1) {
			tree->push();
			Node* &w = node->base < tree->base ? tree->left : tree->right;
			if(w) {
				tree = w;
			} else {
				w = node;
				tree->fix();
				break;
			}
		}
		root = node->splay();
	}

	void erase(Node* node) {
		node->pull();
		if(node == root) {
			if(node->left) node->left->p = NULL;
			if(node->right) node->right->p = NULL;
			*this = SplayTree(node->left) + SplayTree(node->right);
		} else {
			assert(node->p);
			Node* &w = node->p->left == node ? node->p->left : node->p->right;
			if(!node->left || !node->right) {
				w = node->left ? node->left : node->right;
			} else {
				node->left->p = node->right->p = NULL;
				w = (SplayTree(node->left) + SplayTree(node->right)).root;
			}
			node->p->fix();
			root = node->p->splay();
		}
	}

	SplayTree operator + (SplayTree o) {
		if(!root) return o;
		if(!o.root) return *this;
		splayLast();
		assert(!root->right && !o.root->p);
		root->right = o.root;
		root->fix();
		return SplayTree(root);
	}
};

typedef SplayTree<Info, LazyContext> Splay;

inline int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> mod;
	std::map<int, Splay::Node*> st;
	Splay tree;
	struct Query {
		int l, r;
		int id;
		void read() {
			std::cin >> l >> r;
			l--;
		}
		bool operator < (const Query &o) const { return hilbertOrder(l, r, 21, 0) < hilbertOrder(o.l, o.r, 21, 0); }
	};
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(!st.count(a[i])) {
			tree.insert(Info(a[i]));
			st[a[i]] = tree.root;
			assert(tree.root->base.val == a[i]);
		}
	}
	std::cin >> m;
	std::vector<Query> qries(m);
	for(int i = 0; i < m; i++) {
		qries[i].read();
		qries[i].id = i;
	}
	std::sort(qries.begin(), qries.end());
	std::vector<int> ans(m, -1);
	int l = 0, r = 0;
	auto add = [&](int x, int f) {
		//std::cout << "doing operation for " << x << ", " << f << "\n";
		auto node = st[x];
		node->base.freq += f;
		if(node->base.freq == f || node->base.freq == 0) {
			tree.root = node->splay();
			assert(node && node->base.val == x && tree.root == node);
			node->base.recalc();
			node->fix();
		}
	};
	for(auto qry : qries) {
		while(l > qry.l) add(a[--l], 1);
		while(r < qry.r) add(a[r++], 1);
		while(r > qry.r) add(a[--r], -1);
		while(l < qry.l) add(a[l++], -1);
		ans[qry.id] = tree.root->info.b[1].val;
	}
	for(int i = 0; i < m; i++) {
		std::cout << ans[i] << '\n';
	}
}