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
	VI cnt;
	int ab, bc;
	int ans;

	Node(){
		ab = bc = ans = 0;
		cnt = VI(3);
	}
};

Node merge(Node a, Node b){
	Node ret;
	ret.ans = a.ans + b.ans;

	int fs = std::min(a.cnt[0], b.bc);
	ret.ans += fs;
	a.cnt[0] -= fs;
	b.bc -= fs;

	int sc = std::min(a.ab, b.cnt[2]);
	ret.ans += sc;
	b.cnt[2] -= sc;
	a.ab -= sc;

	int xd = std::min(a.ab, b.bc);
	ret.ans += xd;
	a.ab -= xd;
	b.bc -= xd;

	int ab = std::min(a.cnt[0], b.cnt[1]);
	a.cnt[0] -= ab;
	b.cnt[1] -= ab;
	ret.ab = a.ab + b.ab + ab;

	int bc = std::min(a.cnt[1], b.cnt[2]);
	a.cnt[1] -= bc;
	b.cnt[2] -= bc;
	ret.bc = a.bc + b.bc + bc;

	FOR(i, 3) ret.cnt[i] = a.cnt[i] + b.cnt[i];

	ret.cnt[1] += xd;
	// a.cnt[1] += xd;
	// b.cnt[1] += xd;

	return ret;
}

struct Tree{
	int BOTTOM;
	std::vector<Node> t;
	void build(std::string s){
		BOTTOM = 1;
		while(BOTTOM < SZ(s)){
			BOTTOM *= 2;
		}
		t.resize(2*BOTTOM);
		FOR(i, SZ(s)){
			t[BOTTOM+i].cnt[s[i]-'a']++;
		}
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = merge(t[i<<1], t[(i<<1)+1]);
		}
	}

	int ans(){
		return t[1].ans;
	}

	void update(int v, int co){
		v += BOTTOM;
		t[v] = Node();
		t[v].cnt[co]++;

		while(v > 1){
			v>>=1;
			t[v] = merge(t[v<<1], t[(v<<1)+1]);
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::string s;
	std::cin >> s;
	Tree tree;
	tree.build(s);

	FOR(_, q){
		int x;
		char a;
		std::cin >> x >> a;
		x--;

		tree.update(x, a-'a');
		std::cout << tree.ans() << "\n";
	}

	return 0;
}