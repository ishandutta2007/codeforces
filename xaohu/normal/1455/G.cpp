#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;

const ll INF = 1e18;

struct DP {
	map<int, ll> val;
	set <pair<ll, int>> s;
	ll off;
	DP() : val(), s(), off(0) {}
	
	ll get_val(int key) {
		if (val.find(key) == val.end()) return INF;
		return val[key] + off;
	}
	
	void set_val(int key, ll x) {
		ll cur = get_val(key);
		if (x < cur) {
			s.erase({cur - off, key});
			val[key] = x - off;
			s.insert({x - off, key});
		}
	} 
	
	void del(int key) {
		s.erase({get_val(key) - off, key});
		val.erase(key);
	}
	
	ll get_min() {
		if (s.empty()) return INF;
		return s.begin()->first + off;
	}	
};

DP* merge(DP* a, DP* b) {
	if (a->val.size() > b->val.size())
		swap(a, b);
	for (auto [key, val] : a->val) 
		b->set_val(key, a->get_val(key));
	return b;
}

int n, ban;

DP* solve(int st, ll up) {
	DP* dp = new DP;
	dp->set_val(st, up);
	while (n--) {
		string s;
		cin >> s;
		if (s[0] == 's') {
			int y, cost;
			cin >> y >> cost;
			ll mn = dp->get_min();
			dp->off += cost;
			if (y != ban)
				dp->set_val(y, mn);
		}
		if (s[0] == 'i') {
			int y;
			cin >> y;
			auto dp2 = solve(y, dp->get_val(y));
			dp->del(y);
			dp = merge(dp, dp2);
		}
		if (s[0] == 'e')
			return dp;
	}
	return dp;
}

int main() {
	cin >> n >> ban;
	auto res = solve(0, 0);
	cout << res->get_min();
	return 0;
}