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
std::vector<PII> A;

void f(int a, std::set<int> &set){
	int init = a;
	int div = 2;
	while(a > 1 && div*div <= init){
		if(a % div == 0) set.insert(div);
		while(a % div == 0) a /= div;
		div++;
	}
	if(a > 1) set.insert(a);
}

signed main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.reserve(n);
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back({a, b});
	}
	std::set<int> divs;
	f(A[0].X, divs);
	f(A[0].Y, divs);
	TRAV(d, divs){
		bool good = true;
		REP(i, 1, n){
			if(A[i].X % d != 0 && A[i].Y % d != 0){
				good = false;
				break;
			}
		}
		if(good){
			std::cout << d << "\n";
			return 0;
		}
	}
	std::cout << "-1\n";
	return 0;
}