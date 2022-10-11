#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<int> freq(26, 0);
	int n, k;
	std::cin >> n >> k;
	if(k == n) {
		std::cout << "\n";
		return 0;
	}
	std::string str;
	std::cin >> str;
	for(auto c : str) {
		freq[c - 'a']++;
	}
	char bound = 'a';
	while(freq[bound - 'a'] <= k) {
		k -= freq[bound - 'a'];
		bound++;
	}
	std::string ans;
	for(auto c : str) {
		if(c > bound) {
			ans += c;
		} else if(c == bound) {
			if(k) {
				k--;
			} else {
				ans += c;
			}
		}
	}
	std::cout << ans << std::endl;
}