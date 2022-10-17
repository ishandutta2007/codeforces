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


int n, m, d, vis[200005];
std::vector<VI> g;

void bfs(int v){
	std::queue<int> que;
	vis[v] = true;
	que.push(v);
	while(!que.empty()){
		int cur = que.front();
		que.pop();
		TRAV(ch, g[cur]){
			if(vis[ch]) continue;
			std::cout << cur+1 << " " << ch+1 << "\n";
			vis[ch] = true;
			que.push(ch);
		}
	}
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
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int max = 0;
	FOR(i, n) if(SZ(g[i]) > SZ(g[max])) max = i;
	bfs(max);
	return 0;
}