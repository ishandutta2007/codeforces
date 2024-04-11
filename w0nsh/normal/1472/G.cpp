#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int INF = 1000000666;
std::vector<VI> bfs(int start, const std::vector<VI>& g, std::vector<int>& dist){
	int n = SZ(g);
	dist = std::vector<int>(n, INF);
	dist[start] = 0;
	std::queue<int> que;
	que.push(start);
	std::vector<VI> ret(n);
	ret[0].push_back(start);
	while(!que.empty()){
		int cur = que.front();
		que.pop();
		TRAV(ch, g[cur]){
			if(dist[ch] == INF){
				dist[ch] = dist[cur] + 1;
				ret[dist[ch]].push_back(ch);
				que.push(ch);
			}
		}
	}
	return ret;
}
 
void solve(){
	int n, m;
	std::cin >> n >> m;
	std::vector<VI> g(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
	}
	VI dist;
	auto layers = bfs(0, g, dist);
	VI dp(n, INF);
	for(int i = n-1; i >= 0; --i){
		TRAV(v, layers[i]){
			dp[v] = dist[v];
			TRAV(ch, g[v]) if(dist[ch] > dist[v]){
				dp[v] = std::min(dp[v], dp[ch]);
			}else{
				dp[v] = std::min(dp[v], dist[ch]);
			}
		}
	}
	FOR(i, n) std::cout << dp[i] << " ";
	std::cout << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}