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
	int n, m;
	std::cin >> n >> m;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	std::vector<ll> add(m);
	ll sum = 0;
	FOR(i, n){
		if(i%m == 0){
			FOR(j, m) add[j] += (i+j >= n ? 0 : A[i+j]);
		}
		sum += add[i%m];
		std::cout << sum << " ";
	}
	return 0;
}