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

int n, cur;
int ans = 1;
std::set<int> set;
const int MOD = 1000000007;
const int INF = 2000000666;
int main(){
	std::scanf("%d", &n);
	int lo = -1;
	int hi = -1;
	FOR(i, n){
		char q[10];
		std::scanf("%s%d", q, &cur);
		if(q[1] == 'C'){
			if(set.empty() || ((lo != -1 && cur < lo) || (hi != -1 && cur > hi))){
				std::printf("0\n");
				return 0;
			}
			//std::cout << "before: " << lo << " " << hi << std::endl;
			if(cur == lo || cur == hi){
			}else{
				ans *= 2;
				ans %= MOD;
			}
			set.erase(cur);
			if(!set.empty()){
				auto aft = set.lower_bound(cur);
				if(aft == set.begin()) lo = -1;
				else lo = *(std::next(aft, -1));
				if(aft == set.end()) hi = -1;
				else hi = *aft;
			}else{
				lo = hi = -1;
			}
			//std::cout << "after: " << lo << " " << hi << " ans: " << ans << std::endl;
		}else{
			set.insert(cur);
		}
	}
	int plus = 1;
	if(hi != lo || (lo == -1 && hi == -1)){
		auto it = (lo == -1 ? set.begin() : std::next(set.find(lo)));
		auto end = (hi == -1 ? set.end() : set.find(hi));
		while(it != end) plus++, it++;
	}
	//std::cout << "plus: " << plus <<  std::endl;
	std::printf("%d\n",(int)((1ll*ans*plus)%MOD));
	return 0;
}