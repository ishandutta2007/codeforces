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

int n;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	if(n == 1){
		std::cout << 0 << "\n";
		return 0;
	}
	A.resize(2*n);
	FOR(i, n*2) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	ll best = 1ll*(A[n-1]-A[0])*(A[n*2-1]-A[n]);
	REP(i, 1, n){
		ll cand = A[i+n-1]-A[i];
		cand = cand * 1ll*(A[2*n-1]-A[0]);
		best = std::min(cand, best);
	}
	std::cout << best << "\n";
	return 0;
}