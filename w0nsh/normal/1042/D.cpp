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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
std::pair<ll, int>,
null_type,
std::less<std::pair<ll, int> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int n;
ll t, A[200005];
std::pair<ll, ll> pref[200005];
ordered_set set;
std::map<ll, ll> ind;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> t;
	FOR(i, n) std::cin >> A[i];
	pref[0].X = 0;
	FOR(i, n){
		pref[i+1] = MP(pref[i].X + A[i], ++ind[pref[i].X+A[i]]);
		set.insert(pref[i+1]);
	}
	ll ms = 0;
	ll ans = 0;
	FOR(i, n){
		ans += set.order_of_key(MP(t-ms, -1));
		set.erase(pref[i+1]);
		ms -= A[i];
	}
	std::cout << ans << "\n";
	return 0;
}