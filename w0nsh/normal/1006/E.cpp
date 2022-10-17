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
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = a; i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, q;
std::vector<VI> g;
VI num, size, num_rev;

int tick = 0;
void dfs(int v, int parent=-1){
	num[v] = tick;
	num_rev[tick] = v;
	tick++;
	for(auto &ch : g[v]){
		if(ch == parent) continue;
		dfs(ch, v);
		size[v] += size[ch];
	}
}

void answer(int a, int b){
	if(size[a] < b) std::cout << -1 << "\n";
	else{
		b--;
		std::cout << num_rev[num[a]+b] +1 << "\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	g.resize(n);
	num.resize(n);
	num_rev.resize(n);
	size.resize(n, 1);
	FOR(i, n-1){
		int a;
		std::cin >> a;
		a--;
		g[a].push_back(i+1);
		g[i+1].push_back(a);
	}
	dfs(0);
	while(q--){
		int a, b;
		std::cin >> a >> b;
		answer(--a, b);
	}
	return 0;
}