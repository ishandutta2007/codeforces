#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 1000000007;

PII operator +(PII a, PII b){
	if(a.X == b.X && a.X != 0) return MP(a.X, (a.Y+b.Y)%MOD);
	return std::max(a, b);
}
PII operator *(PII a, PII b){
	return MP(a.X+b.X+1, 1ll*a.Y*b.Y%MOD);
}
PII operator ++(PII a){
	return MP(a.X+1, a.Y);
}

struct Node{
	Node *l, *r;
	PII val;
	Node() : l(nullptr), r(nullptr), val(MP(0, 1)) {}
	Node(PII _val) : l(nullptr), r(nullptr), val(_val) {}
};

struct Tree{
	int BOTTOM;

	Node* build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		return new Node();
	}

	Node* set(int a, PII val, Node *node, int lo=0, int hi=-2){
		if(hi==-2) hi=BOTTOM-1;

		if(node) node = new Node(*node);
		else node = new Node();

		if(lo == hi){
			node->val = node->val+val;
			return node;
		}
		
		int mid = (lo+hi)/2;
		if(a <= mid) node->l = set(a, val, node->l, lo, mid);
		else node->r = set(a, val, node->r, mid+1, hi);

		node->val = (node->l ? node->l->val : MP(0, 1)) + (node->r ? node->r->val : MP(0, 1));

		return node;
	}

	PII query(int a, int b, Node *node, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b || !node) return MP(0, 1);

		if(a == lo && b == hi) return node->val;

		int mid = (lo+hi)/2;
		return query(a, std::min(b, mid), node->l, lo, mid)
			+ query(std::max(a, mid+1), b, node->r, mid+1, hi);
	}
};

struct Wrr{
	int BOTTOM;
	std::vector<PII> t;

	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t = std::vector<PII>(BOTTOM*2, MP(0, 1));
	}

	void set(int a, PII val){
		a += BOTTOM;
		t[a] = t[a]+val;
		while(a > 1){
			a>>=1;
			t[a] = t[a<<1]+t[(a<<1)+1];
		}
	}

	PII query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a>b) return MP(0, 1);
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return query(a, std::min(b, mid), v<<1, lo, mid)
			+ query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	VI vals = A;
	std::vector<PII> que(m);
	FOR(i, m) std::cin >> que[i].X >> que[i].Y, vals.push_back(que[i].Y), que[i].X--;

	std::sort(vals.begin(), vals.end());
	vals.resize(std::unique(vals.begin(), vals.end())-vals.begin());
	FOR(i, n) A[i] = std::lower_bound(vals.begin(), vals.end(), A[i])-vals.begin();
	FOR(i, m) que[i].Y = std::lower_bound(vals.begin(), vals.end(), que[i].Y)-vals.begin();

	auto get_vec = [&](Tree &tree, VI vec, bool xd){
		std::vector<Node*> roots;
		roots.push_back(tree.build(n+m));

		FOR(i, SZ(vec))
			roots.push_back(tree.set(vec[i], xd ? ++tree.query(vec[i]+1, n+m-1, roots.back()) : ++tree.query(0, vec[i]-1, roots.back()), roots.back()));

		return roots;
	};

	Tree left;
	auto rl = get_vec(left, A, false);
//	std::reverse(A.begin(), A.end());
//	Tree right;
//	auto rr = get_vec(right, A, true);
//	std::reverse(A.begin(), A.end());
//	std::reverse(rr.begin(), rr.end());

	PII all = left.query(0, n+m-1, rl.back());

	std::vector<std::vector<PII> > evs(n);
	int ind = 0;
	TRAV(q, que) evs[q.X].push_back(MP(q.Y, ind++));
	VI ans(m);

	Wrr tree;
	tree.build(n+m);
	for(int i = n-1; i >= 0; --i){
		TRAV(q, evs[i]){
			auto &an = ans[q.Y];

			an = (left.query(0, q.X-1, rl[i])*tree.query(q.X+1, n+m-1)).X;

			PII a = left.query(0, A[i]-1, rl[i]);
			PII b = tree.query(A[i]+1, n+m-1);

			if(all == a*b) an = std::max(an, all.X-1);
			else an = std::max(an, all.X);
		}

		tree.set(A[i], ++tree.query(A[i]+1, n+m-1));
	}

	FOR(i, m) std::cout << ans[i] << "\n";

	return 0;
}