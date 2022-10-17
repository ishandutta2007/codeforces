#include <bits/stdc++.h>
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

const int INF = 1000000000;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	if(A[0] == A.back()){
		std::cout << 0;
		return 0;
	}
	int min = INF;
	int add = (A.back()-A[0])/2;
	int want = A[0]+add;
	bool good = true;
	FOR(i, n){
		if(A[i] + add == want || A[i] == want || A[i] - add == want){}
		else good = false; 
	}
	if(good) min = std::min(min, add);
	good = true;
	add = A.back()-A[0];
	FOR(i, n){
		if(A[i] == A[0] || A[i] == A.back()){}
		else good= false;
	}
	if(good) min = std::min(min, add);
	std::cout << (min == INF ? -1 : min);
	return 0;
}