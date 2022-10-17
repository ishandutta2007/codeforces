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

std::vector<VI> g;
VI tm, col;
int TICK, COL;
VI cyc;

int pww(int a, int e){
	int ret = 1;
	FOR(i, e) ret = (1ll*ret*a)%MOD;
	return ret;
}

void dfs(int v){
	col[v] = COL;
	TRAV(ch, g[v]){
		if(col[ch] != -1){
			if(col[ch] == col[v]){
				cyc.push_back(tm[v]-tm[ch]+1);
			}
		}else{
			tm[ch] = tm[v]+1;
			dfs(ch);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	g.resize(n);
	tm.resize(n);
	col.resize(n, -1);
	FOR(i, n){
		int a;
		std::cin >> a;
		a--;
		g[i].push_back(a);
	}
	FOR(i, n){
		if(col[i] == -1){
			TICK++;
			dfs(i);
			COL++;
		}
	}
	int notcyc = n;
	TRAV(i, cyc) notcyc -= i;
	
	int ans = pww(2, notcyc);
	TRAV(i, cyc) ans = (1ll*ans*(pww(2, i)-2))%MOD;
	std::cout << ans;
	return 0;
}