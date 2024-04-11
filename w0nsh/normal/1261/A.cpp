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
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		auto get_close = [&](int pos, char what){
			REP(i, pos, n){
				if(s[i] == what) return i;
			}
			assert(false);
			return -1;
		};
		int pos = 0;
		std::vector<PII> ans;
		while(k > 1){
			int l = get_close(pos, '(');
			ans.push_back(MP(pos, l));
			std::reverse(s.begin()+pos, s.begin()+l+1);
			pos++;
			int r = get_close(pos, ')');
			ans.push_back(MP(pos, r));
			std::reverse(s.begin()+pos, s.begin()+r+1);
			pos++;
			k--;
		}
		int left = (n-pos)/2;
		FOR(i, left){
			int xd = get_close(pos, '(');
			ans.push_back(MP(pos, xd));
			std::reverse(s.begin()+pos, s.begin()+xd+1);
			pos++;
		}
		FOR(i, left){
			int xd = get_close(pos, ')');
			ans.push_back(MP(pos, xd));
			std::reverse(s.begin()+pos, s.begin()+xd+1);
			pos++;
		}
		assert(pos == n);
		std::cout << SZ(ans) << "\n";
		TRAV(i, ans){
			std::cout << i.X+1 << " " << i.Y+1 << "\n";
		}
	}
	return 0;
}