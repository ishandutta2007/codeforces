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

int n, x;
std::set<int> set;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> x;
	FOR(i, n){
		int a;
		std::cin >> a;
		if(set.find(a) != set.end()){
			std::cout << 0 << "\n";
			return 0;
		}
		set.insert(a);
	}
	std::set<int> set1 = set;
	std::set<int> set2;
	auto it = set.begin();
	auto it1 = set1.begin();
	FOR(i, set1.size()){
		auto nxt = std::next(it, 1);
		set.erase(it);
		if(set.find(*it1 & x) != set.end()){
			std::cout << 1 << "\n";
			return 0;
		}
		set.insert(*it1);
		set2.insert(*it1 & x);
		it = nxt;
		it1++;
	}
	if(set2.size() < set1.size()) std::cout << 2 << "\n";
	else std::cout << -1 << "\n";

	return 0;
}