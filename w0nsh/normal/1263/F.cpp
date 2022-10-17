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

const int INF = 1000000666;

VI par;
void dfs(int v, int p, std::vector<VI> &g){
	par[v] = p;
	TRAV(ch, g[v]) if(ch != p) dfs(ch, v, g);
}
std::vector<PII> A;
void dfs2(int v, int p, std::vector<VI> &g){
	TRAV(ch, g[v]) if(ch != p){
		dfs2(ch, v, g);
		A[v].X = std::min(A[v].X, A[ch].X);
		A[v].Y = std::max(A[v].Y, A[ch].Y);
	}
}

std::vector<VI> pr[2];
int dp[1005][1005][2];


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	int a;
	std::cin >> a;
	std::vector<VI> g(a);
	FOR(i, a-1){
		int p;
		std::cin >> p;
		p--;
		g[i+1].push_back(p);
		g[p].push_back(i+1);
	}
	par.resize(a);
	dfs(0, -1, g);
	A = std::vector<PII>(a, MP(INF, -INF));
	FOR(i, n){
		int x;
		std::cin >> x;
		x--;
		A[x].X = std::min(A[x].X, i);
		A[x].Y = std::max(A[x].Y, i);
	}
	dfs2(0, -1, g);
	FOR(i, 2) pr[i].resize(n);
	REP(i, 1, a){
		pr[0][A[i].Y].push_back(A[i].X);
	}
	FOR(i, n) std::sort(pr[0][i].begin(), pr[0][i].end());


	std::cin >> a;
	g = std::vector<VI>(a);
	FOR(i, a-1){
		int p;
		std::cin >> p;
		p--;
		g[i+1].push_back(p);
		g[p].push_back(i+1);
	}
	par.resize(a);
	dfs(0, -1, g);
	A = std::vector<PII>(a, MP(INF, -INF));
	FOR(i, n){
		int x;
		std::cin >> x;
		x--;
		A[x].X = std::min(A[x].X, i);
		A[x].Y = std::max(A[x].Y, i);
	}
	dfs2(0, -1, g);
	REP(i, 1, a){
		pr[1][A[i].Y].push_back(A[i].X);
	}
	FOR(i, n) std::sort(pr[1][i].begin(), pr[1][i].end());
/*
	FOR(i, n){
		TRAV(j, pr[1][i]){
			std::cout << j+1 << " " << i+1 << "\n";
		}
	}
*/	
	int ans = 0;
	FOR(i, n+1) FOR(x, 2) dp[0][i][x] = -INF;
	dp[0][0][1] = dp[0][0][0] = 0;
	REP(i, 1, n+1){
		REP(j, 2, n+1){
			FOR(x, 2){
				int xd = std::lower_bound(pr[x][i-1].begin(), pr[x][i-1].end(),
								i-j)-pr[x][i-1].begin();
				dp[i][j][x] = dp[i-1][j-1][x] + SZ(pr[x][i-1])-xd;
				ans = std::max(ans, dp[i][j][x]);
			}
		}
		FOR(x, 2){
			int best = 0;
			FOR(j, n+1) best = std::max(best, dp[i-1][j][1-x]);
			int xd = std::lower_bound(pr[x][i-1].begin(), pr[x][i-1].end(),
								i-1)-pr[x][i-1].begin();
			dp[i][1][x] = best + SZ(pr[x][i-1])-xd;
			ans = std::max(ans, dp[i][1][x]);
		}
	}
	std::cout << ans << "\n";
	return 0;
}