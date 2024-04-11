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

const int INF = 1000000666;

std::vector<PII> A;


std::map<int, int> map;
ordered_set<int> set;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	FOR(i, n){
		int a, b;
		std::cin >> a >> b;
		A.push_back(MP(b, a));
		set.insert(a);
		map[a]++;
	}
	std::sort(A.begin(), A.end());
	ll ans = 0;
	auto it = A.begin();
	while(it != A.end()){
		int y = it->X;
		VI xy;
		xy.push_back(-INF);
		while(it != A.end() && it->X == y){
			xy.push_back(it->Y);
			map[it->Y]--;
			if(map[it->Y] == 0) set.erase(it->Y);
			it++;
		}
		xy.push_back(INF);
		VI sz;
		int sum = 0;
		FOR(i, SZ(xy)-1){
			sz.push_back(set.order_of_key(xy[i+1]) - set.order_of_key(xy[i]+1)+1);
			sum += sz.back();
		}
		FOR(i, SZ(sz)){
			sum -= sz[i];
			ans += 1ll*sum*sz[i];
		}
	}
	std::cout << ans << "\n";

	return 0;
}