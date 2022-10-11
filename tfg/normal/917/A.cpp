#include <iostream>
#include <string>
#include <vector>

const int ms = 5050;

short int pref[ms][ms], suf[ms][ms], m1[ms][ms], m2[ms][ms];

int get_val(char x, int v) {
	if(x == '(') return 1;
	else if(x == ')') return -1;
	else return v;
}

int main() {
	std::string str;
	std::cin >> str;
	for(int i = 0; i < str.size(); i++) {
		for(int j = i; j < str.size(); j++) {
			pref[i][j + 1] = pref[i][j] + get_val(str[j], 1);
			m1[i][j + 1] = std::min(m1[i][j], pref[i][j + 1]);
		}
		for(int j = i; j < str.size(); j++){
			suf[i][j + 1] = suf[i][j] + get_val(str[j], -1);
			m2[i][j + 1] = std::min(m2[i][j], suf[i][j + 1]);
			//std::cout << "(" << i << ", " << j << ") = " << suf[i][j + 1] << ", " << m2[i][j + 1] << '\n';
		}
	}
	long long ans = 0;
	for(int i = 0; i < str.size(); i++) {
		std::vector<int> pos;
		for(int j = i; j < str.size(); j++) {
			if(pref[i][j + 1] < 0) {
				break;
			}
			if(str[j] == '?') {
				pos.push_back(j);
			}
			if((j - i + 1) % 2 == 1) {
				continue;
			}
			if(pref[i][j + 1] == 0) {
				//std::cout << "got full on (" << i << ", " << j << ")\n";
				ans++;
				continue;
			}
			//std::cout << "got here on (" << i << ", " << j << ")\n";
			int cur_sum = pref[i][j + 1] + (int)suf[i][j + 1];
			cur_sum /= 2;
			//std::cout << "sum is " << cur_sum << '\n';
			int x = ((int) pos.size() - cur_sum) / 2;
			// x - (freq - x) + cur_sum = 0
			// x = (freq - cur_sum) / 2
			if(x < 0 || x >= pos.size()) {
				//std::cout << "broke because x == " << x << "\n";
				continue;
			}
			//std::cout << "x is (" << x << ", " << pos[x] << "), got minimum on suffix " << m2[pos[x]][j + 1] << '\n';
			if(m2[pos[x]][j + 1] + pref[i][pos[x]] >= 0) {
				//std::cout << "got partial on (" << i << ", " << j << ")\n";
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}