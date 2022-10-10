#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <map>
#include <queue>
#include <cassert>

#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<
int,
null_type,
std::less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	std::set<int> pos;
	pos.insert(0);
	pos.insert(n + 1);
	std::priority_queue<std::pair<int, int>> hp;
	hp.push({n, 1});
	ordered_set ord;
	std::map<int, int> hmm;
	while(q--) {
		int t;
		std::cin >> t;
		//std::cout << "type " << t << std::endl;
		if(t == 0) {
			int l, r;
			std::cin >> l >> r;
			l--;
			std::cout << ord.order_of_key(r+1) - ord.order_of_key(l+1) << '\n';
		} else if(hmm.count(t)) {
			int on = hmm[t];
			hmm.erase(t);
			ord.erase(on);
			pos.erase(on);
			auto itr = pos.lower_bound(on);
			auto itl = itr;
			itl--;
			hp.push({*itr - *itl - 1, *itl + 1});
		} else {
			while(!hp.empty()) {
				auto l = hp.top().second;
				auto r = hp.top().first + l;
				auto it = pos.lower_bound(l);
				if(*it < r) {
					hp.pop();
				} else {
					break;
				}
			}
			assert(!hp.empty() && hp.top().first > 0);
			auto l = hp.top().second;
			auto r = hp.top().first + l;
			int mid = (l + r) / 2;
			auto itr = pos.lower_bound(l);
			auto itl = itr;
			itl--;
			hp.push({mid - *itl - 1, *itl + 1});
			hp.push({*itr - mid - 1, mid + 1});
			pos.insert(mid);
			ord.insert(mid);
			hmm[t] = mid;
		}
	}
}