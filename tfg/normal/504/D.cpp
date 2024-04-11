#include <iostream>
#include <string>
#include <bitset>
#include <utility>
#include <vector>

const int e = 20;
const int d = 1 << e;
const int mb = 2200;

std::pair<int, std::string> long_div(std::string &str) {
	std::pair<int, std::string> ans(0, "");
	bool got = false;
	for(int i = 0; i < str.size(); i++) {
		int nxt = ans.first * 10 + str[i] - '0';
		if(got) {
			ans.second += '0';
		} else {
			if(nxt >= d) {
				ans.second += '0';
				got = true;
			}
		}
		if(got) {
			ans.second.back() += nxt / d;
		}
		ans.first = nxt % d;
	}
	//std::cout << "making division " << str << " / " << d << " got remainder " << ans.first << " and quotient " << ans.second << "\n";
	return ans;
}

std::bitset<mb> read_int() {
	std::string str;
	std::cin >> str;
	int step = 0;
	std::bitset<mb> ans;
	while(str.size() > 0) {
		auto p = long_div(str);
		str = p.second;
		for(int i = 0; i < e; i++) {
			ans[i + step * e] = (p.first & 1) != 0;
			p.first >>= 1;
		}
		step++;
	}
	return ans;
}

std::bitset<mb> gauss[mb], elem[mb];
int ori[mb];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		auto bits = read_int();
		std::bitset<mb> cur_ele; 
		for(int j = mb - 1; j >= 0; j--) {
			if(bits[j] && gauss[j][j]) {
				bits ^= gauss[j];
				cur_ele ^= elem[j];
			}
		}
		int last_bit = mb - 1;
		while(last_bit >= 0 && !bits[last_bit]) last_bit--;
		if(last_bit != -1) {
			std::cout << "0\n";
			gauss[last_bit] = bits;
			cur_ele[last_bit] = true;
			elem[last_bit] = cur_ele;
			ori[last_bit] = i;
			continue;
		}
		std::vector<int> ans;
		for(int j = 0; j < mb; j++) {
			if(cur_ele[j]) ans.push_back(ori[j]);
		}
		std::cout << ans.size();
		for(auto a : ans) {
			std::cout << ' ' << a;
		}
		std::cout << '\n';
	}
}