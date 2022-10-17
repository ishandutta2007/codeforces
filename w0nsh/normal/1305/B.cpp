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
	std::string s;
	std::cin >> s;
	int n = SZ(s);
	std::vector<bool> dead(n);
	std::vector<PR<VI, VI> > ans;
	while(true){
		VI pos;
		int l =0;
		int r = n-1;
		ans.emplace_back();
		while(l < r){
			while(l < r && dead[l]) l++;
			while(l < r && dead[r]) r--;
			if(l >= r) break;
			if(s[l] == '(' && s[r] == ')'){
				dead[l] = true;
				dead[r] = true;
				ans.back().X.push_back(l++);
				ans.back().Y.push_back(r--);
			}else{
				if(s[l] == ')') l++;
				if(s[r] == '(') r--;
			}
		}
		if(SZ(ans.back().X) == 0){
			ans.pop_back();
			break;
		}
	}
	std::cout << SZ(ans) << "\n";
	TRAV(i, ans){
		std::cout << SZ(i.X)+SZ(i.Y) << "\n";
		TRAV(j, i.X) std::cout << j+1 << " ";
		std::reverse(i.Y.begin(), i.Y.end());
		TRAV(j, i.Y) std::cout << j+1 << " ";
		std::cout << "\n";
	}

	return 0;
}