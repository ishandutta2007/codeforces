#include<bits/stdc++.h>

bool check(char *s){
	int len = strlen(s);
	for (int i = 0; i < len >> 1; ++ i){
		if (s[i] != s[len - i - 1]){
			return false;
		}
	}
	return true;
}

char s[10];

int main(){
	scanf("%s", s);
	for (int i = 2; i <= 4; ++ i){
		s[i] = s[i + 1];
	}
	int ans = 0;
	while (!check(s)){
		++ ans;
		++ s[3];
		if (s[3] > '9'){
			s[3] = '0';
			++ s[2];
		}
		if (s[2] >= '6'){
			s[2] = '0';
			++ s[1];
		}
		if (s[1] > '9'){
			s[1] = '0';
			++ s[0];
		}
		if (s[0] == '2' && s[1] == '4'){
			s[0] = s[1] = '0';
		}
	}
	return printf("%d\n", ans), 0;
}