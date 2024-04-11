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
	std::string s;
	std::cin >> s;

	ll ans = 0;
	ll cur = 0;
	std::reverse(s.begin(), s.end());
	std::vector<PII> stack;

	auto add_stack = [&](int c, int ile){
		int mam = 0;
		while(SZ(stack) && stack.back().X <= c){
			mam += stack.back().Y;
			cur -= 1ll*stack.back().Y*stack.back().X;
			stack.pop_back();
		}
		stack.push_back(MP(c, mam+ile));
		cur += 1ll*stack.back().Y*stack.back().X;
	};

	auto add_cons = [&](int c){
		for(int i = c; i >= 1; --i){
			add_stack(i, 1);
		}
	};

	auto get = [&](int c){
		return 1ll*c*(c+1)/2;
	};

	int cons = 0;
	TRAV(c, s){
		if(c == '0'){
			if(cons > 0) add_cons(cons);
			cons = 0;
			add_stack(0, 1);
			ans += cur;
		}else{
			cons++;
			add_stack(cons, 0);
			ans += cur + get(cons);
		}
	}

	std::cout << ans << "\n";

	return 0;
}