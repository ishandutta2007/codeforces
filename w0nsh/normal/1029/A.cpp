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
std::string A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> A;
	int suf = -1;
	for(int i = n-1; i > 0; --i){
		bool good = true;
		int pos = 0;
		REP(j, i, n){
			if(A[j] != A[pos++]){
				good = false;
				break;
			}
		}
		if(good) suf = i;
	}
	if(suf == -1){
		FOR(i, k) std::cout << A;
	}else{
		std::cout << A;
		std::string sub = "";
		REP(i, n-suf, n) sub.push_back(A[i]);
		FOR(i, k-1){
			std::cout << sub;
		}
	}
	return 0;
}