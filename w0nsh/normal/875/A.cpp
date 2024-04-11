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
	VI ans;
	FOR(i, 20000){
		int x = n-i;
		if(x <= 0) break;
		int sm = 0;
		int c = x;
		while(c > 0) sm += c%10, c /= 10;
		if(x + sm == n) ans.push_back(x);
	}

	std::reverse(ans.begin(), ans.end());
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans) std::cout << i << " ";

	return 0;
}