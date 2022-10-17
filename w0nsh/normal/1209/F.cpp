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

const int MOD = 1000000007;

int n, m;
int N;
std::vector<std::vector<PII> > g;

void bfs(){
	std::queue<int> que;
	que.push(0);
	std::vector<int> dist(N, 1000000000);
	dist[0] = 0;
	while(SZ(que)){
		int v = que.front();
		que.pop();
		FOR(i, SZ(g[v])){
			int to = g[v][i].X;
			if(dist[to] < dist[v]+1){
				std::swap(g[v][i], g[v].back());
				g[v].pop_back();
				i--;
			}else if(dist[to] > dist[v]+1){
				dist[to] = dist[v]+1;
				que.push(to);
			}
		}
	}
}

VI ans;
void bfs2(){
	ans.resize(N, -1);
	ans[0] = 0;
	std::vector<bool> vis(N);
	std::queue<VI> que;
	que.push(VI{0});
	vis[0] = true;
	while(SZ(que)){
		VI vec = que.front();
		que.pop();
		FOR(val, 10){
			VI now;
			TRAV(cur, vec){
				TRAV(ch, g[cur]) if(ch.Y == val && vis[ch.X] == false){
					ans[ch.X] = (10ll*ans[cur]+ch.Y)%MOD;
					vis[ch.X] = true;
					now.push_back(ch.X);
				}
			}
			if(SZ(now)) que.push(now);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	g.resize(n);
	REP(xd, 1, m+1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		std::string s = std::to_string(xd);
		int last = a;
		FOR(i, SZ(s)){
			g.emplace_back();
			int next = SZ(g)-1;
			if(i == SZ(s)-1) next = b;
			g[last].push_back(MP(next, s[i]-'0'));
			g[next].push_back(MP(last, s[SZ(s)-1-i]-'0'));
			last = next;
		}
	}
	N = SZ(g);
	bfs();
	bfs2();
	REP(i, 1, n) std::cout << ans[i] << "\n";
	return 0;
}