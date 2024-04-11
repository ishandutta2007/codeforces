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

const int INF = 1000000006;

struct MinTree{
	int BOTTOM;
	std::vector<PII> t;
	VI u, A;
	void build(){
		BOTTOM = 1;
		while(BOTTOM < SZ(A)) BOTTOM *=2;
		t.resize(BOTTOM*2, MP(INF, INF));
		u.resize(BOTTOM*2);
		FOR(i, SZ(A)) t[i+BOTTOM] = MP(A[i], i);
		for(int i = BOTTOM-1; i >= 1; --i){
			t[i] = std::min(t[i<<1], t[(i<<1)+1]);
		}
	}
	void upd(int v){
		if(u[v] != 0){
			if(v < BOTTOM){
				u[v<<1] += u[v];
				u[(v<<1)+1] += u[v];
			}
			t[v].X += u[v];
			u[v] = 0;
		}
	}
	void add(int a, int b, int w, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return;
		if(a==lo&&b==hi){
			u[v] += w;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), w, v<<1, lo, mid);
		add(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		t[v] = std::min(t[v<<1], t[(v<<1)+1]);
	}
	PII query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return MP(INF, INF);
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return std::min(query(a, std::min(b, mid), v<<1, lo, mid),
			query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
};
struct SumTree{
	int BOTTOM;
	VI t;
	void build(int size){
		BOTTOM = 1;
		while(BOTTOM < size) BOTTOM *= 2;
		t.resize(BOTTOM*2);
	}
	void add(int v, int x){
		v += BOTTOM;
		while(v >= 1){
			t[v] += x;
			v >>= 1;
		}
	}
	int query(int a, int b){
		int ret = 0;
		a += BOTTOM;
		b += BOTTOM+1;
		while(a<b){
			if(a&1) ret += t[a++];
			if(b&1) ret += t[--b];
			a>>=1;b>>=1;
		}
		return ret;
	}
};


int n, m;
VI luck, A;
SumTree ans;
std::set<int> set;
std::vector<MinTree> trees;

void fix(MinTree &t){
	while(true){
		auto best = t.query(0, t.BOTTOM-1);
		if(best.X > 0) break;
		if(best.X == 0){
			ans.add(best.Y, 1);
			set.insert(best.Y);
		}
		t.add(best.Y, best.Y, INF);
	}
}

void fixset(int a, int b){
	auto it = set.lower_bound(a);
	while(it != set.end() && *it <= b){
		auto nxt = std::next(it, 1);
		ans.add(*it, -1);
		set.erase(it);
		it = nxt;
	}
}

void getlucky(){
	REP(sz, 1, 5){
		FOR(mask, 1<<sz){
			int num = 0;
			FOR(i, sz) num = num*10+((mask & (1<<i)) ? 4 : 7);
			luck.push_back(num);
		}
	}
}

void gettrees(){
	trees.resize(SZ(luck));
	FOR(i, SZ(luck)){
		MinTree &t = trees[i];
		t.A.resize(n);
		FOR(j, n) t.A[j] = luck[i]-A[j];
		t.build();
		fix(t);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	getlucky();
	std::cin >> n >> m;
	ans.build(n);
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	gettrees();
	FOR(_, m){
		std::string what;
		std::cin >> what;
		if(what[0] == 'c'){
			int a, b;
			std::cin >> a >> b;
			std::cout << ans.query(--a, --b) << "\n";
		}else{
			int a, b, x;
			std::cin >> a >> b >> x;
			--a;--b;
			fixset(a, b);
			FOR(i, SZ(trees)){
				trees[i].add(a, b, -x);
				fix(trees[i]);
			}
		}
	}
	return 0;
}