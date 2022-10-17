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

const int MOD = 998244353;

int n;
std::vector<std::vector<PII> > g;

void add_edge(int a, int b, int t){
	g[a].push_back(MP(b, t));
	g[b].push_back(MP(a, t));
}

int con;
bool er;
VI col;
std::vector<bool> vis;

void dfs(int v){
	vis[v] = true;
	TRAV(ch, g[v]){
		if(er) break;
		if(col[ch.X] == -1){
			col[ch.X] = (ch.Y == 1 ? 1-col[v] : col[v]);
			dfs(ch.X);
		}else{
			if((col[ch.X]^col[v]) != ch.Y){
				er = true;
			}
			if(!vis[ch.X]) dfs(ch.X);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> str;
	n = SZ(str);
	int ans = 0;
	REP(sz, 1, n){
		g = std::vector<std::vector<PII> >(2*n);
		FOR(i, n/2){
			add_edge(i, n-1-i, 0);
		}
		FOR(i, sz/2){
			add_edge(2*n-1-i, 2*n-1-sz+1+i, 0);
		}
		col = VI(2*n, -1);
		vis.resize(2*n);
		std::fill(vis.begin(), vis.end(), false);
		VI have;
		col[2*n-sz] = 1;
		have.push_back(2*n-sz);
		FOR(i, n-sz){
			if(str[i] == '1') col[i] = 1, have.push_back(i);
			else if(str[i] == '0') col[i] = 0, have.push_back(i);
		}
		REP(i, n-sz, n){
			if(str[i] == '1') add_edge(i, n+i, 1);
			else if(str[i] == '0') add_edge(i, n+i, 0);
		}
		con = 1;
		er = false;
		TRAV(i, have){
			if(!vis[i]){
				dfs(i);
				if(er){
					con = 0;
					break;
				}
			}
		}
		if(!er){
			FOR(i, 2*n) if(col[i] == -1){
				if(i >= n && i < 2*n-sz) continue;
				con = (con*2)%MOD;
				col[i] = 1;
				dfs(i);
				if(er){
					con = 0;
					break;
				}
			}
		}
		// std::cout << "adding with " << sz << ": " << con << std::endl;
		ans = (ans+con)%MOD;
	}
	std::cout << ans;
	return 0;
}