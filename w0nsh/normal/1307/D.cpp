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
int n, m, k;

std::vector<VI> g;
VI spec;
VI d1, d2;

void bfs(int src, VI &dist){
	std::fill(dist.begin(), dist.end(), -1);
	std::queue<int> que;
	que.push(src);
	dist[src] = 0;
	while(SZ(que)){
		int cur = que.front();
		que.pop();
		TRAV(ch, g[cur]){
			if(dist[ch] == -1){
				dist[ch] = dist[cur]+1;
				que.push(ch);
			}
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	spec.resize(k);
	g.resize(n);
	FOR(i, k) std::cin >> spec[i], spec[i]--;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	d1.resize(n);
	d2.resize(n);
	bfs(0, d1);
	bfs(n-1, d2);
	int ans = 0;
	std::vector<PII > A;
	FOR(i, k){
		int a = spec[i];
		A.push_back(MP(d1[a]-d2[a], a));
	}
	std::sort(A.begin(), A.end());
	VI suf(k+1);
	for(int i = k-1; i >= 0; --i) suf[i] = std::max(suf[i+1], d2[A[i].Y]);
	FOR(i, k-1){
		int a = A[i].Y;
		ans = std::max(ans, suf[i+1]+1+d1[a]);
	}
	std::cout << std::min(d1[n-1], ans) << "\n";
	
	return 0;
}