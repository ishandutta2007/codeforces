#include <iostream>
#include <string>

const int ms = 100100;

int size[ms], ans[ms];

int main() {
	std::string str;
	std::cin >> str;
	str += '#';
	int pos = -1;
	int cur_ans = 0;
	for(int i = (int)str.size() - 2; i >= 0; i--) {
		if(str[i] == ')' || str[i] == ']' || i + 1 == str.size()) {
			size[i] = 0;
		} else if((str[i] == '[' && str[i + size[i + 1] + 1] == ']')) {
			size[i] = 2 + size[i + 1] + size[2 + size[i + 1] + i];
			ans[i] = 1 + ans[i + 1] + ans[2 + size[i + 1] + i];
		} else if((str[i] == '(' && str[i + size[i + 1] + 1] == ')')) {
			size[i] = 2 + size[i + 1] + size[2 + size[i + 1] + i];
			ans[i] = ans[i + 1] + ans[2 + size[i + 1] + i];
		}
		if(ans[i] > cur_ans) {
			cur_ans = ans[i];
			pos = i;
		}
	}
	if(cur_ans == 0) {
		std::cout << "0\n\n";
	} else {
		std::cout << cur_ans << '\n' << str.substr(pos, size[pos]) << '\n';
	}
}