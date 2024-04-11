#include <iostream>
#include <vector>

bool getNext(std::string &str, char lim) {
	int n = str.size();
	for(int i = n-1; i >= 0; i--) {
		if(str[i] < lim) {
			str[i]++;
			return true;
		} else {
			str[i] = 'a';
		}
	}
	return false;
}

bool check(const std::string &str) {
	int n = str.size();
	for(int i = 0; i < n; i++) {
		if(i > 0 && i + 1 < n) {
			if(str[i-1] == str[i+1]) {
				return false;
			}
		}
		if(i > 0) {
			if(str[i] == str[i-1]) {
				return false;
			}
		}
	}
	return true;
}


const int ms = 1010;

bool dp[ms][26][26];

void calc(int n, int p) {

}

std::string gen(std::string str, int n, int p) {
	int ans[] = {-1, -1};
	for(int i = 0; i < n; i++) {
		for(char j = str[i] + 1; j < 'a' + p; j++) {
			if((i && j == str[i-1]) || (i > 1 && j == str[i-2])) {
				continue;
			} else {
				ans[0] = i;
				ans[1] = j;
				break;
			}
		}
	}
	if(ans[0] == -1) return "NO";
	str[ans[0]] = ans[1];
	for(int i = ans[0] + 1; i < n; i++) {
		str[i] = 'L';
		for(char j = 'a'; j < 'a' + p; j++) {
			if((i && j == str[i-1]) || (i > 1 && j == str[i-2])) {
				continue;
			} else {
				//std::cout << "choosing " << j << " for " << i << std::endl;
				str[i] = j;
				break;
			}
		}
		if(str[i] == 'L') {
			return "NO";
		}
	}
	if(!check(str)) {
		str = "NO";
	}
	return str;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, p;
	std::string str;
	std::cin >> n >> p >> str;
	//if(0) {
	if(n <= 5 || p == 1) {
		while(getNext(str, 'a' + p - 1)) {
			if(check(str)) {
				std::cout << str << std::endl;
				return 0;
			}
		}
		std::cout << "NO\n";
	} else {
		calc(n, p);
		str = gen(str, n, p);
		std::cout << str << std::endl;
	}
}