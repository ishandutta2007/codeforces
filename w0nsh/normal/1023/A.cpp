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
std::string A, B;

void answer(bool what){
	if(what) std::cout << "YES\n";
	else std::cout << "NO\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m >> A >> B;
	int plc = A.find('*');
	if(plc == -1){
		if(A != B) answer(false);
		else answer(true);
	}
	if(n - 1 > m) answer(false);
	FOR(i, plc){
		if(i >= m || A[i] != B[i]) answer(false);
	}
	for(int i = 0; A[n-i-1] != '*'; i++){
		if(m-i-1 < 0 || A[n-i-1] != B[m-i-1]) answer(false);
	}
	answer(true);
	return 0;
}