#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string apply(std::string str, int pos) {
	std::string ans;
	for(int i = pos; i < str.size(); i++) {
		ans += str[i];
		//std::cout << str[i];
	}
	//std::cout << "|";
	for(int i = pos - 1; i >= 0; i--) {
		ans += str[i];
		//std::cout << str[i];
	}
	//std::cout << '\n';
	return ans;
}

std::string app(std::string str, int pos) {
	std::string ans;
	pos = str.size() - pos;
	for(int i = str.size() - 1; i >= pos; i--) {
		ans += str[i];
	}
	for(int i = 0; i < pos; i++) {
		ans += str[i];
	}
	return ans;
}

std::vector<int> solve(std::string str, std::string base) {
	std::vector<int> ans;
	int n = str.size();
	//std::cout << "target is " << str << "\n";
	//std::cout << base << '\n';
	int l = n / 2 - 1;
	int r = n / 2;
	if(n % 4 == 2) {
		r--;
		l--;
	}
	for(int i = 0; i < n; i++) {
		int pos;
		int j = 0;
		if(i % 2 == 0) {
			j = i;
		} else {
			j = 0;
		}
		if(i / 2 % 2 == 0) {
			pos = r++;
		} else {
			pos = l--;
		}
		while(base[j] != str[pos]) {
			j++;
		}
		//std::cout << "found " << str[pos] << " on pos " << j << "\n";
		if(i % 2 == 1) {
			ans.push_back(j + 1);
			ans.push_back(n - j - i - 1);
			base = apply(base, j + 1);
			//std::cout << base << '\n';
			base = apply(base, n - j - i - 1);
			//std::cout << base << '\n';
		} else {
			ans.push_back(j);
			ans.push_back(1);
			base = apply(base, j);
			//std::cout << base << '\n';
			base = apply(base, 1);
			//std::cout << base << '\n';
		}
	}
	if(base != str) {
		ans.push_back(n);
		base = apply(base, n);
		//std::cout << base << '\n';
	}
	return ans;
}

int freq[256];

int main() {
	int n;
	std::cin >> n;
	std::string str[2];
	std::cin >> str[0] >> str[1];
	for(auto a : str[0]) {
		freq[a]++;
	}
	for(auto b : str[1]) {
		freq[b]--;
	}
	bool valid = true;
	for(int i = 0; i < 256; i++) {
		valid = valid && freq[i] == 0;
	}
	if(!valid) {
		std::cout << "-1\n";
		return 0;
	} else {
		auto v = solve(str[0], str[1]);
		std::cout << v.size() << '\n';
		std::reverse(v.begin(), v.end());
		//std::cout << str[0] << '\n';
		for(int i = 0; i < v.size(); i++) {
			std::cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
			//str[0] = app(str[0], v[i]);
			//std::cout << str[0] << '\n';
		}
	}
}