#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef __gnu_pbds::tree<
int,
null_type,
std::less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n), p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] != a[v2] ? a[v1] < a[v2] : v1 > v2; });
	int q;
	std::cin >> q;
	std::vector<std::vector<std::pair<int, int>>> qries(n);
	for(int i = 0; i < q; i++) {
		int k, pos;
		std::cin >> k >> pos;
		qries[n-k].emplace_back(pos, i);
	}
	ordered_set st;
	for(int i = 0; i < n; i++) {
		st.insert(i);
	}
	std::vector<int> ans(q, -1);
	for(int i = 0; i < n; i++) {
		for(auto qry : qries[i]) {
			ans[qry.second] = *st.find_by_order(qry.first-1);
		}
		st.erase(p[i]);
	}
	for(int i = 0; i < q; i++) {
		std::cout << a[ans[i]] << '\n';
	}
}