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


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	int uniq = 1;
	FOR(i, n-1){
		if(A[i] != A[i+1]) uniq++;
	}
	if(uniq == 2 && A[n/2] != A[n/2-1]) std::cout << "YES\n" << A[0] << " " << A[n-1] << "\n";
	else std::cout<< "NO\n";
	return 0;
}