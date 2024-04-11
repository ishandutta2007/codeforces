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

std::vector<VI> g;
const int INF = 1000000666;

std::vector<int> dist;
int bfs(int s){
	std::fill(dist.begin(), dist.end(), 0);
	std::vector<int> now, next;
	now.push_back(s);
	dist[s] = 2;
	int layer = 0;
	int ans = INF;
	while(SZ(now)){
		TRAV(cr, now){
			TRAV(ch, g[cr]){
				if(dist[ch] == 0){
					next.push_back(ch);
					dist[ch] = 1;
				}else if(dist[ch] == 1){
					ans = std::min(ans, 2*(layer+1));
				}else if(dist[ch] == 2){
					return 2*layer+1;
				}
			}
		}
		if(ans != INF) return ans;
		TRAV(i, now) dist[i] = 3;
		TRAV(i, next) dist[i] = 2;
		now = next;
		next = VI();
		layer++;
	}
	return ans;
}

void solve(){
	dist.resize(1000001);
	int ans = INF;
	FOR(i, 1001){
		ans = std::min(ans, bfs(i));
	}
	if(ans == INF) std::cout << -1 << "\n";
	else std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	g.resize(1000001);
	bool ans2 = false;
	std::set<PII> set;
	FOR(i, n){
		std::cin >> A[i];
		if(A[i] == 1){
			std::cout << 1 << "\n";
			return 0;
		}
		PII f1 = MP(-1, 0);
		PII f2 = f1;
		int cur = A[i];
		for(int j = 2; j*j <= cur; ++j) if(cur%j == 0){
			int cnt = 0;
			while(cur%j == 0) cnt = 1-cnt, cur/=j;
			f1 = MP(j, cnt);
			break;
		}
		if(f1 == MP(-1, 0)){
			f1 = MP(cur, 1);
			cur /= cur;
		}else if(cur != 1){
			for(int j = 2; j*j <= cur; ++j) if(cur%j == 0){
				int cnt = 0;
				while(cur%j == 0) cnt = 1-cnt, cur/=j;
				f2 = MP(j, cnt);
				break;
			}
			if(f2 == MP(-1, 0)){
				f2 = MP(cur, 1);
				cur /= cur;
			}
		}
		assert(cur == 1);
		if(f1.Y == 0 && f2.Y == 0){
			std::cout << 1 << "\n";
			return 0;
		}
		if(f1.Y == 1 && f2.Y == 1){
			if(set.count(MP(f1.X, f2.X)) || set.count(MP(f2.X, f1.X))){
				ans2 = true;
			}
			set.insert(MP(f1.X, f2.X));
			g[f1.X].push_back(f2.X);
			g[f2.X].push_back(f1.X);
		}else{
			if(f1.Y == 0) std::swap(f1, f2);
			g[0].push_back(f1.X);
			g[f1.X].push_back(0);
			if(set.count(MP(f1.X, 0))){
				ans2 = true;
			}
			set.insert(MP(f1.X, 0));
		}
	}
	if(ans2){
		std::cout << 2 << "\n";
		return 0;
	}
	solve();
	return 0;
}