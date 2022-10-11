#include <iostream>
#include <string>
#include <iomanip>

const int ms = 5050;
const int eps = 'z' - 'a' + 1;

int freq[eps];
int uniques[eps][ms][eps];

int main() {
	std::string str;
	std::cin >> str;
	long double ans = 0;
	int n = str.size();
	str += str;
	for(int i = 0; i < n; i++) {
		int cur = str[i] - 'a';
		freq[cur]++;
		for(int j = 0; j < n; j++) {
			uniques[cur][j][str[i + j] - 'a']++;
		}
	}
	for(int i = 0; i < eps; i++) {
		if(freq[i] == 0) {
			continue;
		}
		int top = 0;
		for(int j = 1; j < n; j++) {
			int cur = 0;
			for(int k = 0; k < eps; k++) {
				cur += (uniques[i][j][k] == 1 ? 1 : 0);
			}
			top = std::max(top, cur);
		}
		//std::cout << "for " << char(i + 'a') << " got " << top << "\n";
		ans += top;
	}
	std::cout << std::fixed << std::setprecision(20);
	std::cout << ans / n << '\n';
}