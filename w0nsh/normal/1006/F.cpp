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

const int NMAX = 22;

int n, m;
ll k;
int steps;
ll T[NMAX][NMAX];

void ctmap(std::map<ll, ll> map){
	for(auto pr : map){
		std::cout << pr.X << "," << pr.Y << " | ";
	}
	std::cout << "\n";
}

std::map<PII, std::map<ll, ll> > map, map2;

void dfs_f(int x, int y, int length, ll v){
	//if(length == (steps+1)/2) std::cout << "1 adding " << v << " do " << x << "," << y << std::endl;
	if(length == (steps+1)/2) map[MP(x, y)][v]++;
	else{
		if(x < n-1) dfs_f(x+1, y, length+1, v^T[x+1][y]);
		if(y < m-1) dfs_f(x, y+1, length+1, v^T[x][y+1]);
	}
}

void dfs_s(int x, int y, int length, ll v){
	//if(length == (steps)/2) std::cout << "2 adding " << v << " do " << x << "," << y << std::endl;
	if(length == (steps)/2) map2[MP(x, y)][v]++;
	else{
		if(x > 0) dfs_s(x-1, y, length+1, v^T[x][y]);
		if(y > 0) dfs_s(x, y-1, length+1, v^T[x][y]);
	}
}

void calculate(){
	if(n == 1 && m == 1){
		if(k == T[0][0]) std::cout << 1 << "\n";
		else std::cout << 0 << "\n";
		return;
	}
	steps = n+m-2;
	dfs_f(0, 0, 0, T[0][0]);
	dfs_s(n-1, m-1, 0, k);
	ll ans = 0;
	for(auto &pr : map){
		auto it = map2.find(pr.X);
		if(it != map2.end()){
			for(auto &kvp : pr.Y){
				auto jt = it->Y.find(kvp.X);
				if(jt != it->Y.end()) ans += jt->Y * kvp.Y;
			}
		}
	}
	std::cout << ans << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> k;
	FOR(i, n) FOR(j, m) std::cin >> T[i][j];
	calculate();
	return 0;
}