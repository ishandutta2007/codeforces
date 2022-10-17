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

int tests;
int n, m;
std::vector<VI> g;
VI vec;

int cur, vis;

void dfs(int v, int par=-1){
	if(cur == -1) return;
	if(vec[v] == 0) cur++;
	vis++;
	TRAV(ch, g[v]){
		if(cur == -1) return;
		if(ch == par) continue;
		if(vec[ch] != -1){
			if(vec[ch] == (vec[v]+1)%2) continue;
			cur = -1;
			return;
		}
		vec[ch] = (vec[v]+1)%2;
		dfs(ch, v);
	}
}

VI pw;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	pw.push_back(1);
	FOR(i, 400000) pw.push_back((2*pw.back())%998244353);
	std::cin >> tests;
	while(tests--){
		std::cin >> n >> m;
		g = std::vector<VI>(n);
		FOR(i, m){
			int a, b;
			std::cin >> a >> b;
			a--;b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		vec = VI(n, -1);
		VI ans;
		bool bad = false;
		FOR(i, n){
			if(vec[i] == -1){
				cur = 0;
				vis = 0;
				vec[i] = 0;
				dfs(i);
				if(cur == -1){
					bad = true;
					break;
				}
				ans.push_back((pw[cur]+pw[vis-cur])%998244353);
			}
		}
		if(bad) std::cout << 0 << "\n";
		else{
			int fin = 1;
			TRAV(i, ans) fin = (1ll*fin*i)%998244353;
			std::cout << fin << "\n";
		}
	}
	return 0;
}