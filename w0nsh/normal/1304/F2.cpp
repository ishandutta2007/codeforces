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

int tab[55][20005];
const int INF = 2000000666;

struct Tree{
	int BOTTOM;
	std::vector<int> t, u;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		u.resize(BOTTOM*2);
	}
	void clear(){
		t = u = VI(BOTTOM*2);
	}
	void upd(int v){
		t[v] += u[v];
		if(v < BOTTOM){
			u[v<<1] += u[v];
			u[(v<<1)+1] += u[v];
		}
		u[v] = 0;
	}
	int query(int a, int b, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return 0;
		if(a == lo && b == hi) return t[v];
		int mid =(lo+hi)/2;
		return std::max(query(a, std::min(b, mid), v<<1, lo, mid),
					query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
	void add(int a, int b, int w, int v=1, int lo=0, int hi=-2){
		if(hi == -2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return;
		if(a == lo && b == hi){
			u[v] += w;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		add(a, std::min(b, mid), w, v<<1, lo, mid);
		add(std::max(a, mid+1), b, w, (v<<1)+1, mid+1, hi);
		t[v] = std::max(t[v<<1], t[(v<<1)+1]);
	}
};

int n, m, k;
int pref[55][20005];
int dp[55][20005];
int pf(int i, int a, int b){
	if(a > b) return 0;
	return pref[i][b]-pref[i][a-1];
}
int sum(int i, int j){
	int b = std::min(m, j+k-1);
	return pref[i][b]-pref[i][j-1]+pref[i+1][b]-pref[i+1][j-1];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	FOR(i,n) FOR(j, m) std::cin >> tab[i+1][j+1];
//	n++;
	REP(i, 1, n+1){
		REP(j, 1, m+1){
			pref[i][j] = pref[i][j-1]+tab[i][j];
		}
	}
	Tree tree;
	tree.build(m+5);
	REP(i, 1, m+1) dp[1][i] = sum(1, i);
	REP(i, 2, n+1){
		tree.clear();
		REP(j, 1, m+1){
			tree.add(j, j, dp[i-1][j]-pf(i, j, k));
		}
		REP(j, 1, m+1){
			dp[i][j] = sum(i, j) + tree.query(1, m);
			int lef = j-k+1;
			if(lef < 1) lef = 1;
			int rig = j;
			tree.add(lef, rig, tab[i][j]);
			int ps = j+k;
			if(ps <= m){
				lef = ps-k+1;
				rig = ps;
				tree.add(lef, rig, -tab[i][ps]);
			}
		}
	}
//	REP(i, 1, n+1){
//		REP(j, 1, m+1){
//			std::cout << dp[i][j] << " ";
//		}
//		std::cout << "\n";
//	}
	int mx = 0;
	REP(j, 1, m+1) mx = std::max(dp[n][j], mx);
	std::cout << mx << "\n";
	return 0;
}