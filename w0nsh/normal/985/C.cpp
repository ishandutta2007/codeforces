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

int n, k, l;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> l;
	A.resize(n*k);
	FOR(i, n*k) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	int upr = std::distance(A.begin(), std::upper_bound(A.begin(), A.end(), A[0]+l));
	if(upr < n){
		std::cout << 0 << "\n";
		return 0;
	}
	int min_pos = upr-1;
	ll have = 0;
	FOR(i, n){
		int cur = 1;
		int min = A[min_pos--];
		while(cur < k && upr < n*k){
			upr++;
			cur++;
		}
		while(cur < k){
			min = A[min_pos--];
			cur++;
		}
		have += min;
	}
	std::cout << have << "\n";
	return 0;
}