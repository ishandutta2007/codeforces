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

int n, m;
std::vector<VI> g, grev;
std::vector<VI> gsc;
std::vector<VI> inside;
VI sc;
int fre;
std::vector<bool> vis;
const int INF = 1000000000;
VI topo;
void dfs(int v){
	vis[v] = true;
	TRAV(ch, g[v]) if(!vis[ch]){
		dfs(ch);
	}
	topo.push_back(v);
}

void dfs2(int v){
	inside[fre].push_back(v);
	sc[v] = fre;
	TRAV(ch, grev[v]){
		if(sc[ch] != -1){
			if(sc[ch] != sc[v])
				gsc[sc[ch]].push_back(sc[v]);
		}else{
			dfs2(ch);
		}
	}
}

int cyc(int s){
	std::queue<int> que;
	VI dist(n, INF);
	dist[s] = 0;
	que.push(s);

	while(SZ(que)){
		int v = que.front();
		que.pop();
		TRAV(ch, g[v]){
			if(ch == s) return dist[v]+1;
			if(dist[ch] == INF){
				dist[ch] = dist[v]+1;
				que.push(ch);
			}
		}
	}

	assert(false);
}

void solve(){
	vis = std::vector<bool>(n);
	topo = VI();
	FOR(i, n) if(!vis[i]) dfs(i);
	std::reverse(topo.begin(), topo.end());

	fre = 0;
	gsc = std::vector<VI >();
	sc = VI(n, -1);

	TRAV(i, topo) if(sc[i] == -1){
		gsc.emplace_back();
		inside.emplace_back();
		dfs2(i);
		fre++;
	}

	int ans = n;

	FOR(i, fre){
		if(SZ(gsc[i]) == 0){
			if(SZ(inside[i]) == 1) continue;
			int minsize = INF;
			TRAV(j, inside[i]){
				minsize = std::min(minsize, cyc(j));
			}

			ans += 998*minsize+1;
		}
	}

	std::cout << ans << "\n";
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	g.resize(n);
	grev.resize(n);
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		grev[b].push_back(a);
	}

	solve();

	return 0;
}