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


int n, m, d;
std::vector<VI> g;

int repr[200005];

void Reset(){
	FOR(i, n) repr[i] = i;
}

int Find(int a){
	if(a == repr[a]) return a;
	return repr[a] = Find(repr[a]);
}

void Union(int a, int b){
	repr[Find(a)] = Find(b);
}

bool vis[200005];
void dfs(int v){
	vis[v] = true;
	TRAV(ch, g[v]){
		if(v != 0 && ch != 0) Union(ch, v);
		if(vis[ch]) continue;
		dfs(ch);
	}
}
std::set<int> set;

int needmore = 0;

void bfs(){
	needmore = d;
	FOR(i, n) vis[i] = false;
	std::queue<int> que;
	que.push(0);
	vis[0] = true;
	while(!que.empty()){
		int cur = que.front();
		que.pop();
		TRAV(ch, g[cur]){
			if(vis[ch]) continue;
			if(cur == 0 && needmore == 0) continue;
			if(cur == 0) needmore--;
			std::cout << cur+1 << " " << ch+1 << "\n";
			vis[ch] = true;
			que.push(ch);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> d;
	g.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if(SZ(g[0]) < d){
		std::cout << "NO\n";
		return 0;
	}
	Reset();
	dfs(0);
	FOR(i, n) set.insert(Find(i));
	set.erase(set.begin());
	if(SZ(set) > d){
		std::cout << "NO\n";
		return 0;
	}
	VI neworder;
	TRAV(i, set) neworder.push_back(i);
	TRAV(i, g[0]) if(set.count(i) == 0) neworder.push_back(i);
	g[0] = neworder;
	std::cout << "YES\n";
	bfs();
	return 0;
}