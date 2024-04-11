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

int temp, sy, n, q, a, b, _sum[400010];
VI S;

inline int sum(int i, int j){
	return _sum[j+1] - _sum[i+1];
}

int main(){
	std::scanf("%d%d%d%d", &sy, &a, &b, &n);
	S.reserve(n*2+4);
	S.push_back(-1);
	S.push_back(-1);
	FOR(i, n*2) (std::scanf("%d", &temp)), S.push_back(temp);
	S.push_back(1000000666);
	S.push_back(1000000666);
	std::scanf("%d", &q);
	REP(i, 1, SZ(S)+1) _sum[i] = _sum[i-1] + (i % 2 == 0 ? S[i-1]-S[i-2] : 0);
//	REP(i, 0, SZ(S)+1) std::cout << _sum[i] << " ";
//	std::cout << "----\n";
	while(q--){
		int _x, _y;
		double x, y;
		std::scanf("%d%d", &_x, &_y);
		x = _x; y = _y;
		double start = ((y-sy)*x - (x-a)*y)/(y-sy);
		double end = ((y-sy)*x - (x-b)*y)/(y-sy);
		int l = (int)std::ceil(start);
		int r = (int)std::floor(end);
		double count = 0;
		int fl = std::distance(S.begin(), std::lower_bound(S.begin(), S.end(), l));
		int fr = std::distance(S.begin(), std::upper_bound(S.begin(), S.end(), r))-1;
//		std::cout << fl << " - " << fr << "   |    ";
		if(fl > fr){
			if(fr % 2 == 1) count = 0;
			else count = end - start;
		}else if(fl == fr){
			if(fr % 2 == 1) count = S[fr] - start;
			else count = end - S[fr];
		}else{
			count = sum(fl, fr);
//			std::cout << " sum=" << sum(fl, fr) << " ";
			if(fl % 2 == 1) count += S[fl] - start;
			if(fr % 2 == 0) count += end - S[fr];
		}
//		std::cout << count << " : " << std::fixed << std::setprecision(12) << count * (-sy/y+1.0) << "\n";
		std::printf("%.9f\n", count*(-sy/y+1.0));
	}
	return 0;
}