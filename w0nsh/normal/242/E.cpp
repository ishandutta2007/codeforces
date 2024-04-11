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
	VI t;
	std::vector<bool> u;
	void build(int v){
		BOTTOM = 1;
		while(BOTTOM < v) BOTTOM *= 2;
		t.resize(2*BOTTOM);
		u.resize(2*BOTTOM);
	}
	void upd(int v, int lo, int hi){
		if(u[v]){
			t[v] = hi-lo+1-t[v];
			if(v < BOTTOM){
				u[v<<1] = !u[v<<1];
				u[(v<<1)+1] = !u[(v<<1)+1];
			}
			u[v] = false;
		}
	}
	void swap(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi=BOTTOM-1;
		upd(v, lo, hi);
		if(a>b) return;
		if(a==lo && b==hi){
			u[v] = true;
			upd(v, lo, hi);
			return;
		}
		int mid = (lo+hi)/2;
		swap(a, std::min(b, mid), v<<1, lo, mid);
		swap(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
		t[v] = t[v<<1] + t[(v<<1)+1];
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi=BOTTOM-1;
		upd(v, lo, hi);
		if(a>b) return 0;
		if(a==lo && b==hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return query(a, std::min(b, mid), v<<1, lo, mid)+
				query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);
	}
};

Tree t[20];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	FOR(i, 20){
		t[i].build(n);
		FOR(j, n) if(A[j] & (1<<i)) t[i].swap(j, j);
	}
	int m;
	std::cin >> m;
	FOR(_, m){
		int what;
		std::cin >> what;
		if(what == 1){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			ll ans = 0;
			FOR(i, 20) ans += (1ll<<i)*t[i].query(a, b);
			std::cout << ans << "\n";
		}else{
			int a, b, x;
			std::cin >> a >> b >> x;
			a--;b--;
			FOR(i, 20) if((1<<i) & x) t[i].swap(a, b);
		}
	}
	return 0;
}