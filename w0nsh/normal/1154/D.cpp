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

int n, b, a;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> b >> a;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	int ca = a;
	FOR(i, n){
		if(ca == 0 && b == 0){
			std::cout << i << "\n";
			return 0;
		}
		if(A[i] == 1){
			if(b > 0 && ca < a) b--, ca++;
			else ca--;
		}else{
			if(ca > 0) ca--;
			else b--;
		}
	}
	std::cout << n;
	return 0;
}