#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
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

int n, ans;
bool visited[1005];
std::vector<std::vector<int> > G;

void dfs(int v){
	if(visited[v]) ans = v;
	if(ans != -1) return;
	visited[v] = true;
	TRAV(ch, G[v]){
		dfs(ch);
		if(ans != -1) return;
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	G.resize(n);
	FOR(i, n){
		int a;
		std::cin >> a;
		G[i].push_back(--a);
	}
	FOR(i, n){
		FOR(j, 1003) visited[j] = false;
		ans = -1;
		dfs(i);
		std::cout << ans+1 << "\n";
	}
	return 0;
}