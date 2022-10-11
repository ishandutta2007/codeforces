#include <vector>
#include <string>

int n, m, q;

struct Node {
	Node() {
		// empty constructor
		for(int i = 0; i < m; i++) {
			to[i] = i;
			shift[i] = 0;
		}
		size = 0;
	}
	
	Node(char *s) {
		// init
		for(int i = 0; i < m; i++) {
			if(s[i] == '^') {
				to[i] = i;
			} else if(s[i] == '<') {
				if(i == 0) {
					to[i] = -3;
				} else {
					to[i] = to[i - 1];
				}
			} else {
				int j = i;
				while(j + 1 < m && s[j + 1] == '>') j++;
				if(j == m - 1) {
					to[j] = -1;
				} else if(s[j + 1] == '<') {
					to[j] = -2;
				} else {
					to[j] = j + 1;
				}
				while(i < j) {
					to[i++] = to[j];
				}
			}
		}
		for(int i = 0; i < m; i++) {
			shift[i] = to[i] >= 0 ? 1 : 0;
		}
		size = 1;
	}
	
	Node(Node l, Node r) {
		// merge
		std::swap(l, r);
		for(int i = 0; i < m; i++) {
			if(l.to[i] >= 0) {
				shift[i] = l.size + r.shift[l.to[i]];
				to[i] = r.to[l.to[i]];
			} else {
				shift[i] = l.shift[i];
				to[i] = l.to[i];
			}
		}
		size = l.size + r.size;
	}

	// atributes
	int to[10], shift[10], size;
};

template <class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
		}
	}
	
	i_t qry(int l, int r) {
		i_t lp, rp;
		for(l += n, r += n; l < r; l /= 2, r /= 2) {
			if(l & 1) lp = i_t(lp, tree[l++]);
			if(r & 1) rp = i_t(tree[--r], rp);
		}
		return i_t(lp, rp);
	}
	
	void upd(int pos, e_t v) {
		pos += n;
		tree[pos] = i_t(v);
		build(pos);
	}
private:
	int n;
	std::vector<i_t> tree;

	void build(int pos) {
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
};

#include <iostream>
#include <cstdio>

char buffer[100100][11];

int main() {
	std::cin >> n >> m >> q;
	std::vector<char*> base(n);
	for(int i = 0; i < n; i++) {
		scanf(" %s", buffer[i]);
		base[i] = buffer[i];
	}
	SegmentTree<Node, char*> tree;
	tree.init(base);
	while(q--) {
		char c;
		int x, y;
		scanf(" %c %d %d", &c, &x, &y);
		x--;y--;
		if(c == 'A') {
			Node cur = tree.qry(0, x + 1);
			int ans[2];
			if(cur.to[y] == -2) {
				ans[0] = ans[1] = -1;
			} else if(cur.to[y] == -1) {
				ans[0] = x + 1 - cur.shift[y];
				ans[1] = m + 1;
			} else if(cur.to[y] == -3) {
				ans[0] = x + 1 - cur.shift[y];
				ans[1] = 0;
			} else {
				ans[0] = 0;
				ans[1] = cur.to[y] + 1;
			}
			printf("%d %d\n", ans[0], ans[1]);
		} else {
			char wut;
			scanf(" %c", &wut);
			base[x][y] = wut;
			tree.upd(x, base[x]);
		}
	}
}