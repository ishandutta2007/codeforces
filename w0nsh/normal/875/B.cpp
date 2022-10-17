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

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	VI P(n);
	FOR(i, n) std::cin >> P[i], P[i]--;
	std::set<int> white;
	FOR(i, n) white.insert(i);

	FOR(i, n){
		int nd = *std::prev(white.end());
		int mam = n-1-nd;

		std::cout << i+1-mam << " ";
		white.erase(P[i]);
	}

	std::cout << 1 << "\n";
	

	return 0;
}