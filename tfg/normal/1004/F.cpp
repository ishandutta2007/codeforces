#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

int x;

struct Node {
	Node() {
		//memset(freq, 0, sizeof freq);
		// empty constructor
		size[0] = size[1] = 0;
		ans = 0;
	}
	
	Node(int v) {
		memset(freq, 0, sizeof freq);
		// init
		size[0] = size[1] = 1;
		ans = (v >= x ? 1 : 0);
		vals[0][0] = vals[1][0] = v;
		freq[0][0] = freq[1][0] = 1;
	}
	
	Node(Node l, Node r) {
		memset(freq, 0, sizeof freq);
		// merge
		ans = l.ans + r.ans;

		// merge left
		for(int i = 0; i < l.size[0]; i++) {
			vals[0][i] = l.vals[0][i];
			freq[0][i] = l.freq[0][i];
		}
		size[0] = l.size[0];
		for(int i = 0; i < r.size[0]; i++) {
			if(size[0] == 0 || (vals[0][size[0] - 1] | r.vals[0][i]) != vals[0][size[0] - 1]) {
				vals[0][size[0]] = vals[0][size[0] - 1] | r.vals[0][i];
				size[0]++;
			}
			freq[0][size[0] - 1] += r.freq[0][i];
		}

		// merge right
		for(int i = 0; i < r.size[1]; i++) {
			vals[1][i] = r.vals[1][i];
			freq[1][i] = r.freq[1][i];
		}
		size[1] = r.size[1];
		for(int i = 0; i < l.size[1]; i++) {
			if(size[1] == 0 || (vals[1][size[1] - 1] | l.vals[1][i]) != vals[1][size[1] - 1]) {
				vals[1][size[1]] = vals[1][size[1] - 1] | l.vals[1][i];
				size[1]++;
			}
			freq[1][size[1] - 1] += l.freq[1][i];
		}

		// merge middle
		long long right = 0;
		for(int i = 0, j = r.size[0] - 1; i < l.size[1]; i++) {
			while(j >= 0 && (l.vals[1][i] | r.vals[0][j]) >= x) {
				right += r.freq[0][j--];
			}
			ans += right * l.freq[1][i];
		}
	}

	void print() {
		for(int k = 0; k < 2; k++) {
			std::cout << "type " << k << ", size is " << size[k] << ":";
			for(int i = 0; i < size[k]; i++) {
				std::cout << " (" << vals[k][i] << ", " << freq[k][i] << ")";
			}
			std::cout << std::endl;
		}
		std::cout << "ans is " << ans << std::endl;
	}

	// atributes
	int size[2], vals[2][21], freq[2][21];
	long long ans;
};

template <class i_t, class e_t>
class SegmentTree {
public:
	void init(std::vector<e_t> base) {
		n = base.size();
		tree.resize(2 * n);
		for(int i = 0; i < n; i++) {
			tree[i + n] = i_t(base[i]);
			//tree[i + n].print();
		}
		for(int i = n - 1; i > 0; i--) {
			tree[i] = i_t(tree[i + i], tree[i + i + 1]);
			//tree[i].print();
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
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
	
private:
	int n;
	std::vector<i_t> tree;
};

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m >> x;
	std::vector<int> base(n);
	for(int i = 0; i < n; i++) {
		//std::cin >> base[i];
		scanf("%d", &base[i]);
	}
	SegmentTree<Node, int> tree;
	tree.init(base);
	while(m--) {
		int t, x, y;
		//std::cin >> t >> x >> y;
		scanf("%d %d %d", &t, &x, &y);
		if(t == 1) {
			tree.upd(x - 1, y);
		} else {
			std::cout << tree.qry(x - 1, y).ans << std::endl;
		}
	}
}