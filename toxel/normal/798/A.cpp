#include<bits/stdc++.h>

const int N = 20;

char s[N], str[N];

int main(){
	scanf("%s", &s);
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		for (int j = 0; j < 26; ++ j){
			memcpy(str, s, sizeof(s));
			if (str[i] == j + 'a'){
				continue;
			}
			str[i] = j + 'a';
			bool flag = true;
			for (int k = 0; k < len; ++ k){
				if (str[k] != str[len - 1 - k]){
					flag = false;
					break;
				}
			}
			if (flag){
				return printf("YES\n"), 0;
			}
		}
	}
	return printf("NO\n"), 0;
}