#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>

struct node{
	node(){valid = false;}

	node(int a) {
		//init
		valid = true;
		lazy = -1;
		first = last = a;
		memset(table, 0, sizeof table);
	}

	node(node a, node b) {
		if(!a.valid) {
			*this = b;
		} else if(!b.valid) {
			*this = a;
		} else {
			valid = true;
			lazy = -1;
			//merge
			for(int i = 0; i < 10; i++) {
				for(int j = 0; j < 10; j++) {
					table[i][j] = a.table[i][j] + b.table[i][j];
				}
			}
			table[a.last][b.first]++;
			first = a.first;
			last = b.last;
		}
	}

	void add_lazy(int &a) {
		//adicionar lazy com contexto de lazy
		memset(table, 0, sizeof table);
		lazy = first = last = a;
	}

	void add_lazy(node &a) {
		//adicionar lazy do pai
		add_lazy(a.lazy);
	}

	void reset_lazy() {
		//zerar
		lazy = -1;
	}
	//atributos
	bool valid;
	int table[10][10];
	int first, last;

	//lazy
	int lazy = -1;
};

template <class i_t, class s_t, class lazy_cont = int>
class Segment_Tree {
public:
	Segment_Tree(std::vector<s_t> _a) {
		a = _a;
		n = a.size();
		st.resize(4*n);
		build(0, n - 1, 0);
	}

	i_t qry(int i, int j){return qry(0, n-1, i, j, 0);}
	void upd(int pos, s_t val){upd(0, n-1, pos, 0, val);}
	void upd(int i, int j, lazy_cont val){upd(0, n-1, i, j, 0, val);}
private:
	int left(int p){return p + p + 1;}
	int right(int p){return p + p + 2;}
	std::vector<s_t> a;
	std::vector<i_t> st;
	int n;

	void build(int l, int r, int ind) {
		if(l==r) {
			st[ind] = i_t(a[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(l, mid, left(ind));
		build(mid + 1, r, right(ind));
		st[ind] = i_t(st[left(ind)], st[right(ind)]);
	}

	void push(int l, int r, int ind) {
		if(st[ind].lazy == -1) {
			return;
		}
		if(l!=r) {
			st[left(ind)].add_lazy(st[ind]);
			st[right(ind)].add_lazy(st[ind]);
		}
		st[ind].reset_lazy();
	}

	void upd(int l, int r, int pos, int ind, s_t &val) {
		push(l, r, ind);
		
		if(l>pos || r<pos)
			return;

		if(l==r) {
			a[pos] = val;
			st[ind] = i_t(a[pos]);
			return;
		}

		int mid = (l + r) / 2;
		upd(l, mid, pos, left(ind), val);
		upd(mid + 1, r, pos, right(ind), val);
		st[ind] = i_t(st[left(ind)], st[right(ind)]);
	}

	void upd(int l, int r, int i, int j, int ind, lazy_cont &val) {
		push(l, r, ind);
		
		if(r<i || l>j) {
			return;
		} else if(l>=i && r<=j) {
			st[ind].add_lazy(val);
		} else {
			int mid = (l + r) / 2;
			upd(l, mid, i, j, left(ind), val);
			upd(mid + 1, r, i, j, right(ind), val);
			st[ind] = i_t(st[left(ind)], st[right(ind)]);
		}
	}

	i_t qry(int l, int r, int i, int j, int ind) {
		int mid = (l + r) / 2;
		push(l, r, ind);

		if(r<i || l>j) {
			return i_t();
		} else if(l>=i && r<=j) {
			return st[ind];
		} else {
			return i_t(
			qry(l, mid, i, j, left(ind)),
			qry(mid + 1, r, i, j, right(ind))
				);
		}
	}
};

char str[200200];

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	scanf(" %s", str);
	std::vector<int> wtf;
	for(int i = 0; i < n; i++) {
		wtf.push_back(str[i] - 'a');
	}
	Segment_Tree<node, int, int> tree(wtf);
	while(m--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			int l, r;
			char c;
			std::cin >> l >> r >> c;
			l--;r--;
			tree.upd(l, r, c - 'a');
		} else {
			scanf(" %s", str);
			int ans = n;
			auto all = tree.qry(0, n - 1);
			for(int i = 0; i < k; i++) {
				for(int j = i + 1; j < k; j++) {
					//std::cout << char(str[i]) << ", " << char(str[j]) << " = " << all.table[i][j] << '\n';
					ans -= all.table[str[i] - 'a'][str[j] - 'a'];
				}
			}
			std::cout << ans << '\n';
		}
	}
}