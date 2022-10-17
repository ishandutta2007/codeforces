#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
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
	FOR(i, n){
		std::cin >> A[i];
	}

	VI ile(20);

	FOR(i, n){
		FOR(j, 20){
			if(A[i]& (1<<j)) ile[j]++;
		}
	}

	ll ans = 0;
	FOR(i, n){
		int cur = 0;
		FOR(j, 20){
			if(ile[j] > 0){
				cur |= (1<<j);
				ile[j]--;
			}
		}

		ans += 1ll*cur*cur;
	}

	std::cout << ans;

	return 0;
}