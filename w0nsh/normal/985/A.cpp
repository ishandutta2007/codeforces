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

int n, temp;
std::vector<int> pieces;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n/2) (std::cin >> temp), (pieces.push_back(--temp));
	std::sort(pieces.begin(), pieces.end());
	int d1 = 0;
	int d2 = 0;
	FOR(i, n/2){
		d1 += std::abs(pieces[i] - i*2);
		d2 += std::abs(pieces[i] - (i*2 + 1));
	}
	std::cout << std::min(d1, d2) << "\n";
	return 0;
}