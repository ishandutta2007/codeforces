#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
 
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::cin >> n >> m;
		VI ile(m);
		FOR(i, n){
			int a;
			std::cin >> a;
			a--;
			ile[a]++;
		}
		std::queue<int> prices;
		ll ans = 0;
		VI price(m);
		FOR(i, m){
			std::cin >> price[i];
		}
		VI rev = price;
		std::reverse(rev.begin(), rev.end());
		for(int i = m-1; i >= 0; --i){
			while(ile[i]){
				if(SZ(rev) && rev.back() < price[i]){
					ans += rev.back();
					rev.pop_back();
				}else{
					ans += price[i];
				}
				ile[i]--;
			}
		}
		std::cout << ans << "\n";
	}
	return 0;
}