#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1550;

int freq[ms];
bool marked[ms];

bool qry(int a, int b, int c) {
	std::cout << "? " << a << " " << b << " " << c << std::endl;
	//return a + c == 4;
	std::string ans;
	std::cin >> ans;
	return ans == "Yes";
}

int last = -1;

int n, k;
std::vector<std::vector<int>> findPartition(int x) {
	std::vector<std::vector<int>> ans;
	for(int i = 1; i <= n; i++) {
		if(i == x || marked[i]) continue;
		int j = 0;
		while(j < (int) ans.size()) {
			if(!qry(i, x, ans[j][0])) {
				break;
			} else {
				j++;
			}
		}
		if(j == (int) ans.size()) {
			ans.push_back(std::vector<int>(0));
		}
		ans[j].push_back(i);
	}
	if(last != -1) {
		ans.push_back(std::vector<int>(1, last));
	}
	last = x;
	return ans;
}

int getNext(int x, std::vector<int> v) {
	int ans = v[0];
	for(int i = 1; i < (int) v.size(); i++) {
		if(qry(x, v[i], ans)) {
			ans = v[i];
		}
	}
	return ans;
}
int main() {
	//std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> k;
	int h = 1;
	int cur = 1;
	while(cur != n) {
		cur = cur * k + 1;
		h++;
	}
	if(k >= 15) {
		for(int i = 0; i * (n - 2) + n - 2 <= 60 * n; i++) {
			int l = 1, r = 1;
			while(l == r) {
				l = std::uniform_int_distribution<int>(1, n)(rng);
				r = std::uniform_int_distribution<int>(1, n)(rng);
			}
			for(int j = 1; j <= n; j++) {
				if(j != l && j != r && qry(l, j, r)) {
					freq[j]++;
				}
			}
		}
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			if(freq[i] > freq[ans]) {
				ans = i;
			}
		}
		std::cout << "! " << ans << std::endl;
		return 0;
	}
	auto partitions = findPartition(std::uniform_int_distribution<int>(1, n)(rng));
	while((int) partitions.size() != k) {
		int heavy = 0;
		for(int i = 1; i < (int) partitions.size(); i++) {
			if(partitions[i].size() > partitions[heavy].size()) {
				heavy = i;
			}
		}
		for(int i = 0; i < (int) partitions.size(); i++) {
			if(i != heavy) {
				for(auto v : partitions[i]) {
					marked[v] = true;
				}
			}
		}
		marked[last] = true;
		partitions = findPartition(getNext(last, partitions[heavy]));
	}
	std::cout << "! " << last << std::endl;
}