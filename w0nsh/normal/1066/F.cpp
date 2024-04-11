#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n;
ll dp[2][200005];
PII last[2][200005];
std::map<int, std::vector<PII> > map;

inline int dist(PII &a, PII &b){
	return std::abs(a.X-b.X)+std::abs(a.Y-b.Y);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		map[std::max(a, b)].push_back(MP(a, b));
	}
	int i = 1;
	TRAV(pr, map){
		auto &vec = pr.Y;
		std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b){
			if(a.X == b.X) return a.Y > b.Y;
			return a.X < b.X;
		});
		dp[1][i] = std::min(dp[0][i-1]+dist(last[0][i-1], vec[0]), dp[1][i-1]+dist(last[1][i-1], vec[0]));
		dp[0][i] = std::min(dp[0][i-1]+dist(last[0][i-1], vec.back()), dp[1][i-1]+dist(last[1][i-1], vec.back()));
		dp[1][i] += dist(vec[0], vec.back());
		dp[0][i] += dist(vec[0], vec.back());
		last[0][i] = vec[0];
		last[1][i] = vec.back();
	//	std::cout << i << " : " << dp[0][i] << "," << dp[1][i] << "\n";
		i++;
	}
	std::cout << std::min(dp[0][i-1], dp[1][i-1]) << "\n";
	return 0;
}