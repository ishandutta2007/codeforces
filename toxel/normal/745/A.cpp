#include<bits/stdc++.h>

const int N = 100;

char s[N];
std::set <std::string> set;

int main(){
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		char ch = s[0];
		for (int j = 0; j < len - 1; ++ j){
			s[j] = s[j + 1];
		}
		s[len - 1] = ch;
		set.insert(s);
	}
	return printf("%d\n", set.size()), 0;
}