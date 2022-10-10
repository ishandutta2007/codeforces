#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;

int pre[10][10];

struct Node {
	Node() {
		// empty constructor
		pref = -1;
	}
	
	Node(char c) {
		// init
		pref = suf = c - '0';
		dp[0][0] = 0;
		dp[1][1] = c - '0' + 1;
		dp[0][1] = dp[1][0] = 1;
	}
	
	Node(Node l, Node r) {
		// merge
		if(l.pref == -1) {
			*this = r;
		} else if(r.pref == -1) {
			*this = l;
		} else {
			pref = l.pref, suf = r.suf;
			for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) {
				dp[i][j] = (int)(((long long) l.dp[i][1] * r.dp[1][j] + (long long) l.dp[i][0] * r.dp[0][j] % MOD * pre[l.suf][r.pref]) % MOD);
			}
		}
	}

	// atributes
	int dp[2][2];
	int pref, suf;
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
		for(pos /= 2; pos > 0; pos /= 2) {
			tree[pos] = i_t(tree[pos + pos], tree[pos + pos + 1]);
		}
	}
	
private:
	int n;
	std::vector<i_t> tree;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 0; i < 10; i++) for(int j = 0; j < 10; j++) {
		if(i+j>=10) {
			pre[(i+j)/10][(i+j)%10]++;
		}
	}
	int n, m;
	std::cin >> n >> m;
	std::vector<char> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	SegmentTree<Node, char> tree;
	tree.init(a);
	while(m--) {
		int x;
		char ch;
		std::cin >> x >> ch;
		x--;
		tree.upd(x, ch);
		std::cout << tree.qry(0, n).dp[1][1] << '\n';
	}
}