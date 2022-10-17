#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
std::less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;
//X.find_by_order(k); - zwraca iterator na k-ty element (numeracja od zerowego)
//X.order_of_key(k); - zwraca liczb elementw ostro mniejszych ni k

const int INF = 1000000666;

void add(PII p, ordered_set<PII> &set, PII &added, std::vector<PII> &remd){
	auto it = set.lower_bound(MP(p.X, -INF));
	if(it != set.begin()){
		it--;
		auto next = std::next(it);
		if(it->Y >= p.X){
			p.X = it->X;
			p.Y = std::max(it->Y, p.Y);
			remd.push_back(*it);
			set.erase(it);
		}
		it = next;
	}
	while(it != set.end() && it->X <= p.Y){
		remd.push_back(*it);
		p.Y = std::max(p.Y, it->Y);
		auto next = std::next(it);
		set.erase(it);
		it = next;
	}
	added = p;
	set.insert(p);
}

void restore(ordered_set<PII> &set, PII &added, std::vector<PII> &remd){
	set.erase(added);
	TRAV(i, remd) set.insert(i);
}

int check(ordered_set<PII> &a, ordered_set<PII> &b){
	int ans = SZ(a) + SZ(b);
	if(SZ(a) == 0) return ans;
	int upto = std::prev(a.end())->Y;
	return ans - b.order_of_key(PII(upto+1, -INF));
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::vector<PII> A;
		FOR(i, n){
			int a, b;
			std::cin >> a >> b;
			A.push_back(MP(a, b));
		}
		std::sort(A.begin(), A.end());
		std::vector<std::vector<PII> > remd(n+1);
		std::vector<PII> added(n+1);
		ordered_set<PII> lset;
		ordered_set<PII> rset;
		for(int i = n-1; i >= 0; --i){
			add(A[i], rset, added[i], remd[i]);
		}
		int ans = 0;
		FOR(i, n){
			restore(rset, added[i], remd[i]);
			ans = std::max(ans, check(lset, rset));
			add(A[i], lset, added.back(), remd.back());
		}
		std::cout << ans << "\n";
	}
	return 0;
}