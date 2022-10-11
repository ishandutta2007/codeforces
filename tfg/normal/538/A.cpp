#include <iostream>
#include <string>

int main() {
	const std::string pat = "CODEFORCES";
	std::string txt;
	std::cin >> txt;
	int l = 0, r = 0;
	if(txt.size() < pat.size()) {
		std::cout << "NO\n";
		return 0;
	}
	while(l < pat.size() && pat[l] == txt[l]) {
		l++;
	}
	while(r < pat.size() && pat[pat.size() - r - 1] == txt[txt.size() - r - 1]) {
		r++;
	}
	//std::cout << l << ", " << r << "\n";
	if(l + r >= pat.size()) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}