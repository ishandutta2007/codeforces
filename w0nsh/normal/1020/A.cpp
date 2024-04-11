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

int n, h, a, b, k;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> h >> a >> b >> k;
	FOR(i, k){
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		if(x1 == x2){
			std::cout << std::abs(y1 - y2) << "\n";
			continue;
		}
		int ans = std::abs(x1-x2);
		if(y1 < a && y2 < a) ans += std::abs(y1-a) + std::abs(y2-a);
		else if(y1 > b && y2 > b) ans += std::abs(y1-b) + std::abs(y2-b);
		else ans += std::abs(y1-y2);
		std::cout << ans << "\n";
	}
	return 0;
}