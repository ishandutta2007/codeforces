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
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = a; i < (b); ++i)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	std::cin >> str;
	if(str.find('0') == -1 || str.find('2') == -1) std::sort(str.begin(), str.end());
	else if(str.find('1') != -1){
		int zer_bef = 0;
		for(auto &ch : str){
			if(ch == '2') break;
			if(ch == '0') zer_bef++;
		}
		int ones = 0;
		for(auto &ch : str){
			if(ch == '1') ones++;
		}
		std::string sss;
		REP(i, str.find('2'), str.size()) if(str[i] != '1') sss.push_back(str[i]);
		str = std::string(zer_bef, '0') + std::string(ones, '1') + sss;
	}
	std::cout << str << "\n";
	return 0;
}