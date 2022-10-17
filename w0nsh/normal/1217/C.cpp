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
	int t;
	std::cin >> t;
	while(t--){
		std::string s;
		std::cin >> s;
		int	n = SZ(s);
		VI next(n+1, -1);
		for(int i = n-1; i >= 0; --i){
			if(s[i] == '1') next[i] = i;
			else next[i] = next[i+1];
		}
		int ans = 0;
		FOR(i, n){
			if(next[i] != -1){
				int l = i;
				int r = next[i];
				int num = 1;
				while(r < std::min(n, next[i]+22)){
					if(r-l+1 == num) ans++;
					r++;
					if(r == n) break;
					num <<= 1;
					if(s[r] == '1') num++;
				}
			}
		}
		std::cout << ans << "\n";
	}
	return 0;
}