#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 4 * 3 * 5;

struct Node {
	Node(int v = 2) {
		// init
		for(int i = 0; i < ms; i++) {
			ans[i] = (i % v == 0 ? 2 : 1);
		}
	}
	
	Node(Node l, Node r) {
		// merge
		for(int i = 0; i < ms; i++) {
			ans[i] = l.ans[i] + r.ans[(l.ans[i] + i) % ms];
		}
		this->l = l.l;
		this->r = r.r;
	}

	void print() {
		if(l >= r) return;
		std::cout << "[" << l << ", " << r << "): ";
		for(int i = 0; i < 10; i++) {
			std::cout << ans[i] << (i + 1 == 10 ? '\n' : ' ');
		}
	}

	// atributes
	int ans[ms];
	int l, r;
};

template <class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
			tree[i + n].l = i;
			tree[i + n].r = i + 1;
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
			//tree[i].print();
		}
	}
	
	int qry(int l, int r) {
		int pos[30];
		int size = 0;
		int ans = 0;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) {
				//std::cout << "skipping " << tree[l].ans[ans % ms] << std::endl;
				//tree[l].print();
				ans += tree[l++].ans[ans % ms];
			}
			if(r & 1) {
				pos[size++] = --r;
			}
		}
		for(int i = 0; i < size; i++) {
			ans += tree[pos[size - i - 1]].ans[ans % ms];
		}
		return ans;
	}
	
	void upd(int pos, e_t v) {
		pos += n;
		tree[pos] = i_t(v);
		tree[pos].l = pos - n;
		tree[pos].r = pos - n + 1;
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
			//tree[pos].print();
		}
	}
	
private:
	int n;
	std::vector<i_t> tree;
};


int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> base(n);
	for(int i = 0; i < n; i++) {
		//std::cin >> base[i];
		scanf("%d", &base[i]);
	}
	SegmentTree<Node, int> tree;
	tree.init(base);
	int m;
	std::cin >> m;
	while(m--) {
		char typ;
		int x, y;
		//std::cin >> typ >> x >> y;
		scanf(" %c %d %d", &typ, &x, &y);
		if(typ == 'A') {
			//std::cout << y - x << '\n';
			/*int cur = 0;
			for(int i = x - 1; i < y - 1; i++) {
				std::cout << base[i] << (i + 1 == y - 1 ? '\n' : ' ');
				cur += cur % base[i] == 0 ? 2 : 1;
			}
			std::cout << cur << std::endl;*/
			printf("%d\n", tree.qry(x - 1, y - 1));
		} else {
			tree.upd(x - 1, y);
			base[x - 1] = y;
		}
	}
}