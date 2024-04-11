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

int n, m;
std::unordered_map<int, int> map;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin  >> n >> m;
	if(m < n){
		std::cout << 0 << std::endl;
		return 0;
	}
	FOR(i, m){
		int a;
		std::cin >> a;
		map[a]++;
	}
	for(int odp = 10002; odp >= 1; odp--){
		int good = 0;
		TRAV(pr, map){
			good += pr.Y/odp;
			if(good >= n){
				std::cout << odp << "\n";
				return 0;
			}
		}
	}
	std::cout << 0 << "\n";
	return 0;
}