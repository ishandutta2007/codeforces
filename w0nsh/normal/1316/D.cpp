#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

PII tab[1005][1005];
int n;
PII operator + (PII a, PII b){
	return MP(a.X+b.X, a.Y+b.Y);
}
PII operator - (PII a, PII b){
	return MP(a.X-b.X, a.Y-b.Y);
}

bool bounds(PII a){
	return a.X >= 1 && a.X <= n && a.Y >= 1 && a.Y <= n;
}
	std::vector<PII> dir = std::vector<PII>{MP(1, 0), MP(-1, 0), MP(0, 1), MP(0, -1)};
char get(PII p, PII v){
	if(p.X == -1) return 'X';
	p = p-v;
	if(p == MP(1, 0)) return 'D';
	else if(p == MP(-1, 0)) return 'U';
	else if(p == MP(0, 1)) return 'R';
	return 'L';
}
bool vis[1005][1005];
char ans[1005][1005];
void dfs(PII v, PII par){
	ans[v.X][v.Y] = get(par, v);
	TRAV(d, dir){
		PII ps = v+d;
		if(bounds(ps) && ans[ps.X][ps.Y] == '$' && tab[ps.X][ps.Y] == tab[v.X][v.Y]) dfs(ps, v);
	}
}
bool dfs2(PII v){
	TRAV(d, dir){
		PII ps = v+d;
		if(bounds(ps) && tab[ps.X][ps.Y].X == -1){
			ans[v.X][v.Y] = get(ps, v);
		}
		if(bounds(ps) && ans[ps.X][ps.Y] == '$') dfs2(ps);
	}
	return ans[v.X][v.Y] != '$';
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		FOR(j, n){
			int x, y;
			std::cin >> x >> y;
			tab[i+1][j+1] = MP(x, y);
		}
	}
	/*REP(i, 1, n+1){
		REP(j, 1, n+1){
			TRAV(d, dir){
				PII pos = d+MP(i, j);
				if(bounds(pos) && tab[pos.X][pos.Y] == tab[i][j]) Union(pos, MP(i, j));
			}
		}
	}*/
	FOR(i, n+1) FOR(j, n+1) ans[i][j] ='$';
	REP(i, 1, n+1){
		REP(j, 1, n+1){
			if(tab[i][j] == MP(i, j)){
				dfs(MP(i, j), MP(-1, -1));
			}
		}
	}
	REP(i, 1, n+1){
		REP(j, 1, n+1){
			if(tab[i][j] != MP(-1, -1) && ans[i][j] == '$'){
				std::cout << "INVALID";
				return 0;
			}
		}
	}
	REP(i, 1, n+1){
		REP(j, 1, n+1){
			if(ans[i][j] == '$' && !dfs2(MP(i, j))){
				std::cout << "INVALID";
				return 0;
			}
		}
	}
	std::cout << "VALID\n";
	REP(i, 1, n+1){
		REP(j, 1, n+1){
			std::cout << ans[i][j];
		}
		std::cout << "\n";
	}
	

	return 0;
}