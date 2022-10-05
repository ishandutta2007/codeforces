#include<bits/stdc++.h>

const int N = 10010;

bool dp[2][N];
char s[N];
std::set <std::string> set;

int main(){
	scanf("%s", s);
	int len = strlen(s);
	std::reverse(s, s + len);
	dp[0][1] = dp[1][2] = true;
	for (int i = 3; i < len - 5; ++ i){
		dp[0][i] = dp[1][i - 2] || dp[0][i - 2] && (s[i] != s[i - 2] || s[i - 1] != s[i - 3]);
		dp[1][i] = dp[0][i - 3] || dp[1][i - 3] && (s[i] != s[i - 3] || s[i - 1] != s[i - 4] || s[i - 2] != s[i - 5]);
	}
	for (int i = 1; i < len - 5; ++ i){
		if (dp[0][i]){
			std::string str;
			str += s[i];
			str += s[i - 1];
			set.insert(str);
		}
		if (dp[1][i]){
			std::string str;
			str += s[i];
			str += s[i - 1];
			str += s[i - 2];
			set.insert(str);
		}
	}
	printf("%d\n", (int) set.size());
	for (auto u : set){
		std::cout << u << std::endl;	
	}
	return 0;
}