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

int n, m, k, ans;
std::set<int> g[200005];
std::vector<PII> qr;
bool deleted[200005];

void check(int v){
	if(deleted[v] || g[v].size() >= k) return;
	deleted[v] = true;
	ans--;
	TRAV(i, g[v]) g[i].erase(v);
	TRAV(i, g[v]) check(i);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	ans = n;
	FOR(i, m){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		qr.push_back({a, b});
		g[a].insert(b);
		g[b].insert(a);
	}
	FOR(i, n) check(i);
	std::reverse(qr.begin(), qr.end());
	std::vector<int> ret;
	ret.push_back(ans);
	FOR(i, m-1){
		g[qr[i].X].erase(qr[i].Y);
		g[qr[i].Y].erase(qr[i].X);
		check(qr[i].X);
		check(qr[i].Y);
		ret.push_back(ans);
	}
	FOR(i, m) std::cout << ret[m-i-1] << "\n";
	return 0;
}