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

int n;
std::vector<VI> g;
std::string s;
std::vector<bool> vis;

VI cnt;

int dfs(int v){
	vis[v] = true;
	cnt[s[v]-'a']++;
	int sz = 1;
	TRAV(ch, g[v]) if(!vis[ch]) sz += dfs(ch);
	return sz;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int k;
		std::cin >> n >> k;
		std::cin >> s;
		g = std::vector<VI>(n);
		vis = std::vector<bool>(n);
		FOR(i, n-k){
			g[i].push_back(i+k);
			g[i+k].push_back(i);
		}
		FOR(i, n){
			if(i != n-1-i) g[i].push_back(n-1-i);
		}
		int ans = 0;
		FOR(i, n) if(!vis[i]){
			cnt = VI(26, 0);
			int all = dfs(i);
			int best = all;
			FOR(j, 26) best = std::min(best, all-cnt[j]);
			ans += best;
		}
		std::cout << ans << "\n";
	}

	return 0;
}