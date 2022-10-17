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

int n, m;
std::vector<std::vector<PII> > g;

VI topo, col;
void dfs(int v){
	col[v] = 1;
	TRAV(ch, g[v]){
		if(col[ch.X] == 0) dfs(ch.X);
	}
	col[v] = 2;
	topo.push_back(v);
}

int longest(int t){
	VI dp(n, 1);
	TRAV(i, topo){
		TRAV(ch, g[i]){
			if(ch.Y >= t) break;
			dp[i] = std::max(dp[i], dp[ch.X]+1);
		}
	}
	return dp[topo.back()];
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	g.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(MP(b, i));
	}
	col.resize(n);
	FOR(i, n) if(col[i] == 0) dfs(i);
	int left = 1;
	int right = m+1;
	while(left < right){
		int mid = (left+right)/2;
		if(longest(mid) == n) right = mid;
		else left = mid+1;
	}
	std::cout << (left == m+1 ? -1 : left) << "\n";
	return 0;
}