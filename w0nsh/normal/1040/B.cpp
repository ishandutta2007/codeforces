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

int n, k;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k;
	VI best;
	FOR(start, k+1){
		VI skew;
		int pos = start;
		int curk = k+1;
		while(pos < n){
			if(curk == k+1) skew.push_back(pos), pos += k, curk = 0;
			curk++;
			pos++;
		}
		if(curk != 1) continue;
		if(SZ(skew) == 0) skew.push_back(n/2);
		if(SZ(skew) < SZ(best) || SZ(best) == 0) best = skew;		
	}
	std::cout << SZ(best) << "\n";
	TRAV(i, best) std::cout << i+1 << "\n";
	return 0;
}