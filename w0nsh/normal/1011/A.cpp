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

int n, k;
std::string str;
std::set<char> A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> str;
	for(auto ch : str) A.insert(ch);
	int odp = 0;
	char last = (char)(2);
	int cnt = 0;
	TRAV(c, A){
		if(c - last < 2) continue;
		odp += ((int)(c-'a'))+1;
		cnt++;
		last = c;
		if(cnt == k) break;
	}
	if(cnt < k) std::cout << -1 << std::endl;
	else std::cout << odp << std::endl;
	return 0;
}