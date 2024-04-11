#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct Tree {
	int BOTTOM;
	VI t, u;

	void build(int sz) {
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		// std::cout << "size " << BOTTOM*2 << std::endl;
		t = VI(2*BOTTOM, -1);
		u = VI(2*BOTTOM, -2);
	}

	void upd(int v){
		if(u[v] == -2) return;

		t[v] = u[v];
		if (v < BOTTOM) {
			u[v<<1] = u[v];
			u[(v<<1)+1] = u[v];
		}
		u[v] = -2;
	}

	void set(int a, int b, int co, int v=1, int lo=0, int hi=-2){
		if(hi==-2) hi = BOTTOM-1;
		upd(v);
		if(a>b) return;
		if(a == lo && b == hi){
			u[v] = co;
			upd(v);
			return;
		}
		int mid = (lo+hi)/2;
		set(a, std::min(b, mid), co, v<<1, lo, mid);
		set(std::max(a, mid+1), b, co, (v<<1)+1, mid+1, hi);
		t[v] = std::max(t[v<<1], t[(v<<1)+1]);
	}

	int get(int a, int b, int v=1, int lo=0, int hi=-2) {
		if(hi==-2) hi = BOTTOM-1;
		// std::cout << "query " << a << " " << b << " | " << lo << " " << hi << std::endl;
		// std::cout << "v " << v << std::endl;
		upd(v);
		if(a>b) return -1;
		if(a == lo && b == hi){
			return t[v];
		}
		int mid = (lo+hi)/2;
		return std::max(get(a, std::min(b, mid), v<<1, lo, mid),
						get(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
};

void solve(){
	int n;
	std::cin >> n;
	std::vector<VI> g1(n), g2(n);
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		g2[i+1].push_back(a);
		g2[a].push_back(i+1);
	}
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		g1[i+1].push_back(a);
		g1[a].push_back(i+1);
	}

	int tick = 0;
	VI pre(n);
	VI last(n);
	std::function<void(int, int)> dfs = [&](int v, int par){
		pre[v] = tick++;
		TRAV(ch, g1[v]) if(ch != par) dfs(ch, v);
		last[v] = tick-1;
	};
	dfs(0, -1);
	assert(tick == n);

	Tree tree;
	tree.build(n);

	int best = 0;
	int ans = 0;

	std::function<void(int, int)> dfs2 = [&](int v, int par){
		bool zdejm = false;
		int kto = tree.get(pre[v], pre[v]);
		// std::cout << "jestem w " << v << " kto = " << kto << std::endl;
		if(kto != -1){
			zdejm = true;
			tree.set(pre[kto], last[kto], -1);
			tree.set(pre[v], last[v], v);
		}else{
			if(tree.get(pre[v], last[v]) == -1){
				zdejm = true;
				tree.set(pre[v], last[v], v);
				ans++;
			}
		}

		best = std::max(best, ans);

		TRAV(ch, g2[v]) if(ch != par){
			dfs2(ch, v);
		}

		if (zdejm) {
			tree.set(pre[v], last[v], -1);
			if (kto != -1) {
				tree.set(pre[kto], last[kto], kto);
			} else {
				ans--;
			}
		}
	};

	dfs2(0, -1);

	std::cout << best << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}