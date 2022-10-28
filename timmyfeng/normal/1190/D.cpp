#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	ordered_set vals;
	map<int, int> mp;
	for (auto& [y, x] : pts) {
		cin >> x >> y;
		vals.insert(x);
		++mp[x];
	}
	sort(pts.begin(), pts.end());

	int cur = 0;
	long long ans = 0;
	while (cur < n) {
		int lvl = pts[cur].first;
		vector<int> ndx = {-1};
		vector<int> must;

		while (cur < n && pts[cur].first == lvl) {
			ndx.push_back(vals.order_of_key(pts[cur].second));
			must.push_back(pts[cur].second);
			++cur;
		}
		ndx.push_back(vals.size());

		ans += 1LL * int(mp.size()) * int(mp.size() + 1u) / 2;

		for (int i = 1; i < int(ndx.size()); ++i) {
			int len = ndx[i] - ndx[i - 1] - 1;
			ans -= 1LL * len * (len + 1) / 2;
		}

		for (auto& i : must) {
			--mp[i];
			if (!mp[i]) {
				mp.erase(i);
				vals.erase(i);
			}
		}
	}
	cout << ans << "\n";
}