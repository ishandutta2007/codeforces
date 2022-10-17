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
		int n, d;
		std::cin >> n >> d;
		int left = 0;
		int right = d;
		while(left < right){
			int x = (left+right)/2;
			if(x >= (d+x)/(x+1)) right = x;
			else left = x+1;
		}
		int mn = std::min(left+(d+left)/(left+1), (left-1)+(d+left-1)/left);
		std::cout << (mn <= n ? "YES\n" : "NO\n");
	}
	
	return 0;
}