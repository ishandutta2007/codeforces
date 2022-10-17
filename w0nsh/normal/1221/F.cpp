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
	std::vector<PR<ll, int> > t;
	std::vector<ll> u;
	void build(int v){
		BOTTOM = 1;
		while(BOTTOM < v) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2);
		FOR(i, BOTTOM) t[i+BOTTOM] = MP(0, i);
		for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::max(t[i<<1], t[(i<<1)+1]);
	}
	void upd(int v, int lo, int hi){
		if(u[v] != 0){
			t[v].X += u[v];
			if(v < BOTTOM){
				u[v<<1] += u[v];
				u[(v<<1)+1] += u[v];
			}
			u[v] = 0;
		}
	}
	void add(int a, int b, ll val, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi=BOTTOM-1;
		upd(v, lo, hi);
		if(a>b) return;
		if(a == lo && b == hi){
			u[v] += val;
			upd(v, lo, hi);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), val, v<<1, lo, mid);
		add(std::max(a, mid+1), b, val, (v<<1)+1, mid+1, hi);
		t[v] = std::max(t[v<<1],t[(v<<1)+1]);
	}
	PR<ll, int> query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v, lo, hi);
		if(a>b)return MP(-1000000000ll*1000000000ll, -1);
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return std::max(query(a, std::min(b, mid), v<<1, lo, mid),
		query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::map<int, ll> map;
	std::vector<PR<int, PII> > ev;
	std::map<int, int> kto;
	FOR(i, n){
		int x, y, c;
		std::cin >> x >> y >> c;
		map[std::max(x, y)] += c;
		map[std::min(x, y)] += 1;
		map[std::min(x, y)] -= 1;
		ev.push_back(MP(std::min(x, y), MP(c, std::max(x, y))));
	}
	Tree tree;
	tree.build(SZ(map));
	int ind = 0;
	int last = 0;
	std::map<int, int> cord;
	cord[-1] = 2000000000;
	cord[-2] = 2000000000;
	TRAV(i, map){
		kto[i.X] = ind;
		cord[ind] = i.X;
		if(ind > 0){
			tree.add(ind, SZ(map)-1, -(i.X-last));
		}
		tree.add(ind, SZ(map)-1, i.Y);
		last = i.X;
		ind++;
	}
	std::sort(ev.begin(), ev.end());
	PR<ll, PII> best = MP(0, MP(-1, -2));
	ind = 0;
	last = 0;
	auto it = ev.begin();
	TRAV(i, map){
		while(it != ev.end() && it->X < i.X) tree.add(kto[it->Y.Y], SZ(map)-1, -it->Y.X), it++;
		if(ind > 0){
			tree.add(ind, SZ(map)-1, (i.X-last));
		}
		auto cur = tree.query(ind, SZ(map)-1);
		best = std::max(best, MP(cur.X, MP(ind, cur.Y)));
		last = i.X;
		ind++;
	}
	std::cout << best.X << "\n";
	std::cout << cord[best.Y.X] << " " << cord[best.Y.X] << " " << cord[best.Y.Y] << " " << cord[best.Y.Y] << "\n";
	return 0;
}