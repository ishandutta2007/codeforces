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

int get(std::vector<bool> vec){
	int sa = 0;
	int sb = 0;
	FOR(i, 5){
		int ia = i*2;
		int ib = i*2+1;

		if(vec[ia]) sa++;
		int moga = sa + 5-1-i;
		int mogb = sb + 5-i; 
		if(moga < sb || mogb < sa) return ia;

		if(vec[ib]) sb++;
		moga = sa + 5-1-i;
		mogb = sb + 5-1-i;
		if(moga < sb || mogb < sa) return ib;
	}
	return 9;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		std::string s;
		std::cin >> s;

		int cnt = 0;
		TRAV(i, s) if(i == '?') cnt++;

		int ans = 9;
		FOR(mask, 1<<cnt){
			int kt = 0;
			std::vector<bool> vec(10);
			FOR(i, 10){
				if(s[i] == '?'){
					vec[i] = (bool)(mask & (1<<kt));
					kt++;
				}else if(s[i] == '1') vec[i] = true;
				else vec[i] = false;
			}

			ans = std::min(ans, get(vec));
		}
		std::cout << ans+1 << "\n";
	}

	return 0;
}