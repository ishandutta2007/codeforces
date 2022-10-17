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

const int INF = 1000000666;


struct Tree{
	int BOTTOM;
	std::vector<int> t;
	std::vector<std::set<int> > vec;
	void build(int size){
		BOTTOM = 1;
		while(BOTTOM < size) BOTTOM *= 2;
		t.resize(BOTTOM*2, -1);
		vec = std::vector<std::set<int> >(size);
	}
	void add(int x, int y){
		x += BOTTOM;
		vec[x-BOTTOM].insert(y);
		t[x] = *(--vec[x-BOTTOM].end());
		while(x > 1){
			x >>= 1;
			t[x] = std::max(t[x<<1], t[(x<<1)+1]);
		}
	}
	void rem(int x, int y){
		x += BOTTOM;
		vec[x-BOTTOM].erase(y);
		if(SZ(vec[x-BOTTOM]) > 0) t[x] = *(--vec[x-BOTTOM].end());
		else t[x] = -1;
		while(x > 1){
			x >>= 1;
			t[x] = std::max(t[x<<1], t[(x<<1)+1]);
		}
	}
	PII best;
	PII query(int x, int y){
		best = MP(INF, INF);
		_query(x, BOTTOM-1, y, 1, 0, BOTTOM-1);
		return best;
	}
	void _query(int a, int b, int y, int v, int lo, int hi){
		if(a > b) return;
		if(t[v] < y) return;
		if(a == lo && b == hi){
			best = std::min(best, find(v, y));
			return;
		}
		int mid = (lo+hi)/2;
		_query(a, std::min(mid, b), y, v<<1, lo, mid);
		_query(std::max(a, mid+1), b, y, (v<<1)+1, mid+1, hi);
	}
	PII find(int v, int y){
		while(v < BOTTOM){
			if(t[v<<1] >= y) v = v<<1;
			else v = (v<<1)+1;
		}
		return MP(v-BOTTOM, *vec[v-BOTTOM].lower_bound(y));
	}
};

int n;
std::vector<PR<int, PII> > A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	std::set<int> xset;
	std::map<int, int> map;
	VI rev;
	FOR(i, n){
		std::string a;
		int x, y;
		std::cin >> a >> x >> y;
		if(a[0] == 'a'){
			A.push_back(MP(0, MP(x, y)));
			xset.insert(x);
		}else if(a[0] == 'r'){
			A.push_back(MP(1, MP(x, y)));
			xset.insert(x);
		}else{
			A.push_back(MP(2, MP(x+1, y+1)));
			xset.insert(x+1);
		}
	}
	int fre = 0;
	TRAV(i, xset) map[i] = fre++, rev.push_back(i);
	Tree tree;
	tree.build(SZ(rev));
	TRAV(q, A){
		PII p = q.Y;
		p.X = map[p.X];
		if(q.X == 0){
			tree.add(p.X, p.Y);
		}else if(q.X == 1){
			tree.rem(p.X, p.Y);
		}else{
			PII ans = tree.query(p.X, p.Y);
			if(ans.X == INF) std::cout << -1 << "\n";
			else std::cout << rev[ans.X] << " " << ans.Y << "\n";
		}
	}
	return 0;
}