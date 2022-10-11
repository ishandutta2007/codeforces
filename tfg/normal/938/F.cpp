#include <iostream>
#include <string>

const int ms = 5001;
const int me = 12;

std::string str;
int bits = 0;

int op[1 << me];
bool del[1 << me];

int main() {
	for(int i = 0; i < (1 << me); i++) {
		op[i] = op[i / 2] * 2 + (i & 1);
	}
	std::cin >> str;
	int n = str.size();
	while(n - (1 << bits) > 0) {
		n -= 1 << bits;
		bits++;
	}
	std::string ans;
	n = str.size();
	for(int i = 0; i < n - op[(1 << bits) - 1]; i++) {
		char c = 'z' + 1;
		for(int j = 0; j < (1 << bits); j++) {
			if(!del[j]) {
				//std::cout << "on pos " << (i + op[j]) << " got " << str[i + op[j]] << "\n";
				c = std::min(c, str[i + op[j]]);
			}
		}
		//std::cout << "got char " << c << '\n';
		for(int j = 0; j < (1 << bits); j++) {
			if(!del[j] && c < str[i + op[j]]) {
				del[j] = true;
			}
			for(int k = 0; k < bits; k++) {
				del[j] = del[j] && del[j & ~(1 << k)];
			}
		}
		ans += c;
	}
	std::cout << ans << '\n';
}