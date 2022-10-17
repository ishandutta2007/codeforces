#include <algorithm>
#include <bitset>
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

int n, A[200005], level[200005], at_level[200005], place[200005];
bool used[200005];
std::vector<std::vector<int> > g;

void answer(bool what){
	if(what) std::cout << "Yes\n";
	else std::cout << "No\n";
	std::exit(0);
}

void dfs(int v, int lvl, int parent){
	level[v] = lvl;
	at_level[lvl]++;
	TRAV(ch, g[v]){
		if(ch == parent) continue;
		dfs(ch, lvl+1, v);
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		b--;a--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	FOR(i, n){
		int a;
		std::cin >> a;
		A[i] = a-1;
		place[A[i]] = i;
	}
	if(A[0] != 0) answer(false);
	dfs(0, 0, -1);
	int cur_level = 0;
	int place_at_next = 1;
	int left = 1;
	FOR(i, n){
		if(level[A[i]] != cur_level) answer(false);
		TRAV(ch, g[A[i]]){
			if(level[ch] < level[A[i]]) continue;
			//std::cout << ch+1 << " od " << place_at_next+1 << " do " << place_at_next + g[A[i]].size()-(i==0?0:1) << " a jest " << place[ch]+1 << "\n";
			if(place[ch] < place_at_next || place[ch] >= place_at_next + g[A[i]].size() - (i==0?0:1)) answer(false);
		}
		place_at_next += g[A[i]].size();
		if(A[i] != 0) place_at_next--;
		//std::cout << "byl " << A[i]+1 << " place next = " << place_at_next+1 << "\n";
		left--;
		if(left == 0){
			cur_level++;
			left = at_level[cur_level];
			if(left == 0) break;
		}
	}
	answer(true);
	return 0;
}