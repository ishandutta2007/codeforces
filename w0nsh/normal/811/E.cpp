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

int n, m, q;

struct DSU{
	VI repr;
	int ile = 0;
	DSU(){}
	DSU(int size){
		repr.resize(size);
		FOR(i, size) repr[i] = i;
		ile = SZ(repr);
	}
	int MakeSet(){
		int ind = SZ(repr);
		repr.push_back(ind);
		ile++;
		return ind;
	}
	int Find(int a){
		if(a == repr[a]) return a;
		return repr[a] = Find(repr[a]);
	}
	bool Union(int a, int b){
		a = Find(a);
		b = Find(b);
		if(a != b){
			repr[a] = b;
			ile--;
			return true;
		}
		return false;
	}
};

const int LOG = 17;
int tab[12][1<<LOG];
DSU t[1<<(LOG+1)];

void go(int v, int lo, int hi){
	int sz = hi-lo+1;
	t[v] = DSU(m*sz);
	FOR(i, m){
		FOR(j, sz){
			if(i < m-1 && tab[i][lo+j] == tab[i+1][lo+j])
				t[v].Union(i*sz+j, (i+1)*sz+j);
			if(j < sz-1 && tab[i][lo+j] == tab[i][lo+j+1])
				t[v].Union(i*sz+j, i*sz+j+1);
		}
	}
	if(lo != hi){
		go(v<<1, lo, (lo+hi)/2);
		go((v<<1)+1, (lo+hi)/2+1, hi);
	}
}

void build(){
	go(1, 0, (1<<(LOG))-1);
}

std::vector<PR<PII, int> > prze;
int get(int a, int b, int v=1, int lo=0, int hi=(1<<LOG)-1){
	if(a>b) return 0;
	if(a == lo && b == hi){
		prze.push_back(MP(MP(a, b), v));
		return t[v].ile;
	}
	int mid = (lo+hi)/2;
	return get(a, std::min(mid, b), v<<1, lo, mid)
			+ get(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
}

int query(int a, int b){
	prze.clear();
	int ans = get(a, b);
	DSU dsu;
	std::map<PII, int> map;
	FOR(i, SZ(prze)-1){
		int fs = prze[i].X.Y;
		int sc = prze[i+1].X.X;
		int sz1 = prze[i].X.Y-prze[i].X.X+1;
		int sz2 = prze[i+1].X.Y-prze[i+1].X.X+1;
		auto &ds1 = t[prze[i].Y];
		auto &ds2 = t[prze[i+1].Y];
		FOR(j, m){
			if(tab[j][fs] == tab[j][sc]){
				PII aa = MP(i, ds1.Find(j*sz1+sz1-1));
				PII bb = MP(i+1, ds2.Find(j*sz2));
				if(map.count(aa) == 0) map[aa] = dsu.MakeSet();
				if(map.count(bb) == 0) map[bb] = dsu.MakeSet();
				if(dsu.Union(map[aa], map[bb])) ans--;
			}
		}
	}
	return ans;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> m >> n >> q;
	FOR(i, m) FOR(j, n) std::cin >> tab[i][j];
	FOR(i, m) REP(j, n, 1<<LOG) tab[i][j] = 1002137;
	build();
	FOR(_, q){
		int l, r;
		std::cin >> l >> r;
		l--;r--;
		std::cout << query(l, r) << "\n";
	}
	return 0;
}