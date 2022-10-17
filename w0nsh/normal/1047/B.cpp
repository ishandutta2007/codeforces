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

int n, A[100005], B[100005];

bool check(unsigned what){
	FOR(i, n) if(A[i] + B[i] > what) return false;
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, n) std::cin >> A[i] >> B[i];
	unsigned left = 0;
	unsigned right = 2000000006;
	while(left < right){
		unsigned mid = (left+right)/2;
		if(!check(mid)) left = mid+1;
		else right = mid;
	}
	std::cout << left << "\n";
	return 0;
}