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

const int N = 100005;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::vector<std::vector<PII> > F(n);
	FOR(a, n){
		int cur = A[a];
		for(int i = 2; i*i <= A[a]; ++i){
			if(cur%i == 0){
				int pot = 0;
				while(cur%i == 0){
					cur /= i;
					pot++;
				}
				if(pot%k != 0) F[a].push_back(MP(i, pot%k));
			}
		}
		if(cur > 1) F[a].push_back(MP(cur, 1));
	}
	std::map<std::vector<PII>, int> map;
	ll ans = 0;
	FOR(i, n){
		std::vector<PII> vec;
		TRAV(j, F[i]) vec.push_back(MP(j.X, k-j.Y));
		ans += map[vec];
		map[F[i]]++;
	}
	std::cout << ans;
	return 0;
}