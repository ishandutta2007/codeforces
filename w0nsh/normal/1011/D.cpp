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

int m, n, P[40];

int main(){
	std::scanf("%d%d", &m, &n);
	FOR(i, n){
		std::printf("%d\n", m);
		fflush(stdout);
		int odp;
		std::scanf("%d", &odp);
		if(odp == 0 || odp == -2) std::exit(0);
		if(odp == -1) P[i] = true;
	}
	int left = 1;
	int right = m-1;
	int which = 0;
	while(left <= right){
		int mid = (left+right)/2;
		int odp;
		std::printf("%d\n", mid);
		fflush(stdout);
		std::scanf("%d", &odp);
		if(odp == 0 || odp == -2) std::exit(0);
		if(!P[which%n]) odp *= -1;
		if(odp == -1) right = mid-1;
		else left = mid+1;
		which++;
	}
	std::printf("%d\n", left);
	fflush(stdout);
	return 0;
}