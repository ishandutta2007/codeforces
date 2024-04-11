#include <iostream>
#include <string>

const int ms = 200200;
const int eps = 'z' - 'a' + 1;

void print(int x) {
	for(int i = 0; i < eps; i++) {
		std::cout << ((x & (1 << i)) ? 1 : 0);
	}
	std::cout << '\n';
}

char t[200200];
std::string str[200200];

int main() {
	int n;
	std::cin >> n;
	int isnt = 0;
	int know = (1 << eps) - 1;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> t[i] >> str[i];
	}
	for(int i = 0; i < n; i++) {
		int tot = (~isnt & know);
		//std::cout << isnt << ", " << know << '\n';
		//print(tot);
		bool hmm = tot - (tot & -tot) == 0;
		int mask = 0;
		for(auto a : str[i]) {
			//std::cout << a;
			mask |= 1 << (a - 'a');
		}
		//std::cout << '\n';
		//print(mask);
		if(t[i] == '!') {
			if(hmm) {
				ans++;
			}
			know &= mask;
		} else if(t[i] == '.') {
			isnt |= mask;
		} else {
			//std::cout << "guessed " << str[0] << '\n';
			//std::cout << tot << ", " << (1 << (str[0] - 'a')) << '\n';
			if(hmm && (1 << (str[i][0] - 'a')) != tot) {
				ans++;
				//std::cout << "got\n";
			}
			if(!hmm && str[i][0] != str[n - 1][0]) {
				isnt |= 1 << (str[i][0] - 'a');
			}
		}
	}
	std::cout << ans << '\n';
}