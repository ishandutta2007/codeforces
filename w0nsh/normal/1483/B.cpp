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
	std::set<int> bad;
	std::set<int> set;
	FOR(i, n) if(std::gcd(A[i], A[(i+1)%n]) == 1) bad.insert(i);
	FOR(i, n) set.insert(i);
	VI ans;
	auto pos = set.begin();
	while(SZ(bad) && SZ(set) > 1){

		// TRAV(i, bad) std::cout << i << " ";
		// std::cout << "  | ";
		// TRAV(i, set) std::cout << i << " ";
		// std::cout << std::endl;

		assert(SZ(set) > 1);

		auto it = bad.lower_bound(*pos);
		if(it == bad.end()) it = bad.begin();

		pos = set.find(*it);
		assert(pos != set.end());

		auto next = std::next(pos);
		if(next == set.end()) next = set.begin();

		ans.push_back(*next);
		bad.erase(it);
		if(SZ(set) == 2){
			set.erase(next);
			break;
		}
		if(bad.count(*next)) bad.erase(*next);
		set.erase(next);

		next = std::next(pos);
		if(next == set.end()) next = set.begin();

		if(std::gcd(A[*next], A[*pos]) == 1){
			bad.insert(*pos);
			pos = next;
		}
	}
	if(SZ(set) == 1 && A[*set.begin()] == 1) ans.push_back(*set.begin());
	std::cout << SZ(ans) << " ";
	TRAV(i, ans) std::cout << i+1 << " ";
	std::cout << "\n";
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}