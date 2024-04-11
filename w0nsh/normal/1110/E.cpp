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

int n;
VI A, B;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	int last = 0;
	FOR(i, n){
		int a;
		std::cin >> a;
		A.push_back(a-last);
		last = a;
	}
	last = 0;
	FOR(i, n){
		int a;
		std::cin >> a;
		B.push_back(a-last);
		last = a;
	}
	if(B[0] != A[0]) std::cout << "No\n";
	else{
		std::sort(A.begin(), A.end());
		std::sort(B.begin(), B.end());
		FOR(i, n) if(A[i] != B[i]){
			std::cout << "No\n";
			return 0;
		}
		std::cout << "Yes\n";
	}
	return 0;
}