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

int q;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> q;
	while(q--){
		ll x, y, k;
		std::cin >> x >> y >> k;
		if(x == y && x+1 == k){
			std::cout << k-2 << "\n";
			continue;
		}
		ll cnt = 0;
		ll diag = std::min(x, y);
		ll left = std::max(x-diag, y-diag);
		if(k < diag + left){
			std::cout << -1 << "\n";
		}else{
			ll moves = k - diag;
			if(left % 2 == 0){
				if(moves % 2 == 0) std::cout << k << "\n";
				else std::cout << diag + moves - 2 << "\n";
			}else{
				std::cout << diag + moves - 1 << "\n";
			}
		}
	}
	return 0;
}