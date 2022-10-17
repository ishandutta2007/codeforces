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

int n;
std::vector<VI> g;
ll ans;
VI S, parent, minchild;

void fail(){
	std::cout << -1;
	std::exit(0);
}

void dfs(int v, ll last=0){
	ll ths = 0;
	if(S[v] != -1){
		ths = S[v] - last;
		if(ths < 0) fail();
	}else{
		if(minchild[v] == -1){
			ths = 0;
		}else{
			ths = minchild[v]-last;
			if(ths < 0) fail();
		}
	}
	ans += ths;
	TRAV(ch, g[v]){
		if(ch != parent[v]){
			dfs(ch, last+ths);
		}
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	S.resize(n);
	parent.resize(n, -1);
	minchild.resize(n, -1);
	g.resize(n);
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		parent[i+1] = a;
		g[a].push_back(i+1);
		g[i+1].push_back(a);
	}
	FOR(i, n) std::cin >> S[i];
	FOR(i, n){
		if(S[i] == -1){
			TRAV(ch, g[i]){
				if(ch != parent[i]){
					if(minchild[i] == -1 || S[ch] < minchild[i]) minchild[i] = S[ch];
				}
			}
		}
	}
	dfs(0);
	std::cout << ans;
	return 0;
}