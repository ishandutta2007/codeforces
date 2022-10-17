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

int n, cost[200005], A[200005], price[200005], which[200005], frind, ans;

int dfs(int v){
	which[v] = frind;
	if(A[v] == v){
		price[frind] = cost[v];
		ans += cost[v];
		return -1;
	}
	if(which[A[v]] == frind){
		price[frind] = cost[v];
		return A[v];
	}
	if(which[A[v]] != -1){
		price[frind] = price[which[A[v]]];
		return -1;
	}
	int ret = dfs(A[v]);
	if(ret != -1){
		price[frind] = std::min(price[frind], cost[v]);
		if(v == ret){
			ans += price[frind];
			return -1;
		}
		return ret;
	}
	return -1;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) which[i] = -1;
	FOR(i, n) std::cin >> cost[i];
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) A[i]--;
	FOR(i, n){
		if(which[i] == -1) dfs(i);
		frind++;
	}
	std::cout << ans << "\n";
	return 0;
}