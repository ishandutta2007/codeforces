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
	std::map<int, int> A;
	FOR(i, n){
		int a;
		std::cin >> a;
		A[a]++;
	}
	int m;
	std::cin >> m;
	std::vector<PR<PII, int> > B;
	VI aud(m), sub(m);
	FOR(i, m) std::cin >> aud[i];
	FOR(i, m) std::cin >> sub[i];
	FOR(i, m){
		B.push_back(MP(MP(A[aud[i]], A[sub[i]]), i));
	}
	std::cout << std::max_element(B.begin(), B.end())->Y+1;

	return 0;
}