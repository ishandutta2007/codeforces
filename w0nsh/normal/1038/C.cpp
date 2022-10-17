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
VI A, B;
std::vector<PII> vec;
ll sc[2];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int a;
	FOR(i, n) (std::cin >> a), vec.push_back({a, 0});
	FOR(i, n) (std::cin >> a), vec.push_back({a, 1});
	std::sort(vec.begin(), vec.end());
	int turn = 0;
	while(!vec.empty()){
		auto cur = vec.back();
		vec.pop_back();
		if(turn == cur.Y) sc[turn] += cur.X;
		turn = (turn+1)%2; 
	}
	std::cout << sc[0]-sc[1] << "\n";
	return 0;
}