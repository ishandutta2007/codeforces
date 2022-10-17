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

int n;
ll ans = 0;
ll min = 2000000666, max=-2000000666;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	ll a;
	if(n == 1){
		std::cin >> a;
		std::cout << a << "\n";
		return 0;
	}
	FOR(i, n) (std::cin >> a), min = std::min(min, a), max = std::max(max, a), ans += std::abs(a);
	if(min > 0) ans -= 2*min;
	if(max < 0) ans += 2*max;
	std::cout << ans << "\n";
	return 0;
}