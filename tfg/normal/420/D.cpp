#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef int Key;
struct Treap {
	Treap(){}
	Treap(int k) {
		key = 1;
		size = 1;
		l = r = NULL;
		val = k;
		priority = rng();
	}

	int priority;
	Treap *l, *r;
	Key key;
	int val;
	int size;
};

typedef Treap * PTreap;

bool leftSide(PTreap l, PTreap r) {
	return l->priority > r->priority;
}

void fix(PTreap t) {
	if(t == NULL) {
		return;
	}
	t->size = 1;
	t->key = 1;
	if(t->l) {
		t->size += t->l->size;
		t->key += t->l->size;
	}
	if(t->r) {
		t->size += t->r->size;
	}
}

void split(PTreap t, Key key, PTreap &l, PTreap &r) {
	if(t == NULL) {
		l = r = NULL;
	} else if(t->key <= key) {
		l = t;
		split(t->r, key - t->key, l->r, r);
		fix(l);
	} else {
		r = t;
		split(t->l, key, l, r->l);
		fix(r);
	}
}

void merge(PTreap &t, PTreap l, PTreap r) {
	if(!l || !r) {
		t = l ? l : r;
		return;
	}
	if(leftSide(l, r)) {
		t = l;
		merge(t->r, l->r, r);
	} else {
		t = r;
		merge(t->l, l, r->l);
	}
	fix(t);
}

Treap buffer[1001000];

std::vector<int> ans;
void dfs(PTreap t) {
	if(t == NULL) return;
	dfs(t->l);
	ans.push_back(t->val);
	dfs(t->r);
}

void print(PTreap t) {
	if(t == NULL) return;
	print(t->l);
	std::cout << t->val << ' ';
	print(t->r);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> last(n, -1);
	PTreap tree = NULL;
	int known = 0;
	std::vector<bool> got(n, false);
	std::vector<std::pair<int, int>> qries;
	for(int i = 0; i < m; i++) {
		int val, pos;
		std::cin >> val >> pos;
		val--;
		qries.emplace_back(val, pos);
		if(pos <= known) {
			//std::cout << "first case!\n";
			// check if it's in known shit
			/*if(!got[val]) {
				std::cout << "-1\n";
				return 0;
			}*/
			// split
			PTreap l, mid, r;
			split(tree, pos-1, l, mid);
			split(mid, 1, mid, r);
			//print(l);std::cout << std::endl;
			//print(mid);std::cout << std::endl;
			//print(r);std::cout << std::endl;
			if(mid == NULL || mid->val != val) {
				std::cout << "-1\n";
				return 0;
			}
			merge(tree, mid, l);
			merge(tree, tree, r);
		} else {
			//std::cout << "second case!\n";
			// check if value is known
			if(got[val]) {
				std::cout << "-1\n";
				return 0;
			}
			PTreap cur = &buffer[known++];
			got[val] = true;
			*cur = Treap(val);
			merge(tree, cur, tree);
		}
	}
	for(int i = 0; i < n; i++) {
		if(!got[i]) {
			PTreap cur = &buffer[known++];
			*cur = Treap(i);
			merge(tree, tree, cur);
		}
	}
	for(int i = m-1; i >= 0; i--) {
		int to = qries[i].second;
		PTreap l, mid, r;
		split(tree, 1, l, mid);
		split(mid, to-1, mid, r);

		//print(l);std::cout << std::endl;
		//print(mid);std::cout << std::endl;
		//print(r);std::cout << std::endl;

		merge(tree, mid, l);
		merge(tree, tree, r);
	}
	dfs(tree);
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}