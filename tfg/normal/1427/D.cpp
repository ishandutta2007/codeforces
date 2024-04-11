#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Group {
	int l, r, id;
	int size() { return r - l; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> wanted(n), a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		wanted[i] = i+1;
	}
	std::vector<std::vector<int>> ans;
	while(wanted != a) {
		std::vector<Group> groups;
		for(int l = 0, r = 0; l < n; l = r) {
			while(r < n && a[r] == a[l] + (r - l)) r++;
			Group cur;
			cur.l = a[l];
			cur.r = a[r-1]+1;
			cur.id = l;
			groups.push_back(cur);
		}
		int l = 0;
		std::vector<int> wtf;
		for(int i = 0; i < (int) groups.size(); i++) {
			for(int j = i+1; j < (int) groups.size(); j++) {
				if(groups[i].l == groups[j].r) {
					if(groups[i].id != l) wtf.push_back(groups[i].id - l);
					wtf.push_back(groups[j].id - groups[i].id);
					wtf.push_back(groups[j].size());
					l = groups[j].id + groups[j].size();
					i = j;
					break;
				}
			}
		}
		assert(l != 0);
		if(l != n) {
			wtf.push_back(n - l);
		}
		ans.push_back(wtf);
		std::vector<std::vector<int>> haha;
		l = 0;
		for(auto x : wtf) {
			std::vector<int> lul;
			assert(x > 0);
			while(x--) {
				assert(l < n);
				lul.push_back(a[l++]);
			}
			haha.push_back(lul);
		}
		assert(l == n);
		l = 0;
		std::reverse(haha.begin(), haha.end());
		for(auto v : haha) {
			for(auto x : v) {
				a[l++] = x;
			}
		}
	}
	assert((int) ans.size() <= n);
	std::cout << ans.size() << '\n';
	for(auto v : ans) {
		std::cout << v.size();
		for(auto x : v) {
			std::cout << ' ' << x;
		}
		std::cout << '\n';
	}
}