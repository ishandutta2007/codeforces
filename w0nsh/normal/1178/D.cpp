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

bool xd(){
	std::vector<bool> prime(500005, true);
	prime[0] = prime[1] = false;
	REP(i, 2, 500005){
		if(prime[i]){
			for(ll j = 1ll*i*i; j < 500005; j += i){
				prime[j] = false;
			}
		}
	}
	REP(n, 3, 10000){
		std::vector<PII> edges;
		FOR(i, n) edges.push_back(MP(i, (i+1)%n));
		int pos = 0;
		while(pos < n/2 && !prime[SZ(edges)]){
			edges.push_back(MP(pos, n/2+pos));
			pos++;
		}
		if(!prime[SZ(edges)]){
			std::cout << n << "BAD";
			return false;
		}
	}
	return true;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	// xd();
	int n;
	std::cin >> n;
	std::vector<bool> prime(500005, true);
	prime[0] = prime[1] = false;
	REP(i, 2, 500005){
		if(prime[i]){
			for(ll j = 1ll*i*i; j < 500005; j += i){
				prime[j] = false;
			}
		}
	}
	std::vector<PII> edges;
	FOR(i, n) edges.push_back(MP(i, (i+1)%n));
	int pos = 0;
	while(pos < n/2 && !prime[SZ(edges)]){
		edges.push_back(MP(pos, n/2+pos));
		pos++;
	}
	if(!prime[SZ(edges)]) std::cout << -1;
	else{
		std::cout << SZ(edges) << "\n";
		TRAV(i, edges){
			std::cout << i.X+1 << " " << i.Y+1 << "\n";
		}
	}
	return 0;
}