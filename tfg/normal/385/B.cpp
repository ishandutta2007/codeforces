#include <iostream>

const int ms = 100100;

int got[ms];

int main() {
	std::string str;
	std::cin >> str;
	int n = str.size();
	int last = -1;
	int ans = 0;
	for(int i = 0; i + 4 <= str.size(); i++) {
		if(str.substr(i, 4) == "bear") {
			//std::cout << "got on " << i << ", last is " << last << "\n";
			ans += (n - i - 3) * (i - last);
			last = i;
		}
	}
	std::cout << ans << '\n';
}