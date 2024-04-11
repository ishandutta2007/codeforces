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
std::string A, B;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> A >> B;
	std::string Acp = A;
	std::string Bcp = B;
	std::sort(Acp.begin(), Acp.end());
	std::sort(Bcp.begin(), Bcp.end());
	if(Acp != Bcp){
		std::cout << -1 << "\n";
		return 0;
	}
	std::vector<int> moves;
	FOR(i, n){
		int next = i;
		while(A[next] != B[i]) next++;
		for(int j = next-1; j >= i; --j){
			moves.push_back(j+1);
			std::swap(A[j], A[j+1]);
		}
	}
	std::cout << moves.size() << "\n";
	TRAV(i, moves) std::cout << i << " ";
	return 0;
}