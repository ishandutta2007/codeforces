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

const int INF = 2000000666;

struct MaxTree{
	int BOTTOM;
	VI t;
	void go(int v){
		if(v >= BOTTOM) return;
		go(v<<1);
		go((v<<1)+1);
		t[v] = std::max(t[v<<1], t[(v<<1)+1]);
	}
	void build(VI arr){
		BOTTOM = 1;
		while(BOTTOM < SZ(arr)) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		FOR(i, SZ(arr)) t[BOTTOM+i] = arr[i];
		REP(i, SZ(arr), BOTTOM) t[BOTTOM+i] = -INF;
		go(1);
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return -INF;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return std::max(query(a, std::min(b, mid), v<<1, lo, mid),
						query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
	void update(int v, int val){
		v = BOTTOM+v;
		t[v] = val;
		while(v > 1){
			v = v>>1;
			t[v] = std::max(t[v<<1], t[(v<<1)+1]);
		}
	}
};

struct MinTree{
	int BOTTOM;
	VI t;
	void go(int v){
		if(v >= BOTTOM) return;
		go(v<<1);
		go((v<<1)+1);
		t[v] = std::min(t[v<<1], t[(v<<1)+1]);
	}
	void build(VI arr){
		BOTTOM = 1;
		while(BOTTOM < SZ(arr)) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		FOR(i, SZ(arr)) t[BOTTOM+i] = arr[i];
		REP(i, SZ(arr), BOTTOM) t[BOTTOM+i] = INF;
		go(1);
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		if(a > b) return INF;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return std::min(query(a, std::min(b, mid), v<<1, lo, mid),
						query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
	void update(int v, int val){
		v = BOTTOM+v;
		t[v] = val;
		while(v > 1){
			v = v>>1;
			t[v] = std::min(t[v<<1], t[(v<<1)+1]);
		}
	}
};

int n, k;
std::vector<VI> points;
MinTree mint[32];
MaxTree maxt[32];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	points.resize(n);
	FOR(i, n){
		FOR(j, k){
			int a;
			std::cin >> a;
			points[i].push_back(a);
		}
	}
	FOR(mask, 1<<k){
		VI vec;
		FOR(i, n){
			int cur = 0;
			FOR(j, k) cur += (mask & (1<<j) ? 1 : -1)*points[i][j];
			vec.push_back(cur);
		}
		mint[mask].build(vec);
		maxt[mask].build(vec);
	}
	int q;
	std::cin >> q;
	while(q--){
		int what;
		std::cin >> what;
		if(what == 1){
			int v;
			std::cin >> v;
			v--;
			FOR(i, k) std::cin >> points[v][i];
			FOR(mask, 1<<k){
				int cur = 0;
				FOR(j, k) cur += (mask & (1<<j) ? 1 : -1)*points[v][j];
				mint[mask].update(v, cur);
				maxt[mask].update(v, cur);
			}
		}else{
			int l, r;
			std::cin >> l >> r;
			l--;r--;
			int best = 0;
			FOR(mask, 1<<k){
				best = std::max(best, maxt[mask].query(l, r)-mint[mask].query(l, r));
			}
			std::cout << best << "\n";
		}
	}
	return 0;
}