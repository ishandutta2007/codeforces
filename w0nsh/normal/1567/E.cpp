#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct Node{
	ll ans;
	int left, right;
	int size;
	Node() : left(0), right(0), ans(0ll), size(0) {}
};

Node merge(Node a, Node b){
	Node ret;
	ret.ans = a.ans + b.ans + 1ll * a.right * b.left;
	ret.left = a.left;
	if(a.left == a.size) ret.left = a.size + b.left;
	ret.right = b.right;
	if(b.right == b.size) ret.right = b.size + a.right;
	ret.size = a.size + b.size;
	return ret;
}

struct Tree{

	int BOTTOM;
	std::vector<Node> t;

	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t = std::vector<Node>(BOTTOM*2);
		for(int i = BOTTOM; i < BOTTOM * 2; ++i){
			t[i].size = 1;
		}
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = merge(t[i<<1], t[(i<<1)+1]);
		}
	}

	void set(int v, int val) {
		v += BOTTOM;
		t[v] = Node();
		t[v].size = 1;
		if(val){
			t[v].left = t[v].right = t[v].ans = 1;
		}

		while(v > 1){
			v >>= 1;
			t[v] = merge(t[v<<1], t[(v<<1)+1]);
		}
	}

	Node query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return Node();
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		Node fs = query(a, std::min(b, mid), v<<1, lo, mid);
		Node sc = query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
		return merge(fs, sc);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	Tree tree;
	tree.build(n-1);

	FOR(i, n-1) tree.set(i, A[i] <= A[i+1]);

	FOR(_, q){
		int t;
		std::cin >> t;
		if(t == 1){
			int x, y;
			std::cin >> x >> y;
			x--;
			A[x] = y;
			if(x > 0) tree.set(x-1, A[x-1] <= A[x]);
			if(x < n-1) tree.set(x, A[x] <= A[x+1]);
		}else{
			int l, r;
			std::cin >> l >> r;
			l--;r--;
			std::cout << tree.query(l, r-1).ans + (r - l + 1) << "\n";
		}
	}

	return 0;
}