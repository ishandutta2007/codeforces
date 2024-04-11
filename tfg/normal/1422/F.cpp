#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

const int MOD = 1e9 + 7;
const int ms = 100200;

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

struct Node{
	modBase<> v = 1;
	Node *l = this, *r = this;
};

int CNT = 1;
Node buffer[ms * 13 * 20];
 
Node* update(Node *root, int l, int r, int idx, modBase<> val){
	Node *node = &buffer[CNT++];
	*node = *root;
	int mid = (l + r) / 2;
	node->v *= val;
	if(l+1 != r){
		if(idx < mid) node->l = update(root->l, l, mid, idx, val);
		else node->r = update(root->r, mid, r, idx, val);
	}
	return node;
}
 
modBase<> query(Node *node, int tl, int tr, int l, int r){
	if(l <= tl && tr <= r) return node->v;
	if(tr <= l || tl >= r) return 1;
	int mid = (tl+tr) / 2;
	return query(node->l, tl, mid, l, r) * query(node->r, mid, tr, l, r);
}

const int mv = 200200;
std::vector<std::pair<int, int>> fact[mv], st[mv];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 2; i < mv; i++) {
		if(!fact[i].empty()) continue;
		for(int j = i; j < mv; j += i) {
			int e = 1;
			int x = j;
			while(x % i == 0) {
				x /= i;
				e *= i;
			}
			fact[j].emplace_back(i, e);
		}
	}
	for(int i = 1; i < mv; i++) {
		assert((int) fact[i].size() <= 6);
	}
	std::vector<Node*> roots(1, &buffer[0]);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		auto cur = roots.back();
		for(auto p : fact[x]) {
			int last = 1;
			while(!st[p.first].empty() && st[p.first].back().second <= p.second) {
				cur = update(cur, 0, n, st[p.first].back().first, modBase<>(1) / (st[p.first].back().second / last));
				last = st[p.first].back().second;
				st[p.first].pop_back();
			}
			if(!st[p.first].empty() && p.second / last > 1) {
				cur = update(cur, 0, n, st[p.first].back().first, modBase<>(1) / (p.second / last));
			}
			st[p.first].emplace_back(i, p.second);
		}
		roots.push_back(update(cur, 0, n, i, modBase<>(x)));
	}
	assert(CNT <= ms * 13 * 20);
	int q;
	std::cin >> q;
	int last = 0;
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		l = (last + l) % n;
		r = (last + r) % n;
		if(l > r) std::swap(l, r);
		r++;
		last = query(roots[r], 0, n, l, r).val;
		std::cout << last << '\n';
	}
}