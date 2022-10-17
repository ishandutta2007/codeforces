#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct SAT{
	std::vector<std::vector<int> > g;
	std::vector<bool> m;
	std::vector<int> s;
	int c, n;
	SAT(){}
	SAT(int xd){
		n=xd;
		g = std::vector<std::vector<int> > (2*n);
		m = std::vector<bool>(2*n);
		s = std::vector<int>(2*n);
	}

	void add_clause(int x, int xval, int y, int yval){
		x = (x<<1)+xval;
		y = (y<<1)+yval;
		g[x^1].push_back(y);
		g[y^1].push_back(x);
	}

	void add_impl(int x, int xval, int y, int yval){
		x = (x<<1)+xval;
		y = (y<<1)+yval;
		g[x].push_back(y);
		g[y^1].push_back(x^1);
	}

	bool dfs(int x){
		if(m[x^1]) return 0;
		if(m[x]) return 1;
		m[x]=1; s[c++]=x;
		for(auto ch : g[x]) if(!dfs(ch)) return 0;
		return 1;
	}
	bool solve(){
		for(int i = 0; i < 2*n; i += 2) if(!m[i] && !m[i+1]){
			c = 0;
			if(!dfs(i)){
				while(c) m[s[--c]] = 0;
				if(!dfs(i+1)) return 0;
			}
		}
		return 1;
	}
	inline bool val(int a){
		return m[a*2+1];
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, p, M, m;
	std::cin >> n >> p >> M >> m;
	SAT sat = SAT(p+2*(M+2));
	FOR(i, M+1) sat.add_impl(p+i+1, 1, p+i, 1);
	FOR(i, M+1) sat.add_impl(p+M+2+i, 1, p+M+2+i+1, 1);
	FOR(i, M+1) sat.add_clause(p+i, 1, p+M+2+i+1, 1);
	FOR(i, M+1) sat.add_clause(p+i, 0, p+M+2+i+1, 0);
	sat.add_clause(p, 1, p, 1);
	sat.add_clause(p+M, 0, p+M, 0);
	sat.add_clause(p+2*(M+2)-1, 1, p+2*(M+2)-1, 1);
	sat.add_clause(p+M+3, 0, p+M+3, 0);
	FOR(i, n){
		int x, y;
		std::cin >> x >> y;
		x--;y--;
		sat.add_clause(x, 1, y, 1);
	}
	FOR(i, p){
		int l, r;
		std::cin >> l >> r;
		sat.add_impl(i, 1, p+l-1, 1);
		sat.add_impl(i, 1, p+M+2+r+1, 1);
	}
	FOR(i, m){
		int x, y;
		std::cin >> x >> y;
		x--;y--;
		sat.add_clause(x, 0, y, 0);
	}
	if(!sat.solve()) std::cout << -1 << "\n";
	else{
		VI ans;
		FOR(i, p) if(sat.val(i)) ans.push_back(i);
		int f = -1;
		REP(i, 1, M+1) if(!sat.val(p+i) && !sat.val(p+M+2+i)){
			f = i;
			break;
		}
		assert(f != -1);
		std::cout << SZ(ans) << " " << f << "\n";
		TRAV(i, ans) std::cout << i+1 << " ";
	}
	return 0;
}