#include<bits/stdc++.h>

const int N = 100000;

char s[N];
std::string ans[N];
std::map <std::string, int> Hash;

int main(){
	for (int i = 1989; i < N; ++ i){
		sprintf(s, "%d", i);
		int len = strlen(s);
		for (int j = len - 1; j >= 0; -- j){
			std::string string = s + j;
			if (!Hash.count(string)){
				ans[i] = string;
				Hash[ans[i]] = i;
				break;
			}
		}
	}
	int test;
	scanf("%d", &test);
	while (test --){
		scanf("%s", s);
		int len = strlen(s);
		std::string string = s + 4;
		if (Hash.count(string)){
			printf("%d\n", Hash[string]);
			continue;
		}
		bool flag = false;
		long long ans = 0;
		for (int i = 4; i < len - 4; ++ i){
			ans = ans * 10 + 1;
		}
		ans = ans * 10000 + 3099;
		//std::cout << ans << std::endl;
		if (atoi(s + 4) < ans){
			putchar('1');
		}
		std::cout << string << std::endl;
	}
	return 0;
}