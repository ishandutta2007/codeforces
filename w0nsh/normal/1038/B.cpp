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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	if(n == 1 || n == 2) std::cout << "No", std::exit(0);
	std::cout << "Yes\n";
	VI A, B;
	REP(i, 1, n/2+1){
		if(i%2 == 1) A.push_back(i),A.push_back((n+1)-i);
	}
	REP(i, 1, n/2+1){
		if(i%2 == 0) B.push_back(i),B.push_back((n+1)-i);
	}
	if(n%2 != 0) B.push_back(n/2+1);
	std::cout << A.size() << " ";
	TRAV(i, A) std::cout << i << " ";
	std::cout << "\n";
	std::cout << B.size() << " ";
	TRAV(i, B) std::cout << i << " ";
	return 0;
}