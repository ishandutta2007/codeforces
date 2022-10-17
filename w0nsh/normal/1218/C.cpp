#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : (n))
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, m, k;
ll c[505][505];
std::vector<PII> lef[505][505], up[505][505];
ll dp[2][2][505][505];
ll best[2][505][505];
const ll INF = 1000000000ll*1000000000ll;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	std::swap(n, m);
	FOR(i, k){
		int x, y, d, t, e;
		std::cin >> x >> y >> d >> t >> e;
		int time = x+y;
		bool fs = false, sc = false;
		if(time >= t && time%4 == t%4){
			c[y+1][x+1] += e;
			fs = true;
		}
		if(time >= t+1 && time%4 == (t+1)%4){
			c[y-d+1][x+d+1] += e;
			sc = true;
		}
		int time2 = x+y+d;
		if(time2 >= t+2 && time2%4 == (t+2)%4){
			c[y+1][x+d+1] += e;
			if(fs && d%4 == 2){
				lef[y+1][x+d+1].push_back(MP(d, e));
			}
			if(sc && d%4 == 1){
				up[y+1][x+d+1].push_back(MP(d, e));
			}
		}
		if(time2 >= t+3 && time2%4 == (t+3)%4){
			c[y+d+1][x+1] += e;
			if(fs && d%4 == 3){
				up[y+d+1][x+1].push_back(MP(d, e));
			}
		}
	}
	FOR(i, n+1) FOR(j, m+1) std::sort(lef[i][j].begin(), lef[i][j].end(), std::greater<PII>()),
						std::sort(up[i][j].begin(), up[i][j].end(), std::greater<PII>());
	int MX = std::max(n, m);
	FOR(xd, 2) FOR(j, m+1) FOR(x, MX+1) dp[xd][0][j][x] = INF;
	FOR(xd, 2) FOR(i, n+1) FOR(j, m+1) best[xd][i][j] = INF;
	FOR(xd, 2) best[xd][1][1] = c[1][1];
	REP(i, 1, n+1){
		int ind = i&1;
		FOR(xd, 2) FOR(j, m+1) FOR(x, MX+1) dp[xd][ind][j][x] = INF;
		REP(j, 1, m+1){
		if(i == 1 && j == 1) continue;
			ll min = 0;
			while(SZ(lef[i][j]) && lef[i][j].back().X <= 1) min += lef[i][j].back().Y, lef[i][j].pop_back();
			dp[0][ind][j][1] = std::min(dp[0][ind][j][1], best[1][i][j-1]-min+c[i][j]);
			best[0][i][j] = std::min(best[0][i][j], dp[0][ind][j][1]);
			REP(x, 2, MX+1){
				while(SZ(lef[i][j]) && lef[i][j].back().X <= x) min += lef[i][j].back().Y, lef[i][j].pop_back();
				dp[0][ind][j][x] = std::min(dp[0][ind][j-1][x-1]-min+c[i][j], dp[0][ind][j][x]);
				best[0][i][j]= std::min(best[0][i][j], dp[0][ind][j][x]);
			}

			min = 0;
			while(SZ(up[i][j]) && up[i][j].back().X <= 1) min += up[i][j].back().Y, up[i][j].pop_back();
			dp[1][ind][j][1] = std::min(dp[1][ind][j][1], best[0][i-1][j]-min+c[i][j]);
			best[1][i][j] = std::min(best[1][i][j], dp[1][ind][j][1]);
			REP(x, 2, MX+1){
				while(SZ(up[i][j]) && up[i][j].back().X <= x) min += up[i][j].back().Y, up[i][j].pop_back();
				dp[1][ind][j][x] = std::min(dp[1][ind^1][j][x-1]-min+c[i][j], dp[1][ind][j][x]);
				best[1][i][j]= std::min(best[1][i][j], dp[1][ind][j][x]);
			}
		}
	}
	/*
	FOR(i, n+1){
		FOR(j, m+1){
			std::cout << std::min(best[0][i][j], best[1][i][j]) << " ";
		}
		std::cout << "\n";
	}*/
	std::cout << std::min(best[0][n][m], best[1][n][m]) << "\n";
	return 0;
}