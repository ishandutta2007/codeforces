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

int n, gc;
VI A;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	gc = A[0];
	REP(i, 1, n) gc = std::__gcd(gc, A[i]);
	if(gc > 1){
		std::cout << "YES\n0";
		return 0;
	}
	// FOR(i, n) A[i] /= gc;
	int cnt = 0;
	FOR(i, n-1){
		if(A[i] % 2 == 0 && A[i+1]%2 == 0) continue;
		if(A[i] % 2 == 1 && A[i+1]%2 == 1){
			cnt++;
			A[i] = 0;
			A[i+1] = 0;
			continue;
		}
	}
	FOR(i, n) if(A[i] % 2 == 1) cnt += 2;
	std::cout << "YES\n" << cnt;
	return 0;
}