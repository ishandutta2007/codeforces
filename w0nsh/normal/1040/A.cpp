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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, a, b;
	std::cin >> n >> a >> b;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	int cost = 0;
	for(int i = 0; i < n/2; ++i){
		if(A[i] == A[n-1-i] && A[i] == 2) cost += 2*std::min(a, b);
		else if(A[i] == A[n-1-i]) cost += 0;
		else if(A[i] == 2) cost += (A[n-1-i] == 0 ? a : b);
		else if(A[n-1-i] == 2) cost += (A[i] == 0 ? a : b);
		else{
			std::cout << -1 << "\n";
			return 0;
		}
	}
	if(n % 2 == 1 && A[n/2] == 2) cost += std::min(a, b);
	std::cout << cost << "\n";
	return 0;
}