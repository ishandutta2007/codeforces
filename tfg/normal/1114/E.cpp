#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9;

int arr[4] = {14, 24, 9, 19};

int used = 0;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool hasGreater(int x) {
	assert(used < 60);
	used++;
	std::cout << "> " << x << std::endl;
	if(0) {
		for(int i = 0; i < 4; i++) {
			if(arr[i] > x) return true;
		}
		return false;
	}
	std::cin >> x;
	return x == 1;
}

int getValue(int i) {
	assert(used < 60);
	used++;
	std::cout << "? " << i << std::endl;
	if(0) {
		return arr[i-1];
	}
	std::cin >> i;
	return i;
}

int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> p;
	for(int i = 1; i <= n; i++) {
		p.push_back(i);
	}
	std::shuffle(p.begin(), p.end(), rng);
	std::vector<int> values;
	{
		int l = 0, r = INF;
		while(l != r) {
			int mid = (l + r) / 2;
			if(hasGreater(mid)) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		values.push_back(l);
	}
	for(auto i : p) {
		if(used >= 60) break;
		values.push_back(getValue(i));
	}
	std::sort(values.begin(), values.end());
	values.resize(std::unique(values.begin(), values.end()) - values.begin());
	int g = 0;
	for(int i = 0; i < (int) values.size(); i++) {
		for(int j = i + 1; j < (int) values.size(); j++) {
			g = gcd(g, values[j] - values[i]);
		}
	}
	assert(values.back() - (n - 1) * g >= 0);
	std::cout << "! " << values.back() - (n - 1) * g << " " << g << std::endl;
}