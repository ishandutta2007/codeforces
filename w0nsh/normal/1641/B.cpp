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

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::map<int, int> cnt;
	TRAV(i, A) cnt[i]++;
	TRAV(pr, cnt) if(pr.Y % 2 == 1){
		std::cout << -1 << "\n";
		return;
	}
	cnt.clear();

	std::vector<PII> ans1;
	VI ans2;

	VI stack;
	int pos = 0;
	int i = 0;
	int zacz = -1;
	while(i < SZ(A)){
		stack.push_back(A[i]);
		pos++;
		if(A[i] == zacz){
			// std::cout << "stack tera ";
			// TRAV(j, stack) std::cout << j << " ";
			// std::cout << std::endl;

			REP(j, 1, SZ(stack)-1){
				ans1.push_back(MP(pos, stack[j]));
				pos++;
			}
			ans2.push_back(SZ(stack) * 2 - 2);

			stack.pop_back();
			std::reverse(stack.begin(), stack.end());
			stack.pop_back();

			auto cpy = A;
			A = stack;
			REP(j, i+1, SZ(cpy)) A.push_back(cpy[j]);
			i = 0;

			// TRAV(j, A) std::cout << j << " ";
			// std::cout << std::endl;
			// int none;
			// std::cin >> none;

			stack.clear();
			zacz = -1;
		}else{
			if(zacz == -1) zacz = A[i];
			++i;
		}
	}
	assert(stack.empty());

	std::cout << SZ(ans1) << "\n";
	TRAV(j, ans1) std::cout << j.X << " " << j.Y << "\n";
	std::cout << SZ(ans2) << "\n";
	TRAV(j, ans2) std::cout << j << " ";
	std::cout << "\n"; 
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}