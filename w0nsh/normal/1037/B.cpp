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

int n, s, A[200005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> s;
	FOR(i, n) std::cin >> A[i];
	std::sort(A, A+n);
	int bigger = n;
	int smaller = -1;
	FOR(i, n){
		if(A[i] < s) smaller = i;
		else break;
	}
	for(int i = n-1; i >= 0; --i){
		if(A[i] > s) bigger = i;
		else break;
	}
	if(A[n/2] == s){
		std::cout << 0 << "\n";
		return 0;
	}
	ll ans1 = 0;
	int pos = smaller;
	while(pos >= n/2){
		ans1 += std::abs(1ll*A[pos]-s);
		pos--;
	}
	pos = bigger;
	while(pos <= n/2){
		ans1 += std::abs(1ll*A[pos]-s);
		pos++;
	}
	std::cout << ans1 << "\n";
	return 0;
}