#include <iostream>
#include <algorithm>

const int eps = 'z' - 'a' + 1;

int freq[eps];

bool can(int x, int n) {
	int got = 0;
	for(int i = 0; i < eps; i++) {
		int need = (freq[i] + x - 1) / x;
		got += need;
	}
	return got <= n;
}

int main() {
	std::string str;
	int n;
	std::cin >> str >> n;
	for(auto a : str) {
		freq[a - 'a']++;
	}
	if(!can(str.size(), n)) {
		std::cout << "-1\n";
		return 0;
	}
	int l = 1, r = str.size();
	//std::sort(freq, freq + eps);
	while(l != r) {
		int mid = (l + r) / 2;
		if(can(mid, n)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
	for(int i = 0; i < eps; i++) {
		int need = (freq[i] + l - 1) / l;
		while(need--) {
			n--;
			std::cout << char('a' + i);
		}
	}
	while(n--) {
		std::cout << 'a';
	}
	std::cout << '\n';
}