#include <iostream>
#include <vector>
#include <stack>
#include <utility>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::string str;
	std::cin >> n >> k >> str;
	std::stack<int> s;
	std::vector<std::pair<int, int>> places;
	for(int i = 0; i < n; i++) {
		if(str[i] == '(') {
			s.push(i);
		} else {
			places.emplace_back(s.top(), i);
			s.pop();
		}
	}
	int erase = (n - k) / 2;
	std::vector<bool> valid(n, true);
	for(int i = 0; i < erase; i++) {
		valid[places[i].first] = false;
		valid[places[i].second] = false;
	}
	std::string ans;
	for(int i = 0; i < n; i++) {
		if(valid[i]) {
			ans += str[i];
		}
	}
	std::cout << ans << std::endl;
}