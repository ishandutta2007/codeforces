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

int los(int a, int b){
	return a + std::rand()%(b-a+1);
}

ll sa, sb;
int n;
VI A, B, P;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::srand(std::time(0));
	std::cin >> n;
	A.resize(n);
	B.resize(n);
	FOR(i, n) std::cin >> A[i], sa += A[i];
	FOR(i, n) std::cin >> B[i], sb += B[i];
	FOR(i, n) P.push_back(i);
	while(true){
		std::random_shuffle(P.begin(), P.end());
		ll a = 0;
		ll b = 0;
		FOR(i, n/2+1){
			a += A[P[i]];
			b += B[P[i]];
		}
		if(2ll*a > sa && 2ll*b > sb){
			std::cout << n/2+1 << "\n";
			FOR(i, n/2+1) std::cout << P[i]+1 << " ";
			return 0;
		}
	}
	return 0;
}