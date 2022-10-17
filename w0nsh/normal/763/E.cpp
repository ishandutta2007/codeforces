#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct dsu{
	VI repr;
	dsu(){}
	dsu(int size){
		repr.resize(size);
		FOR(i, size) repr[i] = i;
	}
	int Find(int a){
		if(a == repr[a]) return a;
		return repr[a] = Find(repr[a]);
	}
	int Union(int a, int b){
		a = Find(a);
		b = Find(b);
		if(a == b) return 0;
		repr[a] = b;
		return 1;
	}
	int MakeSet(){
		int id = SZ(repr);
		repr.push_back(id);
		return id;
	}
};

int bot, n, k;
std::vector<dsu> t;
VI ile;
std::vector<VI> g;

void go(int v, int lo, int hi){
	if(hi < n){
		t[v] = dsu(hi-lo+1);
		ile[v] = hi-lo+1;
		REP(i, lo, hi+1){
			TRAV(ch, g[i]) if(lo <= ch && ch <= hi){
				ile[v] -= t[v].Union(i-lo, ch-lo);
			}
		}
	}
	int mid = (lo+hi)/2;
	if(hi != lo) go(v<<1, lo, mid), go((v<<1)+1, mid+1, hi);
}
void build(){
	bot = 1;
	while(bot < n) bot *= 2;
	t.resize(bot*2);
	ile.resize(bot*2);
	go(1, 0, bot-1);
}
std::vector<PR<int, PII> > vec;
int query(int a, int b, int v=1, int lo=0, int hi=-2){
	if(hi==-2) hi=bot-1;
	if(a > b) return 0 ;
	if(a == lo && b== hi){
		vec.push_back(MP(v, MP(lo, hi)));
		return ile[v];
	}
	int mid = (lo+hi)/2;
	return query(a, std::min(mid, b), v<<1, lo, mid)
		 + query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
}


int answer(int l, int r){
	vec.clear();
	int ans = query(l, r);
	std::map<PII, int> map;
	dsu ds;
	std::vector<PII> guys;
	VI kon;
	FOR(i, SZ(vec)) kon.push_back(vec[i].Y.Y);
	FOR(i, SZ(vec)){
		int lo = vec[i].Y.X;
		int hi = vec[i].Y.Y;
		REP(j, lo, std::min(lo+k, hi+1)){
			TRAV(ch, g[j]){
				if(ch < l) continue;
				int ind = std::lower_bound(kon.begin(), kon.end(), ch)-kon.begin();
				if(ind == i) continue;
				int ins = ch-vec[ind].Y.X;
				PII my = MP(i, t[vec[i].X].Find(j-lo));
				PII xd = MP(ind, t[vec[ind].X].Find(ins));
				if(map.count(my) == 0) map[my] = ds.MakeSet();
				if(map.count(xd) == 0) map[xd] = ds.MakeSet();
				ans -= ds.Union(map[xd], map[my]);
			}
		}
	}
	return ans;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	g.resize(n);
	int m;
	std::cin >> m;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		if(a < b) std::swap(a, b);
		g[a].push_back(b);
	}
	build();
	int q;
	std::cin >> q;
	while(q--){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		std::cout << answer(a, b) << "\n";
	}
	return 0;
}