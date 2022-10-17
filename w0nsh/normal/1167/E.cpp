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
	int n, x;
	std::cin >> n >> x;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::set<int> set;
	std::vector<PII> prze;
	for(int i = n-1; i >= 0; --i){
		if(!set.empty()){
			PII nw = MP(*set.begin(), A[i]);
			if(nw.X < nw.Y) prze.push_back(nw);
			auto it = set.lower_bound(A[i]);
			if(it != set.begin()){
				it--;
				prze.push_back(MP(*it, A[i]));
			}
		}
		set.insert(A[i]);
	}
	int end = x;
	int mx = 0;
	std::sort(prze.begin(), prze.end());
	TRAV(i, prze) end = std::min(end, i.Y), mx = std::max(mx, i.X);
	auto it = prze.begin();
	ll ans = 0;
	// TRAV(i, prze) std::cout << i.X << " " << i.Y << std::endl;
	REP(i, 1, end+1){
		while(it != prze.end() && it->X < i){
			mx = std::max(mx, it->Y);
			it++;
		}
		mx = std::max(mx, i);
		ans += x-mx+1;
		// std::cout << i << " " << mx << "+" << std::endl;
	}
	std::cout << ans;
	return 0;
}