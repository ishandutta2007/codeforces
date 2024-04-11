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
#include <cmath>
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


std::vector<double> A, B;
double w;
int n;

bool check(double fuel){
	FOR(i, n){
		if(i != 0) fuel -= (w+fuel)/B[i];
		if(fuel < 0.0) return false;
		fuel -= (w+fuel)/A[i];
		if(fuel < 0.0) return false;
	}
	fuel -= (w+fuel)/B[0];
	if(fuel < 0.0) return false;
	return true;
}

void answer(){
	double left = 0.00000001;
	double right = 1000000000.00000001;
	double step = 0.00000001;
	while(left + 0.0000004 < right){
		double mid = left / 2.0 + right / 2.0;
		if(!check(mid)){
			left = mid + step;
		}else{
			right = mid - step;
		}
	}
	std::cout << std::fixed << std::setprecision(9) <<  left << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int temp;
	std::cin >> n >> temp;
	A.resize(n); B.resize(n);
	w = (double)temp;
	FOR(i, n){
		std::cin >> temp;
		A[i] = (double)temp;
	}
	FOR(i, n){
		std::cin >> temp;
		B[i] = (double)temp;
	}
	while(false){
		double xd;
		std::cin >> xd;
		std::cout << check(xd) << std::endl;
	}
	if(!check(1000000000.0000001)){
		std::cout << -1 << "\n";
		return 0;
	}
	answer();
	return 0;
}