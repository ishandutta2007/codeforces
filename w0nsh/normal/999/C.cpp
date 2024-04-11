#include <iostream>
#include <vector>
#include <string>

const int A = 50;
int n, k;
std::string str;
int char_count[A];

void answer(){
	for(int i = 0; i < n; ++i){
		char_count[str[i]-'a']++;
	}
	int have = k;
	for(int i = 0; i < A; ++i){
		int odejm = std::min(have, char_count[i]);
		char_count[i] -= odejm;
		have -= odejm;
	}
	std::vector<char> ret;
	for(int i = n-1; i >= 0; --i){
		if(char_count[str[i]-'a'] > 0){
			char_count[str[i]-'a']--;
			ret.push_back(str[i]);
		}
	}
	for(auto i = ret.rbegin(); i != ret.rend(); ++i){
		std::cout << *i;
	}
	std::cout << "\n";
}

void read(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> k >> str;
}

int main(){
	read();
	answer();
	return 0;
}