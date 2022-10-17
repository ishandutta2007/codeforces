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
	std::string str;
	std::cin >> str;
	int n = SZ(str);
	ll ans = 1ll*n*(n+1)/2;
	FOR(i, n){
		int r = i;
		while(r < n){
			bool bad = false;
			REP(s, i, r-1){
				int k = 1;
				while(s+2*k <= r){
					if(str[s] == str[s+k] && str[s] == str[s+2*k]){
						bad = true;
						break;
					}
					k++;
				}
				if(bad) break;
			}
			if(bad) break;
			ans--;
			r++;
		}
	}
	std::cout << ans << "\n";
	return 0;
}