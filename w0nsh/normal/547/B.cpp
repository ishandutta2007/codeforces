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
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	std::vector<PII> val;
	FOR(i, n) val.push_back(MP(A[i], i));
	std::sort(val.begin(), val.end());

	std::multiset<int> sizes;
	std::set<int> set;
	set.insert(-1);
	set.insert(n);
	sizes.insert(n);

	VI ans(n+1, -1);

	TRAV(pr, val){
		ans[*std::prev(sizes.end())] = pr.X;

		auto it = set.lower_bound(pr.Y);
		auto prv = std::prev(it);
		sizes.erase(sizes.find(*it-*prv-1));
		sizes.insert(*it-pr.Y-1);
		sizes.insert(pr.Y-*prv-1);
		set.insert(pr.Y);
	}

	for(int i = n-1; i >= 0; --i) ans[i] = std::max(ans[i], ans[i+1]);

	FOR(i, n) std::cout << ans[i+1] << " ";


	return 0;
}