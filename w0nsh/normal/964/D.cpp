#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>

int n;
VI ans, pre, post;
std::vector<VI> g;

int subsize(int v){
	return (post[v]-pre[v]+1)/2;
}

int _tick = 0;
void dfs0(int v, int par=-1){
	pre[v] = _tick++;
	TRAV(ch, g[v]) if(ch != par) dfs0(ch, v);
	post[v] = _tick++;
}

void dfs1(int v, int par=-1){
	if(SZ(g[v]) == 1 && g[v][0] == par) ans.push_back(v);
	else{
		TRAV(ch, g[v]) if(ch != par && subsize(ch) % 2 == 0) dfs1(ch, v);
		ans.push_back(v);
		TRAV(ch, g[v]) if(ch != par && subsize(ch) % 2 == 1) dfs1(ch, v);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	pre.resize(n);
	post.resize(n);
	FOR(i, n){
		int a;
		std::cin >> a;
		a--;
		if(a != -1){
			g[a].push_back(i);
			g[i].push_back(a);
		}
	}
	if(n == 1) std::cout << "YES\n1\n";
	else if(n % 2 == 0) std::cout << "NO\n";
	else{
		dfs0(0);
		dfs1(0);
		std::cout << "YES\n";
		TRAV(i, ans) std::cout << i+1 << "\n";
	}
	return 0;
}