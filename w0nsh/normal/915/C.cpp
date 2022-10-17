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

std::string best;
std::string A, B;
int ila[11], ilb[11];

std::string get_greatest(){
	int ila_t[11];
	FOR(i, 11) ila_t[i] = ila[i];
	std::string ret = "";
	int pos = 9;
	while(pos >= 0){
		while(ila_t[pos]-- > 0) ret.push_back((char)('0'+pos));
		pos--;
	}
	return ret;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> A >> B;
	TRAV(c, A) ila[c-'0']++;
	TRAV(c, B) ilb[c-'0']++;
	if(B.size() > A.size()){
		std::cout << get_greatest();
		return 0;
	}
	best = A;
	std::sort(best.begin(), best.end());
	std::string have = "";
	FOR(i, (int)A.size()){
		int lower = -1;
		for(int j = (int)(B[i]-'0')-1; j >= 0; --j){
			if(ila[j] > 0){
				lower = j;
				break;
			}
		}
		if(i == 0 && lower == 0) lower = -1;
		if(lower != -1){
			std::string cand = have;
			cand.push_back('0' + lower);
			ila[lower]--;
			cand += get_greatest();
			ila[lower]++;
			if(cand > best && cand <= B) best = cand;
		}
		if(ila[B[i]-'0'] <= 0 && lower == -1) break;
		if(ila[B[i]-'0'] <= 0){
			have.push_back('0'+lower);
			ila[lower]--;
		}else{
			have.push_back(B[i]);
			ila[B[i]-'0']--;
		}
		if(i == (int) A.size() - 1 && have > best && have <= B) best = have;
	}
	std::cout << best << "\n";
	return 0;
}