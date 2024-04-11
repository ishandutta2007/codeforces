#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool cmp(const std::string &a, const std::string &b) {
	if(a.size() != b.size()) return a.size() > b.size();
	else return a > b;
}

std::string getMax(int d, int sum) {
	std::string ans;
	for(int i = 0; i < d; i++) {
		int use = std::min(sum, 9);
		ans += char(use + '0');
		sum -= use;
	}
	if(sum > 0) {
		return "";
	}
	return ans;
}

std::string getMin(std::string ans, int sum) {
	for(auto c : ans) {
		sum -= c - '0';
	}
	if(sum <= 0) {
		int pos = (int) ans.size() - 1;
		//std::cout << "got to second case\n";
		while(pos >= 0) {
			if(ans[pos] == '9') {
				sum += 9;
				ans[pos] = '0';
				pos--;
				continue;
			}
			if(sum - 1 >= 0) {
				ans[pos]++;
				sum--;
				break;
			}
			sum += ans[pos] - '0';
			ans[pos] = '0';
			pos--;
		}
	}
	for(int i = (int) ans.size() - 1; i >= 0; i--) {
		int use = std::min(sum, '9' - ans[i]);
		ans[i] += use;
		sum -= use;
	}

	if(ans[0] == '0') {
		ans[0] = '1';
		for(int i = 1; i < (int) ans.size(); i++) {
			if(ans[i] > '0') {
				ans[i]--;
				break;
			}
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string cur = "0";
	int d = 1;
	while(n--) {
		int sum;
		std::cin >> sum;
		while(!cmp(getMax(d, sum), cur)) {
			d++;
		}
		if(d > (int) cur.size()) {
			cur = std::string(d, '0');
		}
		cur = getMin(cur, sum);
		std::cout << cur << '\n';
	}
}