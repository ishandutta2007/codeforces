#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
    T, __gnu_pbds::null_type, Comp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, d; cin >> n >> d;

	int answer = 0;
	vector<pair<int, int>> normal, reversed;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		if (l >= d && r <= d) {
			answer += 1;
		} else if (r < l) {
			normal.push_back({r, r});
			reversed.push_back({r, l});
		} else {
			normal.push_back({l, r});
		}
	}
	sort(reversed.begin(), reversed.end());

	vector<pair<int, int>> points;
	for (int i = 0; i < (int) normal.size(); ++i) {
		auto [l, r] = normal[i];
		if (l < r) {
			points.push_back({l + 1, ~i});
			points.push_back({r, i});
		}
	}
	sort(points.begin(), points.end());

	int reversed_it = 0;
	vector<int> weight(normal.size());
	ordered_set<pair<int, int>> nums;
	for (auto [x, i] : points) {
		while (reversed_it < (int) reversed.size() && reversed[reversed_it].first < x) {
			auto [l, r] = reversed[reversed_it++];
			nums.insert({r, reversed_it});
		}

		if (i < 0) {
			weight[~i] -= nums.size() - nums.order_of_key({normal[~i].second, -1});
		} else {
			weight[i] += nums.size() - nums.order_of_key({x, -1});
		}
	}

	vector<int> order(normal.size());
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {
		return normal[a] < normal[b];
	});

	map<int, int> prefix_max = {{d, 0}};
	for (auto i : order) {
		auto [l, r] = normal[i];
		int w = weight[i] + 1;

		if (l < d) continue;

		auto it = --prefix_max.upper_bound(l);
		int new_value = it->second + w;

		it = --prefix_max.upper_bound(r);
		if (it->second > new_value) continue;

		while (true) {
			it = prefix_max.upper_bound(r);
			if (it == prefix_max.end() || it->second > new_value)
				break;
			prefix_max.erase(it);
		}

		prefix_max[r] = new_value;
	}

	answer += prefix_max.rbegin()->second;

	cout << answer << "\n";
}