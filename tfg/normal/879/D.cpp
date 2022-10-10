#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

#define int long long

int k;

long long push(std::vector<std::pair<int, int>> &ar, int x) {
	if(!ar.empty() && ar.back().first == x) {
		ar.back().second++;
	} else {
		ar.emplace_back(x, 1);
	}
	long long ans = ar.back().second / k;
	ar.back().second %= k;
	if(ar.back().second == 0) {
		ar.pop_back();
	}
	return ans;
}

long long push(std::vector<std::pair<int, int>> &ar, std::pair<int, int> x) {
	if(!ar.empty() && ar.back().first == x.first) {
		ar.back().second += x.second;
	} else {
		ar.emplace_back(x);
	}
	long long ans = ar.back().second / k;
	ar.back().second %= k;
	if(ar.back().second == 0) {
		ar.pop_back();
	}
	return ans;
}

struct Group {
	std::vector<std::pair<int, int>> left, right;
	long long groups;
	long long size;

	Group(std::vector<int> a) {
		size = (int) a.size();
		for(auto v : a) {
			size -= k * push(left, v);
		}
		right = left;
		std::reverse(right.begin(), right.end());
	}

	Group(Group &l, Group &r) {
		const int MAGIC = 3e5;
		// build left
		left = l.left;
		if(left.size() < MAGIC) {
			for(int i = 0; i < (int) r.left.size(); i++) {
				push(left, r.left[i]);
			}
		}
		// build right
		right = r.right;
		if(right.size() < MAGIC) {
			for(int i = 0; i < (int) l.right.size(); i++) {
				push(right, l.right[i]);
			}
		}
		while((int) left.size() > MAGIC) {
			left.pop_back();
		}
		while((int) right.size() > MAGIC) {
			right.pop_back();
		}
		// middle part
		size = l.size + r.size;
		{
			std::vector<std::pair<int, int>> vec;
			for(int i = 0; i < (int) l.right.size(); i++) {
				push(vec, l.right[(int)l.right.size()-i-1]);
			}
			for(auto x : r.left) {
				size -= k * push(vec, x);
			}
		}

		
	}
};

main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> k >> m;
	std::vector<int> base(n);
	for(int i = 0; i < n; i++) {
		std::cin >> base[i];
	}
	Group x(base);
	base.clear();
	Group ans(base);
	for(; m > 0; m /= 2) {
		if(m & 1) ans = Group(ans, x);
		x = Group(x, x);
	}
	std::cout << ans.size << std::endl;
}