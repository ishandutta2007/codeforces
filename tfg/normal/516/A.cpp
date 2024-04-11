#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	std::string ans;
	std::vector<int> freq(10, 0);
	for(auto v : str) {
		if(v > '1') {
			freq[v - '0']++;
		}
	}
	while(freq[9]) {
		freq[9]--;
		freq[2]++;
		freq[3] += 2;
		freq[7]++;
	}
	while(freq[8]) {
		freq[8]--;
		freq[2] += 3;
		freq[7]++;
	}
	while(freq[6]) {
		freq[6]--;
		freq[5]++;
		freq[3]++;
	}
	while(freq[4]) {
		freq[4]--;
		freq[3]++;
		freq[2] += 2;
	}
	for(int i = 9; i > 0; i--) {
		while(freq[i]--) {
			ans += i + '0';
		}
	}
	if(ans.size() == 0) ans = "1";
	std::cout << ans << std::endl;
}