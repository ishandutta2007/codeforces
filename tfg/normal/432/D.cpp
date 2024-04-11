#include <iostream>
#include <vector>
#include <algorithm>

struct ZFunc {
	std::vector<int> z;
	ZFunc(const std::string v) : z(v.size()) {
		int n = v.size(), a = 0, b = 0;
		if(!z.empty()) z[0] = n;
		for(int i = 1; i < n; i++) {
			int end = i;
			if(i < b) end = std::min(i + z[i - a], b);
			while(end < n && v[end] == v[end - i]) ++end;
			z[i] = end - i;
			if(end > b) {
				a = i;
				b = end;
			}
		}
	}
};

const int ms = 100100;

int freq[ms];

int main() {
	std::string str;
	std::cin >> str;
	int n = str.size();
	ZFunc z(str + '#' + str);
	for(int i = 1; i <= n; i++) {
		//std::cout << "on " << i << ", got " << z.z[i + n] << "\n";
		freq[z.z[i + n]]++;
	}
	for(int i = n; i > 0; i--) {
		freq[i] += freq[i + 1];
	}
	std::vector<int> ans;
	for(int i = 1; i <= n; i++) {
		//std::cout << "trying to get on pos " << n + 1 + n - i << "\n";
		if(z.z[n + 1 + n - i] == i) {
			//std::cout << "pushing " << i << "\n";
			ans.push_back(i);
		}
	}
	std::cout << ans.size() << "\n";
	for(auto l : ans) {
		printf("%d %d\n", l, freq[l]);
	}
}