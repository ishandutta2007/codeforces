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

VI ind;
int n, k;
int frind;
std::stack<int> stack;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> n >> k >> str;
	FOR(i, n){
		if(str[i] == '('){
			stack.push(frind);
			ind.push_back(frind);
			frind++;
		}else{
			ind.push_back(stack.top());
			stack.pop();
		}
	}
	int remove = (n-k)/2;
	FOR(i, n){
		if(ind[i] >= remove) std::cout << str[i];
	}
	std::cout << "\n";
	return 0;
}