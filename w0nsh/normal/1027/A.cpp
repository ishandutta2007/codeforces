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

int t, n;
std::string str;

void answer(bool what){
	if(what) std::cout << "YES\n";
	else std::cout << "NO\n";
}

bool check(char a, char b){
	char m[4];
	m[0] = a+1;
	m[1] = a-1;
	m[2] = b-1;
	m[3] = b+1;
	FOR(i, 2) REP(j, 2, 4){
		if(m[i] == m[j] && m[i] >= 'a' && m[i] <= 'z') return true;
	}
	return false;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> t;
	while(t--){
		std::cin >> n >> str;
		bool good = true;
		FOR(i, n/2){
			if(!check(str[i], str[n-1-i])){
				good = false;
				break;
			}
		}
		if(good) answer(true);
		else answer(false);
	}
	return 0;
}