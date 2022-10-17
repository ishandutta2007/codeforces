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
	void build(int size){
		BOTTOM =1;
		while(BOTTOM < size) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2);
	}
	void upd(int v, int lo, int hi){
		if(u[v] != 0){
			if(v < BOTTOM){
				u[v<<1] += u[v];
				u[(v<<1)+1] += u[v];
			}
			t[v] += u[v];
			u[v] = 0;
		}
	}
	void add(int a, int b, ll w, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v, lo, hi);
		if(a>b) return;
		if(a==lo && b==hi){
			u[v] += w;
			upd(v, lo, hi);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), w, v<<1, lo, mid);
		add(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		t[v] = std::max(t[v<<1], t[(v<<1)+1]);
		// t[v] = t[v<<1] + t[(v<<1)+1];
	}
	ll query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v, lo, hi);
		if(a>b) return 0;
		if(a==lo && b==hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return std::max(query(a, std::min(b, mid), v<<1, lo, mid),
				query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
		// return query(a, std::min(b, mid), v<<1, lo, mid)
				// +query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi);

	}
};

int n, m;
ll dp[200005];
std::vector<std::vector<PII> > races; 
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	races.resize(n);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		b--;a--;
		races[b].push_back(MP(a, c));
	}
	Tree tree;
	tree.build(n+1);
	REP(i, 1, n+1){
		tree.add(0, i-1, -A[i-1]);
		TRAV(r, races[i-1]){
			tree.add(0, r.X, r.Y);
		}
		dp[i] = std::max(dp[i-1], tree.query(0, tree.BOTTOM-1));
		tree.add(i, i, dp[i]);
	}
	std::cout << *std::max_element(dp, dp+n+1) << "\n";
	return 0;
}