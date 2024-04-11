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

int answer(int a){
	std::printf("! %d\n", a+1);
	std::exit(0);
}

int query(int a){
	std::printf("? %d\n", a+1);
	fflush(stdout);
	int ret;
	std::scanf("%d", &ret);
	return ret;
}

int place(int a){
	int x = query(a);
	int y = query(a+n/2);
	if(x-y == 0) answer(a);
	return x>y;
}


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::scanf("%d", &n);
	if(n%4 != 0) std::printf("! -1\n");
	else{
		int fs = query(0);
		int sc = query(n/2);
		if(fs == sc) answer(0);
		int left = 1;
		int right = n/2;
		while(left < right){
			int mid = (left+right)/2;
			if(place(mid) != (fs>sc)) right = mid;
			else left = mid+1;
		}
	}
	return 0;
}