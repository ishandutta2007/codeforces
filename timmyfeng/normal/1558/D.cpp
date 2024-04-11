#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {
    modint() : n(0) {}
    template <class T> modint(T n) { n %= M; if (n < 0) n += M; this->n = n; }

    modint & operator+=(const modint &r) { n += r.n; if (n >= M) n -= M; return *this; }
    modint & operator-=(const modint &r) { n -= r.n; if (n < 0) n += M; return *this; }
    modint & operator*=(const modint &r) { n = (int) ((long long) n * r.n % M); return *this; }

    modint & operator--() { if (--n == -1) n = M - 1; return *this; }
    modint & operator++() { if (++n == M) n = 0; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }
    modint operator++(int) { modint t = *this; ++*this; return t; }

    modint operator-() const { return 0 - *this; }
    modint operator+() const { return *this; }

    modint pow(long long k = M - 2) const {
        modint f = 1, p = *this;
        while (k > 0) {
            if (k % 2 == 1) f *= p;
            p *= p, k /= 2;
        }
        return f;
    }

    int mod() const { return M; }

    friend modint operator+(modint l, const modint &r) { return l += r; }
    friend modint operator-(modint l, const modint &r) { return l -= r; }
    friend modint operator*(modint l, const modint &r) { return l *= r; }
    
    friend bool operator==(const modint &l, const modint &r) { return l.n == r.n; }
    friend bool operator!=(const modint &l, const modint &r) { return l.n != r.n; }

    friend ostream & operator<<(ostream &out, const modint &r) { return out << r.n; }

    int n;
};

using mint = modint<998244353>;

struct splay_node {
	splay_node *child[2], *parent;
	int value, lazy_tag;

	splay_node(int value) : value(value) {
		child[0] = child[1] = parent = nullptr;
		lazy_tag = 0;
	}
};

void add(splay_node *u, int x) {
	if (u) u->value += x, u->lazy_tag += x;
}

void push(splay_node *u) {
	if (u->lazy_tag) {
		for (auto c : u->child)
			add(c, u->lazy_tag);
		u->lazy_tag = 0;
	}
}

int dir(splay_node *u) {
	if (!u->parent) return -1;
	return u == u->parent->child[1];
}

void connect(splay_node *p, splay_node *c, int d) {
	if (p) p->child[d] = c;
	if (c) c->parent = p;
}

void rotate(splay_node *u) {
	splay_node *p = u->parent, *g = p->parent, *c = u->child[dir(u) ^ 1];
	int temp = dir(p);
	connect(u, p, dir(u) ^ 1);
	connect(p, c, dir(u));
	connect(g, u, temp);
}

void push_all(splay_node *u) {
	if (u->parent) push_all(u->parent);
	push(u);
}

splay_node * splay(splay_node *u) {
	push_all(u);
	while (u->parent) {
		if (dir(u) == dir(u->parent))
			rotate(u->parent);
		rotate(u);
	}
	return u;
}

splay_node * find(splay_node *u, int x) {
	if (!u) return nullptr;

	push(u);
	if (x == u->value)
		return splay(u);

	if (x < u->value) {
		splay_node *v = find(u->child[0], x);
		if (!v)
			return splay(u);
		return v;
	}

	return find(u->child[1], x);
}

splay_node * insert(splay_node *u, splay_node *v) {
	if (!u || !v) return u ? u : v;

	push(u);
	int d = (v->value > u->value);
	if (u->child[d])
		return insert(u->child[d], v);
	
	connect(u, v, d);
	return splay(v);
}

splay_node * erase(splay_node *u) {
	splay(u);
	for (auto c : u->child)
		connect(nullptr, c, -1);
	return insert(u->child[0], u->child[1]);
}

pair<splay_node*, splay_node*> split(splay_node *u) {
	if (!u) return {nullptr, nullptr};

	splay(u);
	splay_node *v = u->child[0];
	connect(nullptr, v, -1);
	u->child[0] = nullptr;
	return {v, u};
}

void print(splay_node *u) {
	if (!u) return;
	push(u);
	print(u->child[0]);
	cerr << u->value << " ";
	print(u->child[1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int N = 2e5;

	vector<mint> fact(2 * N + 1), inv(2 * N + 1);
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= 2 * N; ++i) {
		fact[i] = i * fact[i - 1];
		inv[i] = fact[i].pow();
	}

	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;

		int size = 0;
		splay_node *root = nullptr;
		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;

			splay_node *prev = find(root, y - 1);
			if (prev) {
				if (prev->value == y - 1) {
					root = erase(prev);
					size -= 1;
				} else root = prev;
			}

			splay_node *next = find(root, y);
			if (next) {
				tie(root, next) = split(next);
				add(next, 1);
				root = insert(next, root);
			}

			root = insert(root, new splay_node(y));
			size += 1;
		}

		cout << fact[2 * n - 1 - size] * inv[n - 1 - size] * inv[n] << "\n";
	}
}