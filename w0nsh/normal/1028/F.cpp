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

int n, all;
std::map<ll, std::set<PII> > map;
std::map<PR<int, int>, int> ans;

PII get_mid(int x1, int y1, int x2, int y2){
	PII mid = {x1+x2, y1+y2};
	return {mid.X/std::__gcd(mid.X, mid.Y), mid.Y/std::__gcd(mid.X, mid.Y)};
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	while(n--){
		int t, x, y;
		std::cin >> t >> x >> y;
		ll dist = 1ll*x*x+1ll*y*y;
		if(t == 1){
			all++;
			TRAV(i, map[dist]){
				auto mid = get_mid(x, y, i.X, i.Y);
				ans[mid] += 2;
			}
			map[dist].insert({x, y});
			ans[get_mid(x, y, x, y)]++;
		}else if(t == 2){
			all--;
			map[dist].erase({x, y});
			ans[get_mid(x, y, x, y)]--;
			TRAV(i, map[dist]){
				auto mid = get_mid(x, y, i.X, i.Y);
				ans[mid] -= 2;
			}
		}else std::cout << all - ans[MP(x/std::__gcd(x, y), y/std::__gcd(x, y))] << "\n";
	}
	return 0;
}