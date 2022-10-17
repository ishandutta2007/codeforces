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

const int MOD = 1000000007;

struct SumTree{
	int BOTTOM;
	VI t, u;
	void go(int v){
		if(v >= BOTTOM) return;
		go(v<<1);
		go((v<<1)+1);
		t[v] = (t[v<<1] + t[(v<<1)+1])%MOD;
	}
	void build(VI arr){
		BOTTOM = 1;
		while(BOTTOM < SZ(arr)) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2, -1);
		FOR(i, SZ(arr)) t[BOTTOM+i] = arr[i];
		REP(i, SZ(arr), BOTTOM) t[BOTTOM+i] = 0;
		go(1);
	}

	void upd(int v, int lo, int hi){
		if(u[v] != -1){
			t[v] = (1ll*(hi-lo+1)*u[v])%MOD;
			if(v < BOTTOM) u[v<<1] = u[(v<<1)+1] = u[v];
			u[v] = -1;
		}
	}

	void add(int a, int val, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v, lo, hi);
		if(lo == hi){
			t[v] = (t[v] + val)%MOD;
			return;
		}
		int mid = (lo+hi)/2;
		if(a > mid) add(a, val, (v<<1)+1, mid+1, hi);
		else add(a, val, (v<<1), lo, mid);
		upd(v<<1, lo, mid);
		upd((v<<1)+1, mid+1, hi);
		t[v] = (t[v<<1] + t[(v<<1)+1])%MOD; 
	}

	void set(int a, int b, int val, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v, lo, hi);
		if(a > b) return;
		if(a == lo && b == hi){
			u[v] = val;
			upd(v, lo, hi);
			return;
		}
		int mid = (lo+hi)/2;
		set(a, std::min(mid, b), val, v<<1, lo, mid);
		set(std::max(a, mid+1), b, val, (v<<1)+1, mid+1, hi);
		t[v] = (t[v<<1]+t[(v<<1)+1])%MOD;
	}

	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v, lo, hi);
		if(a > b) return 0;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return (query(a, std::min(b, mid), v<<1, lo, mid)
				+ query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi))%MOD;
	}
};

struct Event{
	int x;
	int s, e;
	int type;
	Event(){}
	Event(int _x, int _s, int _e, int _type) : x(_x), s(_s), e(_e), type(_type) {}
};

SumTree tree;
int n, m, k;
std::vector<Event> events;  

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	if(k == 0){
		std::cout << 1 << "\n";
		return 0;
	}
	FOR(i, k){
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		a--;b--;c--;d--;
		events.push_back(Event(a, b, d, 1));
		events.push_back(Event(c+1, b, d, -1));
	}
	tree.build(VI(m+5));
	tree.add(0, 1);
	std::sort(events.begin(), events.end(), [](const Event &a, const Event &b){
		if(a.x == b.x){
			if(a.type == b.type){
				return a.s > b.s;
			}
			return a.type == 1;
		}
		return a.x < b.x;
	});
	std::multiset<PII> obs;
	auto it = events.begin();
	while(it != events.end() && it->x < n){
		if(it->type == 1){
			auto xd = obs.lower_bound(MP(it->e+2, -1));
			int lef = 0;
			int rig = it->e;
			if(xd != obs.begin()) lef = (--xd)->Y+1;
			if(it->x > 0 && lef <= rig && it->e+1 < m){
				int dd = tree.query(lef, rig);
				tree.add(it->e+1, dd);
			}
			obs.insert(MP(it->s, it->e));
			tree.set(it->s, it->e, 0);
		}else{
			obs.erase(obs.find(MP(it->s, it->e)));
		}
		it++;
	}
	auto xd = obs.end();
	if(xd != obs.begin()) xd--;
	int lef = 0;
	int rig = m-1;
	if(xd != obs.end()) lef = xd->Y;
	std::cout << tree.query(lef, rig) << "\n";
	return 0;
}