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

ll left = 1, right, n, k;

int los(int a, int b){
	return std::rand()%(b-a+1);
}

bool query(ll a, ll b){
	std::cout << a << " " << b << "\n";
	std::cout.flush();
	std::string str;
	std::cin >> str;
	if(str[0] == 'Y'){
		if(a == b) std::exit(0);
		return true;
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 10000);
	std::cin >> n >> k;
	right = n+1;
	while(true){
		ll mid = (right+left)/2ll;
		if(query(left, mid)){
			right = mid;
		}else{
			left = mid+1;
		}
		right = std::min(n+1, right+k);
		left = std::max(1ll, left-k);
		if(right - left < 50ll){
			ll qr = left + dis(gen)%(std::max(1, (int)(right - left)));
			query(qr, qr);
			left = std::max(1ll, left-k);
			right = std::min(n+1, right+k);
		}
	}
	return 0;
}