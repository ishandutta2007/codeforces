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
	int my = 0;
	FOR(i, n) std::cin >> A[i];
	FOR(i, n) if(A[i] == -1) my = i;
	if(my == n-1) std::cout << 0;
	else{
		std::multiset<int> xd;
		ll ans = 0;
		int pos = n-1;
		ans += A[pos];
		int ile = n/2;
		while(true){
			FOR(i, ile){
				pos--;
				xd.insert(A[pos]);
				if(A[pos] == -1){
					std::cout << ans;
					return 0;
				}
			}
			ans += *xd.begin();
			xd.erase(xd.begin());
			ile /= 2;
		}
	}
	return 0;
}