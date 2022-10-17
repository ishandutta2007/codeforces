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

#define int long long

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int k, n, s, p;
	std::cin >> k >> n >> s >> p;
	int left = 0;
	int right = 1000000000;
	while(left < right){
		int mid = (left + right)/2;
		int have = p*mid;
		int every = have/k;
		if(every*s < n){
			left = mid+1;
		}else{
			right = mid;
		}
	}
	std::cout << left << "\n";
	return 0;
}