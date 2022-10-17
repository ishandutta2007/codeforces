#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, m;
std::string str;

struct Tree{
	int BOTTOM;
	struct Node{
		int fr, sv, a1, a2;
	};
	std::vector<Node> t;
	std::vector<bool> swap;
	void get(Node &v, Node &a, Node &b){
		v.fr = a.fr+b.fr;
		v.sv = a.sv+b.sv;
		v.a1 = std::max(a.fr+b.a1, a.a1+b.sv);
		v.a2 = std::max(a.sv+b.a2, a.a2+b.fr);
	}
	Tree(){
		BOTTOM = 1;
		while(BOTTOM < n) BOTTOM <<= 1;
		t.resize(BOTTOM*2);
		swap.resize(BOTTOM*2);
		FOR(i, n){
			if(str[i] == '4') t[BOTTOM+i].fr++;
			else t[BOTTOM+i].sv++;
			t[BOTTOM+i].a1 = t[BOTTOM+i].a2 = 1;
		}
		for(int i = BOTTOM-1; i >= 1; --i){
			get(t[i], t[i<<1], t[(i<<1)+1]);
		}
	}
	void upd(int v){
		if(swap[v]){
			if(v < BOTTOM) swap[v<<1] = !swap[v<<1], swap[(v<<1)+1] = !swap[(v<<1)+1];
			std::swap(t[v].fr, t[v].sv);
			std::swap(t[v].a1, t[v].a2);
			swap[v] = false;
		}
	}
	Node query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return Node();
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		Node lef = query(a, std::min(b, mid), v<<1, lo, mid);
		Node rig = query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
		Node ret = Node();
		get(ret, lef, rig);
		return ret;
	}
	void update(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return;
		if(a == lo && b == hi){
			swap[v] = true;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		update(a, std::min(b, mid), v<<1, lo, mid);
		update(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
		get(t[v], t[v<<1], t[(v<<1)+1]);
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> str;
	Tree tree = Tree();
	FOR(_, m){
		std::string query;
		std::cin >> query;
		if(query[0] == 'c'){
			std::cout << tree.query(0, n-1).a1 << "\n";
		}else{
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			tree.update(a, b);
		}
	}
	return 0;
}