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
bool A[1000005], B[1000005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n){
		char t;
		std::cin >> t;
		if(t == '1') A[i] = true;
	}
	FOR(i, n){
		char t;
		std::cin >> t;
		if(t == '1') B[i] = true;
	}
	int cost = 0;
	FOR(i, n){
		if(A[i] == B[i]) continue;
		if(i < n-1 && A[i+1] != B[i+1] && A[i] != A[i+1]) i++;
		cost++;
	}
	std::cout << cost << "\n";
	return 0;
}