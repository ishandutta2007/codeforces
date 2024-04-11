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
std::vector<bool> A;
std::string str;

void answer(std::vector<bool> &vec){
	int best = 0;
	int cur = 1;
	REP(i, 1, SZ(vec)){
		if(vec[i] != vec[i-1]) cur++;
		else{
			best = std::max(best, cur);
			cur = 1;
		}
	}
	std::cout << std::max(cur, best) << "\n";
	std::exit(0);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> str;
	n = SZ(str);
	FOR(i, n) A.push_back(str[i] == 'b');
	if(A[0] == A.back()) answer(A);
	REP(i, 1, n){
		if(A[i] == A[i-1]){
			std::reverse(A.begin(), std::next(A.begin(), i));
			std::reverse(std::next(A.begin(), i), A.end());
			break;
		}
	}
	answer(A);
	return 0;
}