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
	VI t;
	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t.resize(BOTTOM*2);
	}
	void add(int a, int b, int val){
		a += BOTTOM;
		b += BOTTOM+1;
		while(a < b){
			if(a&1) t[a] = (t[a]+val)%MOD, a++;
			if(b&1) --b, t[b] = (t[b]+val)%MOD;
			b >>= 1; a >>= 1;
		}
	}
	int query(int a){
		int sum = 0;
		a += BOTTOM;
		while(a >= 1){
			sum = (sum+t[a])%MOD;
			a >>= 1;
		}
		return sum;
	}
};

int n, q;
std::vector<VI> g;
VI level;
VI start, end;

int _tick;
void dfs(int v, int par=-1){
	start[v] = _tick++;
	TRAV(ch, g[v]) if(ch != par) level[ch] = level[v]+1, dfs(ch, v);
	end[v] = _tick-1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		g[i+1].push_back(a);
		g[a].push_back(i+1);
	}
	level.resize(n);
	start.resize(n);
	end.resize(n);
	dfs(0);
	SumTree sum, mul;
	sum.build(n);
	mul.build(n);
	std::cin >> q;
	while(q--){
		int what;
		std::cin >> what;
		if(what == 1){
			int v, x, k;
			std::cin >> v >> x >> k;
			v--;
			sum.add(start[v], end[v], (1ll*k*level[v]+x)%MOD);
			mul.add(start[v], end[v], k);
		}else{
			int v;
			std::cin >> v;
			v--;
			int ans1 = sum.query(start[v]);
			int ans2 = (-1ll*mul.query(start[v])*level[v])%MOD;
			int ans = (ans1+ans2)%MOD;
			if(ans < 0) ans += MOD;
			std::cout << ans << "\n";
		}
	}
	return 0;
}