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

const int INF = 2000000666;
int n;
PR<PII, PII> sqr[132675];
PR<PII, PII> worst, bef;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	worst.first.X = worst.first.Y = -INF;
	worst.second.Y = worst.second.X = INF;
	bef = worst;
	FOR(i, n){
		std::cin >> sqr[i].X.X >> sqr[i].X.Y >> sqr[i].Y.X >> sqr[i].Y.Y;
		auto &s = sqr[i];
		if(s.first.X >= worst.first.X){
			bef.first.X = worst.first.X;
			worst.first.X = s.first.X;
		}else if(s.first.X >= bef.first.X) bef.first.X = s.first.X;
		if(s.first.Y >= worst.first.Y){
			bef.first.Y = worst.first.Y;
			worst.first.Y = s.first.Y;
		}else if(s.first.Y >= bef.first.Y) bef.first.Y = s.first.Y;
		if(s.second.X <= worst.second.X){
			bef.second.X = worst.second.X;
			worst.second.X = s.second.X;
		}else if(s.second.X <= bef.second.X) bef.second.X = s.second.X;
		if(s.second.Y <= worst.second.Y){
			bef.second.Y = worst.second.Y;
			worst.second.Y = s.second.Y;
		}else if(s.second.Y <= bef.second.Y) bef.second.Y = s.second.Y;
	}
	std::vector<int> xv;
	std::vector<int> yv;
	if(worst.first.Y > worst.second.Y){
		if(bef.first.Y != -INF) yv.push_back(bef.first.Y);
		if(bef.second.Y != INF) yv.push_back(bef.second.Y);
	}else yv.push_back(worst.first.Y);
	if(worst.first.X > worst.second.X){
		if(bef.first.X != -INF) xv.push_back(bef.first.X);
		if(bef.first.Y != INF) xv.push_back(bef.second.X);
	}else xv.push_back(worst.first.X);
	TRAV(x, xv) TRAV(y, yv){
		int bad = 0;
		FOR(i, n){
			if(sqr[i].X.X > x || sqr[i].Y.X < x || sqr[i].X.Y > y || sqr[i].Y.Y < y) bad++;
			if(bad > 1) break;
		}
		if(bad <= 1){
			std::cout << x << " " << y << "\n";
			return 0;
		}
	}
	std::cout << "XD";
	return 0;
}