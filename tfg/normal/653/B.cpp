#include <iostream>
#include <vector>
#include <set>

int n;
std::set<std::string> ans;
std::set<std::string> visit;
std::set<std::string> to[256];

void bf(std::string str) {
	if(visit.count(str)) return;
	//std::cout << "on " << str << std::endl;
	visit.insert(str);
	if(str.size() == n) {
		ans.insert(str);
		return;
	}
	char c = str.back();
	str.pop_back();
	for(auto hmm : to[c]) {
		bf(str + hmm);
	}
}

int main() {
	int q;
	std::cin >> n >> q;
	while(q--) {
		std::string s1, s2;
		std::cin >> s1 >> s2;
		std::swap(s1[0], s1[1]);
		to[s2[0]].insert(s1);
	}
	for(char i = 'a'; i <= 'a'; i++) {
		std::string str;
		str += i;
		bf(str);
	}
	std::cout << ans.size() << std::endl;;
}