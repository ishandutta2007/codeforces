#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto& i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
using ll = long long;
using VI = std::vector<int>;
using PII = std::pair<int, int>;

constexpr int ANG = 360;
constexpr int R = 23;
int rnd[R][ANG];
int wall[R][ANG];
bool vis[R][ANG];

bool OK;
void dfs(int r, int ang){
	if(r == R){
		OK = true;
		return;
	}
	if(vis[r][ang]) return;
	vis[r][ang] = true;

	if(!rnd[r][ang]){
		dfs(r+1, ang);
		if(OK) return;
	}
	if(r > 0 && !rnd[r-1][ang]){
		dfs(r-1, ang);
		if(OK) return;
	}
	if(!wall[r][ang]){
		dfs(r, (ang-1+ANG)%ANG);
		if(OK) return;
	}
	if(!wall[r][(ang+1)%ANG]){
		dfs(r, (ang+1)%ANG);
		if(OK) return;
	}
}

void solve(){
	int n;
	std::cin >> n;
	FOR(i, R) FOR(j, ANG) rnd[i][j] = wall[i][j] = 0, vis[i][j] = false;
	FOR(i, n){
		char c;
		std::cin >> c;
		if(c == 'C'){
			int r, fs, sc;
			std::cin >> r >> fs >> sc;
			--r;
			while(fs != sc){
				rnd[r][fs] = 1;
				fs = (fs+1)%ANG;
			}
		}else{
			int r1, r2, ang;
			std::cin >> r1 >> r2 >> ang;
			REP(r, r1, r2){
				wall[r][ang] = 1;
			}
		}
	}

	OK = false;
	dfs(0, 0);
	std::cout << (OK ? "YES\n" : "NO\n");
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}