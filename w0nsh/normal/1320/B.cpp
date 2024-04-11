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
const int INF = 1000000000;
std::vector<VI> g, grev;
int n, m;
void bfs(std::vector<int> &d, int s){
	std::queue<int> que;
	d = VI(n, INF);
	d[s] = 0;
	que.push(s);
	while(SZ(que)){
		int cur = que.front();
		que.pop();
		TRAV(ch, grev[cur]){
			if(d[ch] == INF){
				d[ch] = d[cur]+1;
				que.push(ch);
			}
		}
	}
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
	int k;
	std::cin >> k;
	VI P(k);
	FOR(i, k) std::cin >> P[i];
	FOR(i, k) P[i]--;
	std::vector<int> d1, d2;
	bfs(d2, P.back());
	int min = 0;
	int max = 0;
	FOR(i, k-1){
		int good = 0;
		std::set<int> gd;
		int BEST = INF;
		TRAV(ch, g[P[i]]) BEST = std::min(BEST, d2[ch]);
		TRAV(ch, g[P[i]]){
			if(d2[ch] == BEST) good++, gd.insert(ch);
		}
		if(SZ(g[P[i]]) != 1){
			if(gd.count(P[i+1])){
				if(SZ(gd) > 1){
					max++;
				}
			}else{
				min++;
				max++;
			}
		}
	}
	std::cout << min <<" " << max;
	return 0;
}