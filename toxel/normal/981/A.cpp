#include<bits/stdc++.h>

const int N = 60;

char s[N];

bool palin(char *s, int len){
	for (int i = 0; i < len; ++ i){
		if (s[i] != s[len - i - 1]){
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%s", s);
	int len = strlen(s);
	for (int i = len; i >= 1; -- i){
		for (int j = 0; j + i - 1 < len; ++ j){
			if (!palin(s + j, i)){
				printf("%d\n", i);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}