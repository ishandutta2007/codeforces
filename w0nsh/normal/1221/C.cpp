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
	int q;
	std::cin >> q;
	while(q--){
		int c, m, x, c1, m1, x1;
		std::cin >> c1 >> m1 >> x1;
		int left = 0;
		int right = 1000000000;
		while(left < right){
			c = c1; m = m1; x = x1;
			int mid = (left+right)/2;
			bool bad = false;
			if(c < mid || m < mid) bad = true;
			x += c-mid;
			x += m-mid;
			if(x < mid) bad = true;
			if(bad) right = mid;
			else left = mid+1;
		}
		std::cout << left-1 << "\n";
		
	}
	
	return 0;
}