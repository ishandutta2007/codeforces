#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cstdlib>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef unsigned int ui;

const int ms = 200200;
const int me = 33;

int c = 1;
int trie[ms * me][2];
int has[ms * me];

int addTrie(ui num, int x) {
	int st = 0;
	for(int i = 31; x > 0; i--, x--) {
		ui bit = (num >> i) & 1;
		//std::cout << bit;
		if(!trie[st][bit]) {
			trie[st][bit] = c++;
		}
		st = trie[st][bit];
	}
	//std::cout << '\n';
	return st;
}

ui toInt(std::string str) {
	std::vector<ui> wtf;
	//std::cout << "received " << str << "\n";
	ui x = 0;
	for(int i = 0; i < (int) str.size(); i++) {
		if(str[i] == '.') {
			wtf.push_back(x);
			x = 0;
		} else {
			x = x * 10 + str[i] - '0';
		}
	}
	wtf.push_back(x);
	//for(auto v : wtf) std::cout << v << ' '; std::cout << std::endl;
	x = 0;
	std::reverse(wtf.begin(), wtf.end());
	while(wtf.size() > 0) {
		x = (x << 8) | wtf.back();
		wtf.pop_back();
	}
	return x;
}

std::vector<std::vector<int>> ans;

int check(int on = 0) {
	int down = 0;
	for(int i = 0; i < 2; i++) {
		if(trie[on][i]) {
			down |= check(trie[on][i]);
		}
	}
	if(has[on] == 3) {
		std::cout << "-1\n";
		exit(0);
	} else if(has[on] == 2 && (down & 1) == 1) {
		std::cout << "-1\n";
		exit(0);
	} else if(has[on] == 1 && (down & 2) == 2) {
		std::cout << "-1\n";
		exit(0);
	}
	has[on] |= down;
	return has[on];
}

void build(int on = 0, int x = 31, ui val = 0) {
	if(has[on] == 3) {
		for(int i = 0; i < 2; i++) {
			if(trie[on][i]) {
				build(trie[on][i], x - 1, val | ((ui) i << x));
			}
		}
	} else if(has[on] == 1) {
		std::vector<int> v;
		for(int i = 0; i < 4; i++) {
			v.push_back(val & 255);
			val >>= 8;
		}
		std::reverse(v.begin(), v.end());
		v.push_back(31 - x);
		ans.push_back(v);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	while(n--) {
		std::string str;
		std::cin >> str;
		char op = str[0];
		std::string mask = str.substr(1, (int) str.size() - 1);
		std::string xstr = "32";
		for(int i = 0; i < (int) str.size(); i++) {
			if(str[i] == '/') {
				xstr = str.substr(i + 1, (int) str.size() - (i + 1));
				mask = str.substr(1, i - 1);
			}
		}
		//std::cout << "mask is " << mask << " op is " << op << " x is " << xstr << "\n";
		int x = 0;
		for(auto cc : xstr) {
			x = x * 10 + cc - '0';
		}
		int st = addTrie(toInt(mask), x);
		if(op == '-') {
			has[st] |= 1;
		} else {
			has[st] |= 2;
		}
	}
	check();
	build();
	std::cout << ans.size() << '\n';
	for(auto v : ans) {
		std::cout << v[0] << '.' << v[1] << '.' << v[2] << '.' << v[3] << '/' << v[4] << "\n";
	}
}