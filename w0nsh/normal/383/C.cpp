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


struct Tree{
	int BOTTOM;
	std::vector<ll> t, u;
	static inline int left(int a){return a<<1;}
	static inline int right(int a){return (a<<1)+1;}
	static inline int parent(int a){return a>>1;}
	void build(VI ar){
		BOTTOM = 1;
		while(BOTTOM < SZ(ar)) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2);
		FOR(i, SZ(ar)) t[i+BOTTOM] = ar[i];
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = t[left(i)]+t[right(i)];
	}
	void upd(int v){
		if(u[v] != 0){
			t[v] += u[v];
			if(v < BOTTOM){
				u[left(v)] += u[v];
				u[right(v)] += u[v];
			}
			u[v] = 0;
		}
	}
	ll query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return 0;
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return query(a, std::min(b, mid), left(v), lo, mid) +
						query(std::max(a, mid+1), b, right(v), mid+1, hi);
	}
	void update(int a, int b, int val, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a > b) return;
		if(a == lo && b == hi){
			u[v] += val;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		update(a, std::min(b, mid), val, left(v), lo, mid);
		update(std::max(a, mid+1), b, val, right(v), mid+1, hi);
		t[v] = t[left(v)] +t[right(v)];
	}
};

std::vector<PII> ord;
std::vector<VI> g;
VI lev;
int n ,m;
Tree t1, t2;

int tick;
void dfs(int v, int par=-1){
	ord[v].X = tick++;
	TRAV(ch, g[v]){
		if(ch == par) continue;
		lev[ch] = lev[v]+1;
		dfs(ch, v);
	}
	ord[v].Y = tick++;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	VI ar(n);
	FOR(i, n) std::cin >> ar[i];
	ord.resize(n);
	g.resize(n);
	FOR(i, n-1){
		int a,b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	lev.resize(n);
	lev[0] = 0;
	dfs(0);
	VI vec(2*n);
	FOR(i, n){
		if(lev[i] % 2 == 0){
			vec[ord[i].X] = ar[i];
			vec[ord[i].Y] = ar[i];
		}
	}
	t1.build(vec);
	std::fill(vec.begin(), vec.end(), 0);
	FOR(i, n){
		if(lev[i] % 2 == 1){
			vec[ord[i].X] = ar[i];
			vec[ord[i].Y] = ar[i];
		}
	}
	t2.build(vec);
	FOR(_, m){
		int what;
		std::cin >> what;
		if(what == 1){
			int x, val;
			std::cin >> x >> val;
			x--;
			if(lev[x]%2 == 0){
				t1.update(ord[x].X, ord[x].Y, val);
			}else{
				t2.update(ord[x].X, ord[x].Y, val);
			}
		}else{
			int x;
			std::cin >> x;
			x--;
			std::cout << (lev[x]%2 == 0 ? 1ll : -1ll)*(t1.query(ord[x].X, ord[x].X)-t2.query(ord[x].X, ord[x].X)) << "\n";
		}
	}
	return 0;
}