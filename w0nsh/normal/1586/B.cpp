#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
int n, m;
	std::cin >> n >> m;
	std::vector<bool> was(n);
	FOR(i, m){
		int a, b, c;
		std::cin >> a >> b >> c;
		was[b-1] = true;
	}

	int co = -1;
	FOR(i, n) if(!was[i]) co = i;
	FOR(i, n){
		if(i != co){
			std::cout << co+1 << " " << i+1 << "\n";
		}
	}

	}
	
	return 0;
}