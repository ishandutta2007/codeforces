#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef int Key;
struct Treap {
	Treap(){}
	Treap(int k) {
		key = 1;
		size = 1;
		l = r = NULL;
		val = k;
	}

	Treap *l, *r, *par;
	Key key;
	int val;
	int size;
};

typedef Treap * PTreap;

bool leftSide(PTreap l, PTreap r) {
	return (int) (rng() % (l->size + r->size)) < l->size;
}

void fix(PTreap t) {
	if(t == NULL) {
		return;
	}
	t->size = 1;
	t->key = 1;
	t->par = NULL;
	if(t->l) {
		t->size += t->l->size;
		t->key += t->l->size;
		t->l->par = t;
	}
	if(t->r) {
		t->size += t->r->size;
		t->r->par = t;
	}
}

void split(PTreap t, Key key, PTreap &l, PTreap &r) {
	if(t == NULL) {
		l = r = NULL;
	} else if(t->key <= key) {
		l = t;
		split(t->r, key - t->key, t->r, r);
		fix(l);
	} else {
		r = t;
		split(t->l, key, l, t->l);
		fix(r);
	}
}

void merge(PTreap &t, PTreap l, PTreap r) {
	if(!l || !r) {
		t = l ? l : r;
		return;
	}
	if(leftSide(l, r)) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	fix(t);
}

Treap buffer[300100];

PTreap build(int l, int r, std::vector<int> &a) {
	if(l >= r) return NULL;
	int mid = (l + r) / 2;
	auto ans = &buffer[a[mid]];
	*ans = Treap(a[mid]);
	ans->l = build(l, mid, a);
	ans->r = build(mid + 1, r, a);
	fix(ans);
	return ans;
}

int wtf[300300], cnt = 1;

void dfs(PTreap t) {
	if(!t) return;
	dfs(t->l);
	wtf[t->val] = cnt++;
	dfs(t->r);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	std::vector<int> mn(n+1), mx(n+1);
	for(int i = 0; i < n; i++) {
		a[i] = i+1;
		mn[a[i]] = mx[a[i]] = i+1;
	}
	PTreap tree = build(0, n, a);
	while(m--) {
		int x;
		std::cin >> x;
		mn[x] = 1;
		PTreap cur = &buffer[x];
		int got = cur->key - 1;
		while(cur->par != NULL) {
			if(cur->par->r == cur) {
				got += cur->par->key;
			}
			cur = cur->par;
		}
		mx[x] = std::max(mx[x], got+1);
		PTreap l, mid, r;
		split(tree, got, l, mid);
		split(mid, 1, mid, r);
		merge(tree, mid, l);
		merge(tree, tree, r);
	}
	dfs(tree);
	for(int i = 1; i <= n; i++) {
		mx[i] = std::max(mx[i], wtf[i]);
		std::cout << mn[i] << ' ' << mx[i] << '\n';
	}
}